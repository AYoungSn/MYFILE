#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status;

	pid=fork();
	if(pid>0){
		printf("부모 시작\n");
		sleep(60);
	//	wait(&status);
		printf("부모 끝\n");
	}else if(pid==0){
		printf("child start\n");
		sleep(10);
		printf("child end\n");
	}
	printf("bye!\n");
}
