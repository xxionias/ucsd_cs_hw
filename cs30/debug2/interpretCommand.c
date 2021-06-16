/*
 * Filename: interpretCommand.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines interpretCommand for parsing commands written in the
 *              hangman game.
 * Date: 4/20/30
 * Sources of help: None.
 */

#include <string.h>

#include "hangman.h"

/*
 * Function Name: interpretCommand()
 * Function Prototype: int interpretCommand(char commandArg[],
 *                                          char commandStr[], size_t len);
 * Description: Interprets a command string, determining which command was
 *              used, as well as parsing the command argument, if there is one.
 * Parameters: commandArg - buffer that will be filled with the argument to the
 *                          command in commandStr, if any
 *             commandStr - buffer containing the full command to be parsed
 *             len        - length of the commandArg buffer
 * Side Effects: commandArg and commandStr will be modified.
 * Error Conditions:
 *    - commandStr has no command
 *    - command at the beginning of the string does not exist
 *    - no-arg command has non-space characters following it
 *    - one-arg command has no arg
 *    - one-arg command uses invalid chars for guess
 *    - one-arg command that takes a single char has a string of chars following
 * Return Value: The index of the command used (as defined in hangman.h).
 *               -1 if an error occurred.
 */
int interpretCommand(char * commandArg, char * commandStr, size_t len) {

  const char * const commands[] = { COMMANDS, NULL };

  // Begin tokenizing the commandStr.
  char * tok = strtok(commandStr, DELIM_CHARS);

  if (tok == NULL) return -1; // Err: string has no tokens.

  // Find the index of the command.
  int i = 0;
  while (commands[i] != NULL && strcmp(commands[i], tok) != 0) {
    i++;
  }

  if (commands[i] == NULL) return -1; // Err: it could not be found.

  // Get rest of string.
  tok = strtok(NULL, "");

  switch (i) {
    // No-arg commands.
    case HELP:
    case QUIT:
    case DISPLAY:
      if (tok != NULL) return -1; // Err: command has extra arg.
      break;

    // One-arg commands.
    case LETTER:
    case PHRASE:
      if (tok == NULL) return -1; // Err: command needs but has no arg.

      // Clean whitespace before checking validity of argument.
      trimWhitespace(commandArg, tok, len);

      // Get length of argument to validate.
      int argLen = strlen(commandArg);

      if (!isValidPhrase(commandArg, argLen)) return -1; // Err: invalid guess.
      if (i == LETTER && argLen != 1) return -1; // Err: must be single char.

      break;

    // Not a command.
    default:
      return -1;
  }

  // Set return values.
  return i;
}
