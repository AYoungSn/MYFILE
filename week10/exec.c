#include <stdio.h>
#include <unistd.h>
int main(){
	//execlp("ls", "ls", "-a", "-l", NULL);
	execlp("cat", "cat", "a.c", NULL);
	execl("cat", "cat", "a.c", NULL);
	fprintf(stderr, "Hello...\n");
}
