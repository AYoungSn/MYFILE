#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
	printf("PPID: %d, PID: %d\n",getppid(),getpid());
}
