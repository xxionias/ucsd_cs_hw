/* Filename:       jumbotronEC
 * Author:         Xinyi Bian
 * Userid:         cs30xfw
 * Description:    jumbotronEC prints the light pattern in the jumboFile to 
 *                 the screen. Each line in a jumbotron file is two numbers
 *                 that represent valid light banks. It will read each line 
 *                 of the jumbotron file and parse the lines in order to get
 *                 the light patterns they represent.
 * Date:           2/14/2018
 * Source of help: CSE tutor
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa2EC.h"
#include "pa2.h"
#include "pa2Strings.h"

/* Function Name:
 * Function prototype:  void jumbotronEC( unsigned int lightBank[]. FILE
 *                      * jumboFile )
 * Description:         The function reads each line of the jumbotron 
 *                      file and parse the lines in order to get the light
 *                      patterns they represent.
 * Return Value:        none
 */
void jumbotronEC( unsigned int lightBank[], FILE * jumboFile ) {

  char buf[BUFSIZ] = { 0 };
  
  // Continuously reading the lines from the jumboFile
  while( fgets( buf, BUFSIZ, jumboFile ) != NULL ) {
    char * wordptr;
    char * endptr;
    
    // Parse the first pattern
    wordptr = strtok( buf, TOKEN_SEPARATORS );
    
    // Convert it to an integer 
    int a =strtoul( wordptr, &endptr, 0 );

    // Parse the second pattern
    wordptr = strtok( NULL, TOKEN_SEPARATORS );

    // Convert it to an integer
    int b= strtoul( wordptr, &endptr, 0 );
    
    // Set the lightBank to be printed
    set(lightBank, a, b);

    // Make function call to displaylightsEC 
    displayLightsEC( lightBank, ON_CHAR, OFF_CHAR );
  
    // Clear the lightBank[]
    clear( lightBank, 0xffffffff, 0xffffffff );

  }
}
