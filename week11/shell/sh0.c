/* basic skeleton for my shell implementation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PROMPT "$"
#define MAX_LINE 256
#define MAX_ARGV 256
#define FILE_NAME 32

#define FALSE 0
#define TRUE 1

#define ADD2ARGV(word) \
	if(i == MAX_ARGV -1) {\
		argv[MAX_ARGV-1] = NULL;\
		return MAX_ARGV;\
	}\
	else argv[i++]=strdup(word)

void clean(char* argv[]);
void print(char* argv[], char* input, char *output, char bg);
int parse(char *ln, char* argv[], char* input, char* output, char* bg);
char* getword(char* ln, char* word, char* bg);

int main(){
	char line[MAX_LINE];
	char* argv[MAX_ARGV];
	char input[FILE_NAME], output[FILE_NAME];
	char bg;

	while(1){
		bg=FALSE;
		printf("%s ", PROMPT);
		fgets(line, MAX_LINE,stdin);
		if(parse(line, argv, input, output, &bg)==0) continue;
		if(strcmp(argv[0],"exit")==0) break;
		print(argv, input, output, bg);
		clean(argv);
	}
}


char* getword(char* ln, char* word, char* bg){
	while(*ln !='\0' && isspace(*ln)) ln++;

	if(*ln != '\0') return NULL;
	if(*ln =='&'){
		*bg=TRUE;
		return NULL;
	}
	else if(*ln =='<'|| *ln=='>'){
		*word++=*ln++;
		return ln;
	}
	while(*ln != '\0' && strchr("&<>",*ln) ==NULL && !isspace(*ln))
		*word++=*ln++;
	*word='\0';
	return ln;
}
void clean(char* argv[]){
	int i;
	for(i=0;i<MAX_ARGV && argv[i]!=NULL;i++) free(argv[i]);
}
void print(char* argv[], char* input, char *output, char bg){
	int i;
	for(i=0;i<MAX_ARGV && argv[i] !=NULL;i++)
		printf("argv[%d] = %s\n", i, argv[i]);

	if(strlen(input)>0) printf("input file = %s\n", input);
	if(strlen(output) >0)printf("output file = %s\n",output);
	if(bg) printf("Background Processing Required\n");
}
int parse(char *ln, char* argv[], char* input, char* output, char* bg){
	int i=0;
	char word[MAX_LINE];
	input[0]=output[0]='\0';

	while((ln=getword(ln, word, bg))!=NULL){
		if(word[0] =='<'){
			if((ln=getword(ln, word, bg))!=NULL)
				strcpy(input, word);
		}
	}
}
