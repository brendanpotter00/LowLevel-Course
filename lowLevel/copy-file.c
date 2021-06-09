on of echo-text.c that copies from input file to output file,
 * counting characters.
 *  *
 *   * Filenames are specified with command-line arguments.
 *    */
#include <stdio.h>

int main(int argc, char *argv[]) {
	if (argc < 3) { 
		printf("usage:  %s infile outfile\n", argv[0]);
		return 1;
	}
	FILE * infile = fopen(argv[1], "r");
	if (infile == NULL) { 
		printf("cannot open file %s\n", argv[1]);
		return 1;
	}
	FILE * outfile = fopen(argv[2], "w");
	if (outfile == NULL) { 
		printf("cannot open file %s\n", argv[2]);
		return 1;
	}

	int ch;
        int count = 0;
	while ((ch = fgetc(infile)) != EOF) {
		fputc(ch, outfile);
		count += 1;
	}
	printf("%d characters copied\n", count);
	fclose(infile);
	fclose(outfile);
	return 0;
}

