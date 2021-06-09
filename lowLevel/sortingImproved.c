/* sort function: 
 * Generate a random sequence of N integers, sort them, and check
 *  * that the sort succeeded.  
 *   * This version prompts for N and a seed for generating the random
 *    * sequence but hardcodes a maximum for N.  Also, the sort function 
 *     * doesn't do anything, so will almost surely fail!
 *      */
#include <stdio.h>
#include <stdlib.h> /* has EXIT_SUCCESS, EXIT_FAILURE */

#define MAX_COUNT 100

/* function declarations -- see definitions (at end) for more comments */
void fill_with_random(int a[], int size);
void sort(int a[], int size);
void print(int a[], int size);
int find_out_of_order(int a[], int size);

/* main program */
int main(void) {

	int data[MAX_COUNT];
	int count;
	int seed;

	/* prompt for how many to sort, seed for rand() */
	printf("how many to sort?\n");
	if (scanf("%d", &count) != 1) {
		printf("value must be integer\n");
		return EXIT_FAILURE;
	}
	if ((count < 1) || (count > MAX_COUNT)) {
		printf("value must be between 1 and %d\n", MAX_COUNT);
		return EXIT_FAILURE;
	}
	printf("seed for generating random sequence?\n");
	if (scanf("%d", &seed) != 1) {
		printf("value must be integer\n");
		return EXIT_FAILURE;
	}
	if ((seed <= 0)) {
		printf("value must not be negative\n");
		return EXIT_FAILURE;
	}

	srand(seed);
	fill_with_random(data, count);
	/* uncomment if you want to print */
	/* print(data, count) */
	sort(data, count);
	/* uncomment if you want to print */
	/* print(data, count) */
	int out_of_order = find_out_of_order(data, count);
	if (out_of_order < 0) {
		printf("sorted\n");
	}
	else {
		printf("not sorted\n");
		printf("first out-of-order element at index %d\n", out_of_order);
	}

	return EXIT_SUCCESS;
}

/* fill array with randomly generated data */
void fill_with_random(int a[], int size) {
	for (int i = 0; i < size; ++i) {
		a[i] = rand();
	}
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




