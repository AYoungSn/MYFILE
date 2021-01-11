#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define SIZE 512

int main(){
	char *msg[]={"apple is red", "banana is yellow", "cherry is red"};
	char buffer[SIZE];
	int fd[2], nread, pid, i;

	pipe(fd);
	if((pid=fork())>0){
		for(i=0;i<3;i++){
		strcpy(buffer,msg[i]);
		write(fd[1],buffer, SIZE);
		}
		nread=read(fd[0],buffer,SIZE);
		printf("[parent] %s\n", buffer);

		write(fd[1],buffer, SIZE);
		printf("[parent] bye!\n");
	}
	else{
		//child
		for(i=0;i<3;i++){
			nread=read(fd[0],buffer,SIZE);
			printf("[child] %s\n",buffer);
		}
		printf("[child] bye!\n");
	}
}
