#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *language=getenv("LANGUAGE2");

	if(language==NULL){
		fprintf(stderr, "LANGUAGE is not defined\n");
		exit(-1);
	}
	if(strcmp(language, "ko")==0){
		printf("안녕하세요?\n");
		printf("만나서 반가워요\n");
	}
	else if(strcmp(language, "sp")==0){
		printf("Hola!\n");
		printf("Gusto en conocerte!\n");
	}else{
		printf("Hello!\n");
		printf("Nice to meet you!\n");
	}
}
