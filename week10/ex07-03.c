#include <unistd.h>
#include <stdio.h>
int main(){
	printf("before executing ls -l\n");
	execl("/bin/ls", "ls", "-l", NULL);
	printf("after executing ls -l\n");
}
