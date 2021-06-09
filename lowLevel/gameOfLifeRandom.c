//PLEDGE: Brendan potter
//besides what was give to us, this is entierly my own
/*
 *  * C program for Conway's ``game of life''.
 *   *
 *    * Command-line arguments specify input file and number of steps.
 *     *
 *      * Input file contains a representation of an initial board configuration:
 *       * N (size of board) and N*N values (each 0 or 1).
 *        */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* 
 *  * builds 2D array in form of an array of pointers into one big 1D array.
 *   * return value is array of pointers, or NULL if there was a problem
 *    *   (in which case the function prints a suitable error message).
 *     */
bool **build2D(long size);

/*
 *  * frees 2D array, built as in build2D().
 *   */
void free2D(long size, bool **array2D);

/* 
 *  * reads initial board configuration from file.
 *   * builds 2D array in form of an array of pointers into one big 1D array.
 *    * parameters:
 *     *   infile is an already-opened file.
 *      *   (out) *size_p is board size 
 *       * return value is array of pointers, or NULL if there was a problem
 *        *   (in which case the function prints a suitable error message).
 *         */
void randomBoard(bool **board, long size, double fract, long seed);

/*
 *  * generates new board configuration from old.
 *   */
void update_board(long size, bool **old_board, bool **new_board);

/*
 *  * prints board.
 *   */
void print_board(long size, bool **board);

int findalive(bool **board,long size);
/* 
 *  * main program
 *   */
int main(int argc, char* argv[]) {

	/* process command-line arguments */
	if (argc != 5 && argc != 6) {
		fprintf(stderr, "parameters; infile num_steps\n");
		return EXIT_FAILURE;
	}
	long size;
	size = strtod(argv[1],NULL);
	if (size%1 != 0) {
		fprintf(stderr, "unexceptable size %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	long steps = strtod(argv[4],NULL);
	if (steps%1 != 0) {
		fprintf(stderr, "unexceptable steps %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	long seed = strtod(argv[2],NULL);
	if (seed%1 != 0) {
		fprintf(stderr, "unexceptable seed %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	srand(seed);
	double fract = strtod(argv[3],NULL);
	bool pr;
	if(argc == 6) pr = true;
	else pr=false;
	
	bool **board = build2D(size);
	randomBoard(board,size,fract,seed);
	
	/* create second board to use for updates */
	bool **new_board = build2D(size);
	if (new_board == NULL) {
		free2D(size, board);
		return EXIT_FAILURE;
	}
	
	/* print initial configuration */
	printf("%d live cells at start\n",findalive(board,size));
	if(pr){
		print_board(size, board);
		putchar('\n');
	}
	/* loop to update board and print */
	for (long step = 1; step <= steps; ++step) {
		/* update (results in new_board) */
		update_board(size, board, new_board);
		printf("%d live cells after step %d\n",findalive(new_board,size),step);
		if(pr) {print_board(size, new_board);
		putchar('\n');}
		/* swap old and new boards by exchanging pointers(!) */
		bool **temp = board;
		board = new_board;
		new_board = temp;
	}

	/* tidy up and return */
	free2D(size, board);
	free2D(size, new_board);
	return EXIT_SUCCESS;
}

/*
 *  * functions (described above)
 *   */

bool **build2D(long size) {
	bool *data = malloc(size * size * sizeof(data[0]));
	if (data == NULL) {
		fprintf(stderr, 
			"unable to allocate space for board of size %ld\n",
			size);
		return NULL;
	}
	bool **array2D = malloc(size * sizeof(array2D[0]));
	if (array2D == NULL) {
		fprintf(stderr, 
			"unable to allocate space for board of size %ld\n",
			size);
		return NULL;
	}
	for (long r = 0; r < size; ++r) {
		array2D[r] = &data[r*size];
	}
	return array2D;
}

void free2D(long size, bool **array2D) {
	bool *data = array2D[0];
	free(data);
	free(array2D);
}

void randomBoard(bool **board, long size, double fract, long seed) {
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			double r = rand();
			double rr = r/RAND_MAX;
			if(rr < fract) board[i][j]=true;
			else board[i][j] = false;
		}
	}
}

void update_board(long size, bool **old_board, bool **new_board) {
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			new_board[i][j] = false;
			int cnt = 0;
			int alv;			
			if(old_board[i][j]) alv=1;
			else alv=0;
	
			if(i>0 && j>0){if(old_board[i-1][j-1]) cnt=cnt+1;}
                        if(i>0){if(old_board[i-1][j]) cnt=cnt+1;}
                        if(i>0 && j<size-1){if(old_board[i-1][j+1]) cnt=cnt+1;}
                        if(j>0){if(old_board[i][j-1]) cnt=cnt+1;}
                        if(j<size-1){if(old_board[i][j+1]) cnt=cnt+1;}
                        if(i<size-1 && j>0){if(old_board[i+1][j-1]) cnt=cnt+1;}
                        if(i<size-1){if(old_board[i+1][j]) cnt=cnt+1;}
                        if(i<size-1 && j<size-1){if(old_board[i+1][j+1]) cnt=cnt+1;}
			
			if(alv==0 && cnt==3) new_board[i][j]=true;
			if(alv==1){
				if(cnt!=2 && cnt!=3) new_board[i][j]=false;
				else new_board[i][j] = true;
			}
		}
	}
}

void print_board(long size, bool **board) {
	for (long i = 0; i < size; ++i) {
		for (long j = 0; j < size; ++j) {
			if (board[i][j]) 
				printf("1 ");
			else
				printf(". ");
		}
		putchar('\n');
	}
}

int findalive(bool **board,long size){
	int cnt = 0;
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			if(board[i][j])cnt=cnt+1;
		}
	}
	return cnt;
}
