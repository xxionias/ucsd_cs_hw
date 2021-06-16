/*
 * Filename: trimWhitespace.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines trimWhitespace for cleaning up input strings from
 *              the user.
 * Date: 4/20/30
 * Sources of help: None.
 */

#include "hangman.h"

/*
 * Function Name: trimWhitespace()
 * Function Prototype: void trimWhitespace(char dest[], char str[], size_t len);
 * Description: Removes leading and trailing whitespace from a string.
 * Parameters: dest - destination buffer for trimmed string
 *             str  - source string to trim
 *             len  - length of dest
 * Side Effects: dest and str will be modified.
 * Error Conditions: None.
 * Return Value: None.
 */
void trimWhitespace(char * dest, char * str, size_t len) {
  char * end;

  while (isspace(*str)) str++; // Advance to front of input.

  end = &str[strlen(str) - 1];

  while (end > str && isspace(*end)) end--; // Find end of input.

  end[1] = '\0'; // Nul-terminate the end of input.

  strncpy(dest, str, len); // Copy trimmed string into dest buffer.
}
