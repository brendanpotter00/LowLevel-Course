/*PLEDGED:brendan potter*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findLength(char *data);
int compare(const void *e1, const void *e2);

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("not engough arguments\n");
		return EXIT_FAILURE;
	}
	
	int fileSize = findLength(argv[1]);
	if(fileSize == 0){
	 	printf("file is empty\n");
		return EXIT_FAILURE;
	}
	char *data;

	if ((data = malloc(fileSize)) == NULL) {
		printf("unable to allocate space for %d values\n", fileSize);
		return EXIT_FAILURE;
	}
	/*already cheched if file was empty*/
	FILE *instream = fopen(argv[1], "r");
	char n;
	int numNewLines = 0;
	for( int i = 0; i < fileSize+1; i++){
		if (fscanf(instream, "%c", &n) == 1) {
			data[i] = n;
		}
		if(n == '\n') numNewLines++;
	}
	/* check whether loop stopped because of EOF or error */
	if (!feof(instream)) {
		printf("bad input\n");
		fclose(instream);
		return EXIT_FAILURE;
	}
	fclose(instream);
	
	char ** lines = malloc(sizeof(lines[0]) * numNewLines);
	lines[0] = &data[0];
	int index = 1;
	for(int i=1; i < fileSize; i++){
		if(data[i]=='\n'){
			lines[index]=&data[i+1];
			index++;
			data[i]='\0';
		}
	}
	
	FILE * outstream = fopen(argv[2], "w");
	if (outstream == NULL) { 
			fprintf(stderr, "cannot open file %s\n", argv[2]);
			return EXIT_FAILURE; 
		}
	
	qsort(lines,numNewLines,sizeof(lines[0]),&compare);
	for(int i=1; i < numNewLines; i++){
		fprintf(outstream,"%s\n",lines[i]);
	}
	fclose(outstream);
	free(data);

}

int findLength(char *data){
	FILE * instream = fopen(data, "r");
	if (instream == NULL) { 
		printf("cannot open file %s\n", data);
		return 0; 
	}
	
	int length = 0;
	char n;
	while (fscanf(instream, "%c", &n) == 1) {
		length += 1;
	}
	fclose(instream);
	return length;
}

int compare(const void *e1, const void *e2) {
    const char **i1 = ( void *) e1;
    const char **i2 = ( void *) e2;

	if (strcmp(*i1,*i2) < 0)
        return -1;
    else if (strcmp(*i1,*i2)>0)
        return 1;
    else
        return 0;
}
