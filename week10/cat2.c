#include <stdio.h>
#include <unistd.h>

int main(){
	execl("/bin/cat", "cat", "data.in", NULL);
	fprintf(stderr, "exec failure...\n");
}
