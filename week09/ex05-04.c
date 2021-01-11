#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a, const void* b){
	return strcmp(*((char**)a),*((char**)b));
}
int main(){
	DIR *dirp;
	struct dirent* dentry;
	char* dir=".",*entries[512];
	int i=0,n=0;

	if((dirp=opendir("."))==NULL)exit(1);

	while((dentry=readdir(dirp))!=NULL){
		//printf("%s\n",dentry->d_name);
		entries[n++]=strdup(dentry->d_name);
	}
	closedir(dirp);

	qsort(entries,n, sizeof(char*),compare);
	for(i=0;i<n;i++){
		printf("%s\n",entries[i]);
		free(entries[i]);
	}
	return 0;
}
