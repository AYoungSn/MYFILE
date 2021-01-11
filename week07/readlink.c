#include <stdio.h>
#include <unistd.h>
int main(){
	char buffer[1024];
	int nread;

	nread=readlink("test.lnk",buffer,1024);
	//write(1, buffer, nread);
	printf("%s\n",buffer);
}
