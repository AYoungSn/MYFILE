#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>


int compare(const void* a, const void* b){
	return strcmp(*((char**)a),*((char**)b));
}

int main(int argc, char* argv[]){
	DIR* dp;
	struct dirent *entp;
	char* dir=".",*entries[512];
	int i,n=0;

	if(argc>1) dir=argv[1];
	dp=opendir(dir);
	
	while((entp=readdir(dp))!=NULL)
		entries[n++]=strdup(entp->d_name);
	closedir(dp);

	qsort(entries,n,sizeof(char*),compare);

	for(i=0;i<n;i++){
		printf("%s\n",entries[i]);
		free(entries[i]);
	}
	return 0;
}
