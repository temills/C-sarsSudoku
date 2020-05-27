# C-sarSudoku Design

C-sarSudoku program generates and solves sudoku puzzles. Creator creates
sudoku puzzle with a unique solution.

* [User Interface](#user-interface)
* [Inputs and Outputs](#inputs-and-outputs)
* [Decomposition into Modules](#decomposition-into-modules)
* [Pseudocode](#pseudocode)
* [Data Structures](#data-structures)

## User Interface

The C-sarSudoku program uses command-line interface. It takes one argument

```console
./sudoku mode
```

where `mode` is either `create` or `solve`.

In `solve` mode the program reads a puzzle from stdin. The
format should follow these requirements:

* The grid is represented as 9 lines of text
* Each line contains 9 integers that range from 0 to 9, separated by a whitespace
* 0 represents a missing number in the grid

## Inputs and Outputs

The inputs are the command-line arguments and for the `solve` mode the puzzle
input is read from stdin either in interactive mode or by piping it from another
source.

The program outputs:

* In `create` mode, a randomized sudoku puzzle (format described in
[user interface](#user-interface)) with at least 40 missing numbers in the grid.
The puzzle is guaranteed to have an unique solution
* In `solve` mode, a filled-in sudoku grid representing the solution to the inputted
puzzle (format described in [user interface](#user-interface))

## Decomposition into Modules

* `sudoku.c` file
    * `main` function which parses and checks command-line arguments, reads input
    from stdin, and initializes other modules
    * `process_input` function which processes the input string and generates the
    data structure storing the grid
    * `print_grid` function which prints the grid to stdout
* `creator` module
    * `generate_grid` function to generate filled out grid
    * `remove_values` function that systematically removes values from the grid
    such that there is one unique solution
* `solver` module
    * `solve_grid` function that tries to fill out the grid. It also checks
    whether a solution is unique
* `common` module
    * `check_consistency` function that checks whether the value in a given
    field is allowed

## Pseudocode

The main module will follow these steps

1. Execute from command line as shown in the user interface
2. Parse the command line arguments
3. Check the argument for mode
    1. If mode is `create`, initialize the `creator` module
    2. If mode is `solve`, process standard input and initialize
    `solver` module
4. Print the output returned by the relevant module

#### Solver

The solver will follow these steps:

1. The solver takes an array of integers representing the unsolved grid
2. While there is a field with 0:
    1. Try filling in a number
    2. Check for consistency
    3. If not consistent, try different number
        1. If all numbers are exhausted, go back to previous field using recursion
    4. If consistent, look for another field with 0
    5. If all fields are filled, copy the solution into solution array
        1. If solution array already contains a solution, return false to indicate
        solution is not unique
3. If solution is found and false wasn't returned, return true

#### Creator

The creator will follow these steps:

1. Initialize new array for the grid
2. While there are unfilled fields
    1. Choose a random integer from 1 to 9 that hasn't been tried yet
    2. Check for consistency
    3. If not consistent, mod by 9 and increment by 1
    4. If consistent, go to next empty field (by recursion)
3. Once the grid is filled, remove value of N fields as follows
    1. Choose random field
    2. Replace with zero
    3. Call solver and see if the puzzle has a unique solution
    4. If there is a unique solution, find next field to empty
    5. If there is not a unique solution, put value back and
    choose different field to empty
4. Return a grid for valid sudoku puzzle

## Data Structures

We don't expect need for any data structures beyond the integer array
representing the sudoku grid.
