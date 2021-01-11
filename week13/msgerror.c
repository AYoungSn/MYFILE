#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define SIZE 512

int main(){
	char* msg1 = "apple is red";
	char *msg2 = "banana is yellow";
	int fd[2];
	pid_t pid;
	pipe(fd);

	if((pid=fork())>0){
		close(fd[0]);
		write(fd[1],msg1, strlen(msg1)+1);
		write(fd[1], msg2, strlen(msg2)+1);
	}
	else{
		char buffer[SIZE];
		int nread;

		close(fd[1]);
		nread=read(fd[0],buffer,SIZE);
		printf("%d, %s\n", nread, buffer);

		nread=read(fd[0],buffer,SIZE);
		printf("%d, %s\n",nread,buffer);
	}
}
