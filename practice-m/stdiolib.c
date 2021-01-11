#include <stdio.h>

int main(){
	fprintf(stdout, "Hello ");
	fprintf(stderr, "Error message...\n");
	fprintf(stdout, "world!!!");

	fprintf(stdout, "Hello ");
	fprintf(stderr, "Error message...");
	fprintf(stdout, "world!!!\n");
}
