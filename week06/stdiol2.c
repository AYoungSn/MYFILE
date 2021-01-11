#include <stdio.h>
#define BUFSIZE 100

main(){
	char buf[BUFSIZE];
	FILE *fp1, *fp2;
	fp1=fopen("a","r");
	fp2=fopen("b","w");
	while(fgets(buf, BUFSIZE, fp1)!=NULL)
		fputs(buf,fp2);
}
