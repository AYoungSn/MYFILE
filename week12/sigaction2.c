#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void f(int signo){
	if(signo==SIGCHLD)printf("SIGCHLD caught\n");
	if(signo==SIGCONT)printf("SIGCONT caught\n");
}

int main(){
	struct sigaction s;
	s.sa_handler=f;
	sigfillset(&s.sa_mask);
	s.sa_flags=0;

	if(fork()>0){
		//parent
		sigaction(SIGCHLD,&s, NULL);
		for(int i=0;;i++){
			printf("i = %d\n",i);
			sleep(1);
		}
	}else{
		//child
		sigaction(SIGCONT,&s,NULL);
		for(int j=0;;j++){
			printf("pid = %d, j = %d\n",getpid(),j);
			sleep(1);
		}
	}
}
