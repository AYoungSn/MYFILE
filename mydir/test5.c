#include <stdio.h>

int main(){
	char s[256];
	FILE *fp1,*fp2;

	fp1=fopen("data.txt","r");
	fp2=fopen("result.txt","w");

	while(fgets(s,256,fp1)!=NULL)
		fputs(s,fp2);
}
