#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MSGSIZE 64

int main(){
	char msg[MSGSIZE];
	int fd, n,j;
	mkfifo("./fifo",0666);
	if((fd=open("./fifo",O_RDONLY))<0){
		perror("fifo");
		exit(-1);
	}
	fprintf(stderr, "fifo opened successfully...\n");

	for(j=0;j<3;j++){
		if((n=read(fd, msg, MSGSIZE))<0){
			perror("read");exit(-1);
		}
		//오류 수정
		if(n==0) break;
		printf("recv: %s\n",msg);
	}
	unlink("./fifo");
}
