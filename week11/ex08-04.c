#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status=0;

	if((pid=fork())>0){
		while(!waitpid(pid, &status, WNOHANG)){
			printf("parent: %d\n",status++);
			sleep(1);
		}
		printf("parent: child - exit(%x)\n",status);
	}
	else if(pid==0){
		sleep(5);
		printf("bye!\n");
		exit(1);
	}
}
