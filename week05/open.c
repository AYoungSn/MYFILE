#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd, fd1, fd2;
	char pathname[]="temp.txt";
	char pathname1[]="temp1.txt";
	char pathname2[]="temp2.txt";
	char buf[1024];

	if((fd=open(pathname, O_RDONLY))==-1){
		perror(pathname);
		exit(-1);
	}
	if((fd1=open(pathname1, O_WRONLY | O_CREAT, 0644))==-1){
		perror(pathname1);
		exit(-1);
	}
	if((fd2=open(pathname2, O_WRONLY|O_CREAT|O_TRUNC, 0644))==-1){
		perror(pathname2);
		exit(-1);
	}
	ssize_t nread;
	if((nread=read(fd, buf,1024))>0){
		if(write(fd1, buf, nread)<nread){
			perror(pathname1);
		}
	}
	lseek(fd,0,SEEK_SET);
	
	if((nread=read(fd, buf,1024))>0){
		if(write(fd2, buf, nread)<nread){
			perror(pathname2);
		}
	}
	close(fd);
	close(fd1);
	close(fd2);
	
	return 0;
}

