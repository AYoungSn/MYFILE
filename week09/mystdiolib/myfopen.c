#include "mystdio.h"
MYFILE* myfopen(char *file, char *mode){
	MYFILE *fp=(MYFILE*)malloc(sizeof(MYFILE));

	if(fp!=NULL){
		if(strcmp(mode,"r")==0){
			if((fp->fd=open(file,O_RDONLY))<0){
				free(fp);
				return NULL;
			}
			fp->mode=READONLY_MODE;
		}
		else{
			if((fp->fd=open(file, O_WRONLY|O_CREAT|O_TRUNC,0644))<0){
				free(fp);
				return NULL;
			}
			fp->mode=WRITEONLY_MODE;
		}
		fp->length=fp->offset=0;
	}
	return fp;
}
