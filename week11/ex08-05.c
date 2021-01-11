#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	pid_t pid;

	if((pid=fork())>0){
		printf("ppid: %d, pid: %d\n",getppid(),getpid());
		sleep(1);
	}
	else if(pid==0){
		printf("ppid:%d, pid:%d\n",getppid(), getpid());
		execl("./0806","0806",NULL);
	}
}
