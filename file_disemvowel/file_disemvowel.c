#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define BUF_SIZE 1024

void disemvowel(FILE* inputFile, FILE* outputFile) {
	char* str = calloc(BUF_SIZE + 1,sizeof(char));
	char* result;
	int i = 0;
	int j = 0;
	while(fgets(str,BUF_SIZE,inputFile) != 0 ){
		i = 0;
		j = 0;
		result = (char*) calloc(strlen(str)+1, sizeof(char));
		for(i=0;str[i];i++){
			char temp[1]={str[i]};
			if(strpbrk(temp,"aeiouAEIOU")){
			}else{
				result[j++] = str[i];
			}
		}
		result[j] = '\0';
		fwrite(result,1,strlen(result),outputFile);
		free(result);
	}
	free(str);
}

int main(int argc, char *argv[]) {
	// This sets these to `stdin` and `stdout` by default.
	// You then need to set them to user specified files when the user
	// provides files names as command line arguments.
	FILE *inputFile = stdin;
	FILE *outputFile = stdout;



	switch (argc){
	case 1:
		break;
	case 2:
		if ( ( inputFile  = fopen( argv[1], "r" )) == NULL ){
			puts( "Can't open input file.\n" );
			exit( 0 );
		}
		break;
	case 3:
		if ( ( inputFile = fopen( argv[1], "r" )) == NULL){ 
			puts( "Can't open input file.\n" );
			exit( 0 );
		}
		if ( ( outputFile = fopen( argv[2], "w" )) == NULL ){
			puts( "Can't open output file.\n" );
			exit( 0 );
		}
	}
	disemvowel(inputFile, outputFile);

	return 0;
}
