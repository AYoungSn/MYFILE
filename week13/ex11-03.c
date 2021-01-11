#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SIZE 512

int main(){
	char msg[SIZE];
	int fd[2];
	pid_t pid;

	pipe(fd);
	if((pid=fork())>0){
		close(fd[0]);//추가
		strcpy(msg,"apple is red\n");
		write(fd[1],msg, SIZE);
		printf("[parent] %s\n",msg);
	}
	else{
		close(fd[1]);//추가
		sleep(1);
		read(fd[0],msg,SIZE);
		printf("[child] %s\n",msg);
	}
}
