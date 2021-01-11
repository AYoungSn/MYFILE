#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "mystdio.h"

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
		if(write(fp->fd, fp->buf, fp->length)<0)
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
