#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
void func1();
void func2();

int main(){
	fprintf(stderr, "Hello!\n");
	atexit(func1);
	atexit(func2);

	fprintf(stderr, "bye!\n");
	_exit(0);

}

void func1(){
	fprintf(stderr, "func1\n");
}
void func2(){
	fprintf(stderr, "func2\n");
}
