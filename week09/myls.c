#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
int compare(const void* a, const void* b){
	return strcmp(*((char**)a),*((char**)b));
}
int main(int argc, char* argv[]){
	char *dir=".";
	if(argc>1) {
		if(strcmp(argv[1],"-a")==0){
			if(argc>2) dir=argv[2];
		}else dir=argv[1];
	}
	DIR *dp;
	struct dirent *entp;
	char *entries[512];
	int i,n=0;

	if((dp=opendir(dir))==NULL){
		perror(dir);
		exit(-1);
	}
	while((entp=readdir(dp))!=NULL){
		entries[n++]=strdup(entp->d_name);
	}
	closedir(dp);
	qsort(entries, n, sizeof(char*), compare);
	for(i=0;i<n;i++){
		printf("%s\n", entries[i]);
		free(entries[i]);
	}
	return 0;
}
