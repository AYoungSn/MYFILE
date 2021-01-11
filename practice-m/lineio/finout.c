#include <stdio.h>
int main(){
	int number;
	char name[128];
	FILE *fp=fopen("result.txt","w");
	fprintf(stdout, "Enter your number: ");
	fscanf(stdin, "%d", &number);
	fprintf(stdout, "Enter your name: ");
	fscanf(stdin, "%s", name);
	fprintf(fp, "학번: %d, 이름: %s\n", number,name);
	fclose(fp);
}
