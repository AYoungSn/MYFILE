#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	pid_t pid;

	if((pid=fork())>0){
		sleep(10);
		printf("bye\n");
	}
	else if(pid==0){
	//	setsid();
		sleep(600);
	}
}
