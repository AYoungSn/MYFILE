#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(){
	int fd;
	if((fd=open("data.txt",O_RDONLY))<0){
		perror("data.txt");
		fd=open("fail.txt",O_WRONLY|O_CREAT,0644);
		char buf[]="fail";
		write(fd, buf, strlen(buf));
		close(fd);
		exit(-1);
	}
	printf("성공\n");
	close(fd);
	fd=open("success.txt",O_WRONLY|O_CREAT,0644);
	char buf[]="success";
	write(fd, buf, strlen(buf));
	close(fd);
	return 0;
}
