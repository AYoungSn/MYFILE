#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main(){
	int a,b, result;
	char op;
	scanf("%d%c%d", &a,&op,&b);

	if(op=='+')
		result = add(a,b);
	else if(op=='-')
		result = sub(a,b);
	else if(op=='*')
		result=mul(a,b);
	else
		result=div(a,b);

	printf("%d %c %d = %d\n",a,op, b,result);

}
