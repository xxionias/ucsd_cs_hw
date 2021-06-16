/*
 * Filename: isValidPhrase.c
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Defines isValidPhrase for checking that the user inputted phrase
 *              contains the right characters.
 * Date: 4/20/30
 * Sources of help: None.
 */

#include <string.h>

#include "hangman.h"

/*
 * Function Name: isValidPhrase()
 * Function Prototype: int isValidPhrase(const char * str, size_t len);
 * Description: Checks that the given string contains only alpha chars,
 *              space chars, or punctuation chars. Also checks that the string
 *              contains *at least* one alpha char.
 * Parameters: str - string to validate
 *             len - length of str
 * Side Effects: None.
 * Error Conditions: None.
 * Return Value: TRUE if the string is valid. FALSE otherwise.
 */
int isValidPhrase(const char * str, size_t len) {
  int alphaCount = 0;
  for (int i = 0; i < len; i++) {
    char c = str[i];

    if (isalpha(c)) {
      alphaCount++;
    }

    if (!isalpha(c) && !isspace(c) && !ispunct(c)) {
      return FALSE;
    }
  }

  return alphaCount > 0;
}
