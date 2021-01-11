#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MSGSIZE 64

void f(int signo){
	fprintf(stderr, "SIGPIPE is received\n");
	exit(-1);
}

int main(){
	char msg[MSGSIZE];
	int fd;
	signal(SIGPIPE,f);

	if((fd=open("./fifo",O_WRONLY))<0){
		perror("fifo");
		exit(-1);
	}
	fprintf(stderr, "fifo opened successfully...\n");
	while(1){
		printf("input a message: ");
		scanf("%s",msg);
		if(write(fd, msg, MSGSIZE)==-1){
			perror("write");
			exit(-1);
		}
	}
}
