// Pledged: Brendan potter
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	if (argc != 4) { 
		printf("usage:  %s infile outfile\n", argv[0]);
		return 1;
	}
	FILE * instream = fopen(argv[2], "r");
	if (instream == NULL) { 
		printf("cannot open file %s\n", argv[2]);
		return 1;
	}
	FILE * outstream = fopen(argv[3], "w");
	if (outstream == NULL) { 
		printf("cannot open file %s\n", argv[3]);
		return 1;
	}
	char *shift;
	long n = strtol(argv[1],&shift,10);
	
	int ch;

	int rotate(int inchar, int positions_to_rotate) {
	    /* or put these declarations outside all functions to make them "global" */
	    char* lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
	    char* uc_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	    /* look for input character in list of lowercase chars */
	    char* in_lc_alphabet = strchr(lc_alphabet, inchar);
	    if (in_lc_alphabet != NULL) {
	        /* lower-case character:  find rotated char in lc_alphabet */
	        int position_in_alphabet = in_lc_alphabet - lc_alphabet;
	        /* 
	 *           * YOUR CODE GOES HERE:
	 *                    * use lc_alphabet and positions_to_rotate to find new character
	 *                             *   and return it
	 *                                      * strlen(lc_alphabet) may be helpful
	 *                                               */
	        int newPosition = position_in_alphabet + positions_to_rotate;
	        if(newPosition > 25){
	                newPosition = strlen(lc_alphabet) - newPosition;
	        }
	        return lc_alphabet[newPosition];
	    }
	    /*
	 * *       * YOUR CODE GOES HERE:
	 * *            * do something similar to the above for uppercase characters
	 * *                 * if input character not found in either "alphabet" just return it
	 * *                      */
	        char* inUcAlphabet = strchr(uc_alphabet, inchar);
	        if(inUcAlphabet != NULL) {
	                int posInAl = inUcAlphabet - uc_alphabet;
	                int newPosition = posInAl + positions_to_rotate;
	                if(newPosition > 25){
	                       // newPosition = strlen(uc_alphabet) + newPosition;
	                       	newPosition = strlen(uc_alphabet) - newPosition;
	                }
	        return uc_alphabet[newPosition];
	        }
	return ' ';
        
	 }

	
	
	
	while((ch = fgetc(instream)) != EOF) {
                fputc(rotate(ch,n), outstream);
        }	
	fclose(instream);
	fclose(outstream);
	return 0;
}

