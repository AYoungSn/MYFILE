#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	if(argc!=3)exit(1);
	if(rename(argv[1], argv[2])==0) printf("성공!\n");
	else printf("실패!\n");

}
