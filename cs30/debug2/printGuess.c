/*
 * Filename: printGuess.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines printGuess for pretty-printing the current
 *              player's guess.
 * Date: 4/20/30
 * Sources of help: None.
 */

#include <stdio.h> // printf

#include "hangman.h"

/*
 * Function Name: printGuess()
 * Function Prototype: void printGuess(const char guessBuf[], size_t len);
 * Description: Prints the guess, surrounded by a pretty set of angle brackets.
 * Parameters: guessBuf - guess of the phrase so far
 *             len      - length of the guess buffer
 * Side Effects: The guess is printed out to stdout.
 * Error Conditions: None.
 * Return Value: None.
 */
void printGuess(const char * guessBuf, size_t len) {
  printf(" >> ");
  for (int i = 0; i < len; i++) {
    printf("%c ", guessBuf[i]);
  }
  printf("<<\n\n");
}

