#include <unistd.h>
#include <stdio.h>

int main(){
	char s[100];

	printf("Enter file to delete: ");
	scanf("%s",s);

	unlink(s);

	return 0;
}
