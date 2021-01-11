#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr, "usage: mycp file1 file2\n");
		exit(-1);
	}
	int fd1, fd2;
	fd1=open(argv[1],O_RDONLY);
	if((fd2=open(argv[2], O_WRONLY|O_CREAT|O_EXCL,0644))<0){
		fprintf(stderr, "파일 %s가 이미 존재합니다.\n",argv[2]);
		exit(-1);
	}
	char buffer[1024];
	int nread;
	while((nread=read(fd1, buffer, 1024))>0){
		write(fd2, buffer, nread);
	}
	close(fd1);
	close(fd2);
	return 0;
}
