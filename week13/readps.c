#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#define SIZE 512
void f(int signo){
	fprintf(stderr, "SIGPIPE is received\n");
	exit(-1);
}

int main(){
	char msg[SIZE];
	int fd[2];
	pid_t pid;
	
	signal(SIGPIPE, f);
	pipe(fd);

	if((pid=fork())>0){
		close(fd[0]);
		strcpy(msg,"apple is red.\n");
		write(fd[1],msg, SIZE);
		fprintf(stderr, "1st write\n");sleep(1);
		write(fd[1],msg,SIZE);
		fprintf(stderr, "2nd write\n");sleep(1);
		while(1);
	}
	else{
		close(fd[1]);
		read(fd[0],msg,SIZE);
		printf("[child] %s\n",msg);
	}
}
