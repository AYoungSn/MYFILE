#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void f(int signo){
	printf("SIGINT caught\n");
	sleep(5);
}

int main(){
	struct sigaction s;
	s.sa_handler=f;
	sigfillset(&s.sa_mask);
	s.sa_flags=SA_RESETHAND;

	sigaction(SIGINT,&s,NULL);
	for(int j=0;;j++){
		printf("i = %d\n",j);
		sleep(1);
	}
	return 0;
}
