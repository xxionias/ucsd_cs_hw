/*
 * Filename: utils.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines some utility functions for the hangman game.
 * Date: 4/20/30
 * Sources of help: None.
 */

/*** XXX: DO NOT CHANGE ANYTHING IN THIS FILE ! ***/

#include <stdio.h> // printf

#include "utils.h"

/*
 * Function Name: unline()
 * Function Prototype: void unline();
 * Description: Removes one line of output from stdout.
 * Parameters: None.
 * Side Effects: One line of output is removed from the stdout stream.
 * Error Conditions: None.
 * Return Value: None.
 */
void unline() {
  printf("\033[F\033[J");
}

/*
 * Function Name: unlines()
 * Function Prototype: void unlines(unsigned int n);
 * Description: Removes a variable number of lines of output from stdout.
 * Parameters: None.
 * Side Effects: Output on the stdout stream may change.
 * Error Conditions: None.
 * Return Value: None.
 */
void unlines(unsigned int n) {
  while (n-- > 0)
    unline();
}
