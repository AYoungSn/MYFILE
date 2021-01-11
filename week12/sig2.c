#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int counter =0;

void f(int signo){
	if(signo==SIGINT) printf("you pressed Ctrl-C\n");
	else if(signo==SIGQUIT) printf("you pressed Ctrl-\\\n");
	else if(signo==SIGTSTP) printf("you pressed Ctrl-Z\n");
	printf("signo = %d, counter = %d\n",signo, counter);
	counter++;
}

int main(){
	signal(SIGINT, f);
	signal(SIGQUIT, f);
	signal(SIGTSTP, f);

	while(counter <10){
		printf("Die Hard\n");
		sleep(1);
	}
	printf("I am dying\n");
	return 0;
}
