/*
 * Filename: main.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Driver for the hangman game program.
 * Date: 4/20/30
 * Sources of help: None.
 */

#include <stdio.h>   // printf, fgets
#include <stdlib.h>

#include <ctype.h>   // isalpha

#include <string.h>  // strlen, strchr
#include <strings.h> // strcasecmp

#include "hangman.h"
#include "utils.h"

/*
 * Function Name: main()
 * Function Prototype: int main(void);
 * Description: Driver for the Hangman game. Provides user interface, handles
 *              user input, keeps track of attempts/win-lose/letters guessed.
 * Parameters: None.
 * Side Effects: Text will be printed to stdout or stderr.
 * Error Conditions: None.
 * Return Value: EXIT_SUCCESS for a non-error exit condition, EXIT_FAILURE
 *               otherwise.
 */
int main(void) {

  char * HANGMAN_PICTURE[] = { ATTEMPTS, NULL };

  char inputBuf[BUFSIZ]; // Temporary buffer for processing user input.
  char answerBuf[MAX_PHRASE_LEN]; // Answer word to guess.
  char guessBuf[MAX_PHRASE_LEN]; // Shows player correct chars and blanks.

  
  int numMistakes = 0; // Keep track of the number of mistakes the user makes.
  int size;            // Length of the guess/answer buffer strings.
  int prompts = 0;     // Keep track of number of prompts printed so far.

  // Print description and wait for the user to input a word/phrase.
  printf(WELCOME_STR);
  printf(INTRO_STR);

  // First, get the answer phrase to guess for from the enemy.
  for (SHOW_PROMPT; fgets(inputBuf, BUFSIZ, stdin); SHOW_PROMPT) {
    prompts++; // Count how many prompts to remove.

    // Clean up input, removing surrounding whitespace and nul-terminating.
    trimWhitespace(answerBuf, inputBuf, MAX_PHRASE_LEN);
    answerBuf[MAX_PHRASE_LEN-1] = 0;
    size = strlen(answerBuf); // Get size of string.

    if (size == 0) {
      printf(ERR_EMPTY_STR);
      continue;
    }

    if (!isValidPhrase(answerBuf, size)) {
      printf(ERR_PHRASE_STR);
      continue;
    }

    break;
  }

  // Stop game if ^D entered.
  if (feof(stdin)) {
    printf(EXIT_STR);
    return EXIT_SUCCESS;
  }

  unlines(prompts * LINES_PER_PROMPT); // Clear lines where enemy was entering.

  printf(INTRO_STR_PLAYER);
  printf(HANGMAN_PICTURE[numMistakes]);

  initGuess(guessBuf, answerBuf, MAX_PHRASE_LEN);
  printGuess(guessBuf, size);

  // Next, play the game with the player, asking for guesses.
  while (numMistakes < MAX_ATTEMPTS) {
    int command;
    char commandBuf[BUFSIZ]; // Holds whole command for processing.
    char commandArg[BUFSIZ]; // Holds the command argument (if any).
    
    for (SHOW_PROMPT; fgets(inputBuf, BUFSIZ, stdin); SHOW_PROMPT) {
      // Change the newline at the end to NUL char.
      trimWhitespace(commandBuf, inputBuf, BUFSIZ);

      command = interpretCommand(commandArg, commandBuf, BUFSIZ);

      // Check command and react appropriately.
      if (command == -1) {
        printf(ERR_BADCMD_STR);
      } else {
        break;
      }
    }

    // Stop game if ^D entered.
    if (feof(stdin)) {
      printf(EXIT_STR);
      return EXIT_SUCCESS;
    }

    int lettersChanged; // Keep track of letters revealed by guess.
    char up; // Set to CASE_MISMATCH if guess was right, but off by case.

    switch (command) {
      case HELP:
        printf(HELP_STR);
        continue;

      case LETTER:
        guessLetter(*commandArg, guessBuf, answerBuf, &lettersChanged, &up);
        break;

      case PHRASE:
        guessPhrase(commandArg, guessBuf, answerBuf, &lettersChanged);
        break;

      case DISPLAY:
        printf(HANGMAN_PICTURE[numMistakes]);
        printGuess(guessBuf, size);
        continue;

      case QUIT:
        printf(QUIT_STR);
        return EXIT_SUCCESS;
    }

    // Guess unchanged.
    if (lettersChanged == 0) {
      numMistakes += 1; // Bad guess, mistake.

      // Tell the player they made a mistake :(
      printf(MISTAKE_STR, MAX_ATTEMPTS - numMistakes);

      // Tell the player they missed the guess by case if they did.
      if (up == CASE_MISMATCH) {
        printf(CASE_MISMATCH_STR);
      }
    } else {
      // Tell player how many letters they revealed if they did.
      printf(REVEAL_STR, lettersChanged);
    }

    printf(HANGMAN_PICTURE[numMistakes]); // Show friend and phrase again.
    printGuess(guessBuf, size);

    // Did they finish?
    if (strcasecmp(guessBuf, answerBuf) == 0) {
      printf(CONGRATS_STR, answerBuf);
      break;
    }
  }

  // Too many mistakes -- they lost :(
  if (numMistakes >= MAX_ATTEMPTS) {
    printf(LOSE_STR, answerBuf);
  }

  return EXIT_SUCCESS;
}

