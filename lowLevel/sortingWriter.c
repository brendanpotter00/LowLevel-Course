// Pledged: brendan potter
/* sort function: 
 * Generate a random sequence of N integers, sort them, and check
 *  * that the sort succeeded.  
 *   * This version prompts for N and a seed for generating the random
 *    * sequence but hardcodes a maximum for N.  Also, the sort function 
 *     * doesn't do anything, so will almost surely fail!
 *      */
#include <stdio.h>
#include <stdlib.h> /* has EXIT_SUCCESS, EXIT_FAILURE */

#define MAX_COUNT 5

/* function declarations -- see definitions (at end) for more comments */
void sort(int a[], int size);
void print(int a[], int size);
int find_out_of_order(int a[], int size);

/* main program */
int main(int argc, char* argv[]) {
	if(argc < 2) {
		fprintf(stderr, "not enough arguments\n");
		return EXIT_FAILURE;
	}
	FILE * instream = fopen(argv[1],"r");
	if (instream == NULL) {
		fprintf(stderr, "cannot open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	FILE * outstream = fopen(argv[2],"w");
	if (outstream == NULL) {
		fprintf(stderr, "cannot open file %s\n",argv[2]);
		return EXIT_FAILURE;
	}
	
	int data[MAX_COUNT];
	int i=0;
	while (fscanf(instream,"%d", &data[i]) == 1){
		++i;
	}
	if(!feof(instream)){
		fprintf(stderr, "bad input\n");
		fclose(instream);
		fclose(outstream);
		return EXIT_FAILURE;
	}
	fclose(instream);
	
	sort(data, 5);
	/* uncomment if you want to print */
	/* print(data, count) */
	int out_of_order = find_out_of_order(data, 5);
	if (out_of_order < 0) {
		printf("sorted\n");
	}
	else {
		printf("not sorted\n");
		printf("first out-of-order element at index %d\n", out_of_order);
	}
	for(int i=0; i < 5; ++i){
		fprintf(outstream, "%d ", data[i]);
	}
	fclose(outstream);

	return EXIT_SUCCESS;
}



/* print array */
void print(int a[], int size) {
	for (int i=0; i < size; ++i) {
		printf("%d\n", a[i]);
	}
}

/* 
 *  * check whether array is sorted:
 *   * returns index of first out-of-order element, or -1 if all are in order
 *    */
int find_out_of_order(int a[], int size) {
	for (int i = 0; i < size-1; ++i) {
		if (a[i] > a[i+1]) { 
			return i;
		}
	}
	return -1;
}

/* sort array */
void sort(int a[], int size){
        for(int i = 0; i < size-1; ++i){
                for(int j=0; j < size-1-i;++j){
                        if(a[j] > a[j+1]){
                                int temp = a[j];
                                a[j] = a[j+1];
                                a[j+1] = temp;
                        }
                }
        }
}




