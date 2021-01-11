#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	fprintf(stderr, "%s\n",argv[argc]);
	execlp(argv[1], argv[1],NULL);
	fprintf(stderr, "exec failure...\n");
}
