#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	if(argc!=3){
		fprintf(stderr, "usage: %s file1 file2\n", argv[0]);
		exit(-1);
	}

	int fd1, fd2;
	fd1=open(argv[1],O_RDONLY);
	if((fd2=open(argv[2],O_WRONLY|O_CREAT|O_EXCL,0644))<0){
		fprintf(stderr,"file %s exist\n",argv[2]);
		exit(-1);
	}
	char buffer[1024];
	int nread;
	while((nread=read(fd1,buffer, 1024))>0){
		write(fd2, buffer, nread);
	}
	close(fd1);
	close(fd2);
}
