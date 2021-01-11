#include <stdio.h>
#include <unistd.h>

int main(){
	char *arg[]={"ls","-l",NULL};
	printf("before executing ls -l\n");
	execv("/bin/ls", arg);
	printf("after executing ls -l\n");
}
