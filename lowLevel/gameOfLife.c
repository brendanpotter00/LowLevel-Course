//PLEDGE: Brendan potter
//besides what was given to us, this is entierly my own
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
bool **read_board(FILE* infile, long *size_p);

/*
 *  * generates new board configuration from old.
 *   */
void update_board(long size, bool **old_board, bool **new_board);

/*
 *  * prints board.
 *   */
void print_board(long size, bool **board);

/* 
 *  * main program
 *   */
int main(int argc, char* argv[]) {

	/* process command-line arguments */
	if (argc != 3) {
		fprintf(stderr, "parameters; infile num_steps\n");
		return EXIT_FAILURE;
	}
	FILE* infile = fopen(argv[1], "r");
	if (infile == NULL) {
		fprintf(stderr, "unable to open input file %s\n", argv[1]);
		return EXIT_FAILURE;
	}
	char* end_ptr_for_strtol;
	long steps = strtol(argv[2], &end_ptr_for_strtol, 10);
	if ((*end_ptr_for_strtol != '\0') || (steps < 0)) {
		fprintf(stderr, "invalid num_steps\n");
		return EXIT_FAILURE;
	}

	/* create board from input file */
	long size;
	bool **board = read_board(infile, &size);
	if (board == NULL) {
		fclose(infile);
		return EXIT_FAILURE;
	}
	fclose(infile);

	/* create second board to use for updates */
	bool **new_board = build2D(size);
	if (new_board == NULL) {
		free2D(size, board);
		return EXIT_FAILURE;
	}

	/* print initial configuration */
	printf("Initial board:\n");
	print_board(size, board);
	putchar('\n');

	/* loop to update board and print */
	for (long step = 1; step <= steps; ++step) {
		/* update (results in new_board) */
		update_board(size, board, new_board);
		printf("Board after step %ld:\n", step);
		print_board(size, new_board);
		putchar('\n');
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

bool **read_board(FILE* infile, long *size_p) {

	/* read size from input file */
	long size;
	if ((fscanf(infile, "%ld", &size) != 1) || (size <= 0)) {
		fprintf(stderr, "invalid size in input file\n");
		return NULL;
	}
	*size_p = size;

	/* build 2D array */
	bool **board = build2D(size);
	if (board == NULL) {
		return NULL;
	}

	/* fill with data from file */
	int inchar;
	for (long i = 0; i < size; ++i) {
		for (long j = 0; j < size; ++j) {
			/* get next nonspace character from input file */
			while (isspace(inchar = fgetc(infile))) { }
			if (inchar == '1') {
				board[i][j] = true;
			}
			else if (inchar == '.') {
				board[i][j] = false;
			}
			else {
				fprintf(stderr, 
					"unable to read values for board\n");
				free2D(size, board);
				return NULL;
			}
		}
	}
	/* check for anything else in input file */
	while (isspace(inchar = fgetc(infile))) { }
	if (!feof(infile)) {
		fprintf(stderr, "unable to read values for board\n");
		free2D(size, board);
		return NULL;
	}

	return board;
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
				else new_board[i][j]=true;
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
