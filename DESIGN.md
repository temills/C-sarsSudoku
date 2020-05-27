# C-sarSudoku Design

C-sarSudoku program generates and solves sudoku puzzles. Creator creates
sudoku puzzle with a unique solution.

* [User Interface](#user-interface)
* [Inputs and Outputs](#inputs-and-outputs)
* [Decomposition into Modules](#decomposition-into-modules)

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






