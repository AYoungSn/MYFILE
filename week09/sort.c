#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b){
	return *((int*)b)-*((int*)a);
}

int main(){
	int data[10]={9,2,1,0,4,7,3,5,8,6};

	qsort(data, 10, sizeof(int), cmp);

	for(int i=0;i<10;i++) printf("%d ", data[i]);
	printf("\n");
	return 0;
}
