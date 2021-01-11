#include <stdio.h>
#include <unistd.h>

int main(){
	char ln[128];
	int n;
	fprintf(stderr, "mycat is starting...\n");
	while((n=read(3,ln, 128))>0)write(1, ln, n);
}
