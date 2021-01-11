#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void f(int signo){
	if(signo==SIGCHLD)printf("SIGCHLD caught\n");
	if(signo==SIGCONT)printf("SIGCONT caught\n");
}

int main(){
	if(fork()>0){
		//parent
		signal(SIGCHLD,f);
		for(int i=0;;i++){
			printf("i = %d\n",i);
			sleep(1);
		}
	}else{
		//child
		signal(SIGCONT,f);
		for(int j=0;;j++){
			printf("pid = %d, j = %d\n",getpid(),j);
			sleep(1);
		}
	}
}
