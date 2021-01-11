#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 512

int main(){
	char msg[SIZE];
	int i, fd[2];

	if(pipe(fd)==-1){
		perror("pipe");
		exit(1);
	}
	fprintf(stderr, "%d, %d\n",fd[0],fd[1]);
	for(i=0;i<3;i++){
		printf("input a message\n");
		fgets(msg, SIZE, stdin);
		write(fd[1],msg,SIZE);
	}
	printf("\n");
	for(i=0;i<3;i++){
		read(fd[0],msg, SIZE);
		printf("%s",msg);
	}
}
