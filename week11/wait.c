#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	pid_t pid;
	int status;
	if((pid=fork())>0){
		wait(&status);
		printf("parent: status is 0x%x\n",status);
	}
	else if(pid==0){
		printf("child: pid = %d\n",getpid());
		sleep(2);
		exit(-1);
	}
}
