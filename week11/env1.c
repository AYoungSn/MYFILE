#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

int main(){
	char *mycalc = getenv("MYCALC");
	char printHexa = FALSE;
	int num1, num2;

	if(mycalc==NULL){
		fprintf(stderr, "MYCALC is not defined\n");
		exit(-1);
	}
	if(strcmp(mycalc, "16")==0)
		printHexa=TRUE;
	while(1){
		printf("Enter two numbers: ");
		scanf("%d %d",&num1, &num2);
		if(printHexa)printf("sum = %x\n", num1+num2);
		else printf("sum = %d\n",num1+num2);
	}
}
