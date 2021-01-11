#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 256

void printcwd(){
	char buffer[BUF_SIZE];
	getcwd(buffer,BUF_SIZE);
	printf("cwd=%s\n",buffer);
}

int main(){
	printcwd();
	chdir("/usr/include");
	printcwd();
	chdir("..");
	printcwd();
}
