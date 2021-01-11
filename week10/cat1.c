#include <unistd.h>
#include <stdio.h>

int main(){
	execl("/bin/cat", "cat", NULL);
	fprintf(stderr, "exec failure...\n");
}
