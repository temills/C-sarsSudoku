/*
 * sudoku - generates and solves sudoku puzzles
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void print_grid(int *grid, int size);
bool process_input(int *grid, int size);

int main(int argc, char *argv[]) {
        char *mode;
        int size = 81;

        //check arg #
        if(argc != 2) {
                fprintf(stderr, "Usage: provide one arg indicating mode\n");
                return 1;
        }

        //allocate memory for grid
        int *grid = malloc(sizeof(int)*size);
        if(grid == NULL) {
                fprintf(stderr, "Error: unable to allocate memory for grid\n");
                return 2;
        }

        mode = argv[1];

        //create mode
        if(strcmp(mode, "create") == 0) {
                //initialize empty grid
                for(int i=0; i<size; i++)
                        *(grid+i) = 0;
                //initialize creator
                creator(grid, size);
        }
        //solve mode
        else if(strcmp(mode, "solve") == 0) {
                //get puzzle to be solved
                if(process_input(grid, size)) {
                        //initialize solver
                        solver(grid, size);
                }
                else {
                        printf("Error: invalid input\n");
                        return 4;
                }
        }
        //invalid mode
        else {
                fprintf(stderr, "Error: mode must be either 'create' or 'solve'\n");
                free(grid);
                return 3;
        }

        //print output
        print_grid(grid, size);
        free(grid);
        return 0;
}

/*
 * process_input reads user input and modifies the grid appropriately
 * reads n = "size" ints into grid, adding them in order
 * returns true if n = "size" ints read into grid, false otherwise
 */
bool process_input(int *grid, int size) {
        for(int i=0; i<size; i++) {
                if(fscanf(stdin, "%d", (grid+i)) != 1)
                       return false;
        }
        return true;
}


/*
 * print_grid prints the numbers in the given array in a 9x9 grid to stdout.
 * If size != 81, it does nothing.
 * Otherwise, it prints the numbers line by line, with the first 9 numbers in the first line,
 * the second 9 numbers in the second line, and on until 9 lines have been printed.
 * Numbers are separated by a whitespace.
 */
void print_grid(int *grid, int size) {
        if(size == 81) {
                for(int i=0; i<9; i++) {
                        for(int j=0; j<9; j++) {
                                printf("%d ", *(grid+(i*9)+j));
                        }
                        printf("\n");
                }
        }
}
