#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void f(int signo){
	printf("signo = %d\n",signo);
}
int main(){
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	//signal(SIGSTOP,SIG_IGN);불가
	//signal(SIGKILL,f);불가
	
	for(int i=0;;i++){
		sleep(1);
		printf("i = %d\n",i);
	}
}
