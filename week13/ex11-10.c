#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

void onError(char* msg){
	fprintf(stderr, "%s",msg);
	exit(-1);
}

int main(){
	char msg[MSGSIZE];
	int p1[2],p2[2],i;
	pid_t pid1=0,pid2=0;
	fd_set initset, newset;

	pipe(p1);
	pipe(p2);

	if((pid1=fork())==-1)
		onError("fail to call fork() #1\n");

	if(pid1>0){
		if((pid2=fork())==-1)
			onError("fail to call fork() #2\n");
	}

	if(pid1>0 && pid2>0){
		printf("parent: %d\n", getpid());
		close(p1[1]);
		close(p2[1]);
		FD_ZERO(&initset);
		FD_SET(p1[0],&initset);
		FD_SET(p2[0], &initset);

		newset = initset;

		while(select(p2[0]+1, &newset, NULL,NULL,NULL)>0){
			if(FD_ISSET(p1[0],&newset)){
				if(read(p1[0],msg, MSGSIZE)>0)
					printf("[parent] %s\n",msg);
			}
			if(FD_ISSET(p2[0],&newset)){
				if(read(p2[0],msg,MSGSIZE)>0)
					printf("[parent] %s\n",msg);
			}
			newset=initset;
		}
	}
	else if(pid1==0&pid2==0){ //child1
		printf("child1: %d\n",getpid());
		close(p1[0]);close(p2[0]);close(p2[1]);
		for(i=0;i<3;i++){
			sleep((i+1)%4);
			printf("child1: send message %d\n",i);
			write(p1[1],"I'm child1",MSGSIZE);
		}
		printf("child: bye!\n");
		exit(0);
	}
	else if(pid1>0 &&pid2==0){//child2
		printf("child2: %d\n",getpid());
		close(p1[0]);close(p2[0]);close(p2[1]);
		for(i=0;i<3;i++){
			sleep((i+3)%4);
			printf("child2: send message %d\n",i);
			write(p2[1],"I'm child2",MSGSIZE);
		}
		printf("child2: bye!\n");
		exit(0);
	}
}
