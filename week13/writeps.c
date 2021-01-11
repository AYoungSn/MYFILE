#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define SIZE 512

int main(){
	char msg[SIZE];
	int fd[2];
	pid_t pid;

//	signal(SIGPIPE,f);
	pipe(fd);

	if((pid=fork())>0){
		close(fd[0]);
		strcpy(msg,"apple is red.\n");
		write(fd[1],msg,SIZE);
		fprintf(stderr, "1st write\n");
	}
	else{
		close(fd[1]);
		while(1){
			if(read(fd[0],msg,SIZE)==0){
				fprintf(stderr,"pipe is broken!!\n");
				exit(-1);
			}
			printf("[read] %s\n",msg);
			sleep(1);
		}
	}
}
