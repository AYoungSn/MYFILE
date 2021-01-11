#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid1=-1, pid2=-1;
	int status;

	if((pid1=fork())>0) pid2=fork();

	if(pid1>0 && pid2>0){
		waitpid(pid2, &status,0);
		printf("parent: child2 - exit(%x)\n",status);
		waitpid(pid1, &status,0);
		printf("parent: child1 - exit(%x)\n",status);
	}
	else if(pid1==0){
		sleep(10);
		exit(1);
	}
	else if(pid2==0){
		sleep(20);exit(2);
	}
}
