#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void f(int signo){
	printf("signo = %d\n",signo);
}
int main(){
	signal(SIGINT, f);
	signal(SIGQUIT, f);
	signal(SIGTERM, f);
	signal(SIGCONT, f);
	signal(SIGTSTP, f);
	//signal(SIGSTOP,f);불가
	//signal(SIGKILL,f);불가
	
	for(int i=0;;i++){
		sleep(1);
		printf("i = %d\n",i);
	}
}
