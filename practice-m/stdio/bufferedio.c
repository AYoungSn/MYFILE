#include <stdio.h>
#include <unistd.h>
int main(){
	printf("Hello ");
	fprintf(stderr,"Error message...");
	printf("world  ");

	printf("Hello \n");
	fprintf(stderr, "Error message...");
	printf("world");
	
	sleep(3);
}
