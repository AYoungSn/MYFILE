#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#define BUFSIZE 1024
#define READONLY_MODE 0
#define WRITEONLY_MODE 1

typedef struct{
	int fd;
	char mode;
	char buf[BUFSIZE];
	int length;
	int offset;
}MYFILE;

MYFILE * myfopen(char* file,char* mode);
int myfclose(MYFILE* fp);
char myfgetc(MYFILE* fp);
void myfputc(char c, MYFILE* fp);

MYFILE * myfopen(char* file, char *mode){
	MYFILE* fp=(MYFILE*)malloc(sizeof(MYFILE));
	
	if(fp!=NULL){
		if(strcmp(mode, "r")==0){
			if((fp->fd=open(file, O_RDONLY))<0){
				free(fp);
				return NULL;
			}
			fp->mode=READONLY_MODE;
		}
		else{
			if((fp->fd=open(file, O_WRONLY|O_CREAT|O_TRUNC,0644))<0){
				free(fp);
				return NULL;
			}
			fp->mode=WRITEONLY_MODE;
		}
		fp->length=fp->offset=0;
	}
	return fp;
}
int myfclose(MYFILE* fp){
	if(fp==NULL) return EOF;

	if(fp->mode==WRITEONLY_MODE){
		if(write(fp->fd, fp->buf, fp->length)<fp->length)
			printf("error");
	}
	if(close(fp->fd)<0){
		free(fp);
		return EOF;
	}
	free(fp);
	return 0;
}
char myfgetc(MYFILE* fp){
	if(fp==NULL) return EOF;
	if(fp->mode==WRITEONLY_MODE) return EOF;	
	if(fp->offset==fp->length){
		if((fp->length=read(fp->fd, fp->buf, BUFSIZE))<1)
			return EOF;
		fp->offset=0;
	}
	return fp->buf[fp->offset++];
}
void myfputc(char c, MYFILE* fp){
	fp->buf[fp->offset++]=c;
	fp->length++;

	if(fp->length==BUFSIZE){
		write(fp->fd, fp->buf, fp->length);
		fp->offset=fp->length=0;
	}
}

/* fputc 가 실제 반환값이 int인데 주어진 myfputc의 헤더는 반환 타입이 void여서 int 버전 첨부*/
/*
int myfputc(char c, MYFILE* fp){
	if(fp==NULL) return EOF;
	if(fp->mode==READONLY_MODE) return EOF;

	fp->buf[fp->offset++]=c;
	fp->length++;

	if(fp->length==BUFSIZE){
		if(write(fp->fd, fp->buf, fp->length)<0)
			return EOF;
		fp->offset=fp->length=0;
	}
	
	return c;
}
*/
int main(){
	char c;
	MYFILE *fpin, *fpout;

	if((fpin=myfopen("a","r"))==NULL){
		perror("a");
		exit(-1);
	}
	if((fpout=myfopen("b","w"))==NULL){
		perror("b");
		exit(-1);
	}
	while((c=myfgetc(fpin))!=EOF){
		myfputc(c,fpout);
	}
	myfclose(fpin);
	myfclose(fpout);
	return 0;
}
