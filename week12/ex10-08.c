#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void f(int signo){
	printf("signal hander is called.\n");
}

int main(){
	signal(SIGINT, f);
	printf("pause return %d\n",pause());
}
