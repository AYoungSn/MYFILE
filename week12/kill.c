#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(){
	int pid,stopped=0;

	if((pid=fork())>0){
		/* parent */
		for(int i=1;;i++){
			printf("i = %d\n",i);
			sleep(1);
			if(i%3==0){
				if(!stopped) kill(pid, SIGSTOP);
				else kill(pid, SIGCONT);
				stopped =!stopped;
			}
		}
	}else{
		for(int i=1;;i++){
			printf("\tpid=%d, j=%d\n",getpid(),i);
			sleep(1);
		}
	}
}
