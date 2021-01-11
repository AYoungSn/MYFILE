#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){
	pid_t pid;
	printf("hello!\n");

	if((pid=fork())>0){
		/* parent */
		printf("parent\n");
		sleep(1);
	}
	else if(pid==0){
		/* child */
		printf("child\n");
		execl("/bin/ls", "ls", "-l", NULL);
		printf("fail to execute ls\n");
	}
	else printf("parent: fail to fork\n");
	printf("bye!\n");
}
