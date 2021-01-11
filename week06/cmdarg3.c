#include <stdio.h>
int main(int argc, char *argv[]){
	while(--argc>0)
		printf("argv = %s\n",*++argv);
	return 0;
}
