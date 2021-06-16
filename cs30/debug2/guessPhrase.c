/*
 * Filename: guessPhrase.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines guessPhrase for applying a whole phrase guess to the
 *              guess buffer.
 * Date: 4/20/30
 * Sources of help: None.
 */

#include "hangman.h"

/*
 * Function Name: guessPhrase()
 * Function Prototype: void guessPhrase(char * phrase, char guessBuf[],
 *                                      char answerBuf[], int * count);
 * Description: Applies a guess `phrase` to the guessBuf, based on what letters
 *              are in answerBuf. The count of matched letters is saved into
 *              the address pointed to by `count`.
 * Parameters: phrase    - the phrase that was guessed
 *             guessBuf  - guess of the phrase so far
 *             answerBuf - the actual phrase
 *             count     - address to store number of revealed letters
 * Side Effects: count is set. guessBuf may be modified.
 * Error Conditions: None.
 * Return Value: None.
 */
void guessPhrase(const char * phrase, char * guessBuf, const char * answerBuf,
                 int * count) {

  // If phrase is an exact match, set count and fill guessBuf.
  if (!strcmp(phrase, answerBuf)) {
    *count = strlen(phrase);
    strcpy(guessBuf, answerBuf);
  } else {
    *count = 0; // Not a match :(
  }
}

