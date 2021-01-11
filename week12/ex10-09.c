#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler(int signo){
	printf("\nSIGINT cought\n");
}
int main(){
	struct sigaction act;

	act.sa_handler=handler;
	sigfillset(&act.sa_mask);
	sigaction(SIGINT,&act, NULL);

	printf("pause return %d\n",pause());
}
