#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int num=0;
void f(int signum){
	printf("SIGINT: %d\n",signum);
	printf("int_handle called %d times\n",++num);
}

int main(){
	struct sigaction act;

	act.sa_handler=f;
	sigfillset(&act.sa_mask);
	act.sa_flags=0;

	sigaction(SIGINT, &act, NULL);
	while(1){
		printf("i'm sleepy...\n");
		sleep(1);
		if(num>=2){
			act.sa_handler=SIG_DFL;
			sigaction(SIGINT, &act, NULL);
		}
	}
}
