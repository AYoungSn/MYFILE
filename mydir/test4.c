#include <stdio.h>
int main(){
	char s[256];

	while(fgets(s,256,stdin)!=NULL)
		fputs(s,stdout);
}
