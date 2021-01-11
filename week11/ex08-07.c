#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	printf("getpgid(getpid()):%d\n", getpgid(getpid()));
	printf("getpgid(0): %d\n",getpgid(0));
	printf("getpgrp():%d\n",getpgrp());
}
