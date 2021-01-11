#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	pid_t pid;
	int status;

	if((pid=fork())>0){
		printf("parent: waiting..\n");
		wait(&status);
		//printf("parent: status is 0x%x\n", status);
		printf("parent: status is 0x%x\n", status>>8);
	}
	else if(pid==0){
		sleep(1);
		printf("child: bye!\n");
		exit(1234);
	}
	printf("bye!\n");
}
