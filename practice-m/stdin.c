#include <stdio.h>

int main(){
	char buf[100];
	fgets(buf,100,stdin);
	fputs(buf,stdout);
}
