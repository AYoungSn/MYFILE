#include <stdio.h>

int main(){
	fprintf(stdout, "Hello ");
	fprintf(stderr, "This is an error message...");
	fprintf(stdout, "world!!\n");

	fprintf(stdout, "Hello\n");
	fprintf(stderr, "This is an error message...");
	fprintf(stdout, "world!!\n");

	fprintf(stdout, "Hello");
	fprintf(stderr, "This is an error message...");
	fprintf(stdout, "world!!");
	fprintf(stderr, "This is an error message...");
	fprintf(stdout, "Hello");
}
