/* 
 * Filename:  main.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            Main driver for PA1, will print out a diamond with four 
 *            parameters.
 * Date:      1.30.2018
 * Sources of help:
 *            course website
 */
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa1.h"
#include "pa1Strings.h"

#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define NL "\n"

/* 
 * Function Name:       main()
 * Function Prototype:  int main( int argc, char * argv[] )
 * Description:         Driver for PA1, will first perform input
 *                      checking by parsing the commandline 
 *                      arguments and checking for erros. If all
 *                      inputs are valid, it will call display-
 *                      Diamond(). If any of the input checks fail,
 *                      it will print the corresponding errors, the
 *                      usage and then exit.
 * Return Value:        Return EXIT_SUCCESS if all inputs are valid.
 *                      Return EXIT_FAILURE if error occurs.
 */
int main( int argc, char * argv[] ) {
  int errCount = ZERO;
  
  // First check that the user entered the correct number of command
  // line arguments. 
  if( argc != FIVE) {

    // If not, print the STR_USAGE and return EXIT_FAILURE.
    fprintf( stderr, STR_USAGE, argv[ZERO], WIDTH_MIN, WIDTH_MAX, 
      HEIGHT_MIN, HEIGHT_MAX, ASCII_MIN, ASCII_MAX, ASCII_MIN, 
      ASCII_MAX );
    return EXIT_FAILURE; }
  
  // set the global variable errno to 0.
  errno = ZERO;
  char * endptr;
  char des[BUFSIZ];
  long wid, hei;
  
  // Use strtol() to convert the diamond width to a long.
  wid = strtol( argv[ONE], &endptr, BASE );

  // Check if there is error converting to long.
  if( errno != ZERO ) {

    // Use snprintf() to build the error string using 
    // STR_ERR_CONVERTING.
    snprintf( des, BUFSIZ, STR_ERR_CONVERTING, STR_WIDTH, argv[ONE], 
                                                           BASE );
    
    // Call perror(), passing the string as a parameter.
    perror( des );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; } 
 
  // Check if width contains non-numerical characters.
  else if( *endptr != '\0' ) {

    // Print the STR_ERR_NOT_INT error messages.
    fprintf( stderr, STR_ERR_NOT_INT, STR_WIDTH, argv[ONE] );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; }

  // Check if width is not within range.
  else if( wid < WIDTH_MIN || wid > WIDTH_MAX ) {
    
    // Print the STR_ERR_NUM_RANGE error message.
    fprintf( stderr, STR_ERR_NUM_RANGE, STR_WIDTH, wid, WIDTH_MIN, 
                                                         WIDTH_MAX );
    fprintf( stderr, NL ); 
    return EXIT_FAILURE; }

  // Check if width is odd.
  else if( isOdd( wid ) == ZERO ) {
    
    // Print the STR_ERR_ODD error message.
    fprintf( stderr, STR_ERR_ODD, STR_WIDTH, wid );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; }
  
  // Set the global variable errno to 0.
  errno = ZERO;

  // Use strtol() to convert the diamond height to a long.
  hei = strtol( argv[TWO], &endptr, BASE );
  
  //Check if there is error converting to long.
  if( errno != ZERO) {

    // Build the error string using STR_ERR_CONVERTING.
    snprintf( des, BUFSIZ, STR_ERR_CONVERTING, STR_HEIGHT, argv[TWO], 
                                                            BASE );
    fprintf( stderr, NL ); 
    
    // Pass the string as a paramter.
    perror( des );
    
    // Input invalid.
    errCount = ONE; }

  // Check if height contains non-numerical characters.
  else if( *endptr != '\0' ) {
    fprintf( stderr, STR_ERR_NOT_INT, STR_HEIGHT, argv[TWO] );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; }

  // Check if height is within range.
  else if( hei < HEIGHT_MIN || hei > HEIGHT_MAX ) {
    fprintf( stderr, STR_ERR_NUM_RANGE, STR_HEIGHT, hei, HEIGHT_MIN, 
                                                      HEIGHT_MAX );
    fprintf( stderr, NL ); 
    return EXIT_FAILURE; }

  // Check if heigh is odd.
  else if( isOdd( hei ) == ZERO ) {
    fprintf( stderr, STR_ERR_ODD, STR_HEIGHT, hei );
    fprintf( stderr, NL ); 
    return EXIT_FAILURE; }
  
  // Check if height >= width.
  if( hei > wid || hei == wid) {
    fprintf( stderr, STR_ERR_HEIGHT_LESS_THAN_WIDTH, hei, wid );
    fprintf( stderr, NL ); } 
  
  // Extract the first character from the border_char argument.
  char borderChar = argv[THREE][0];
  
  // Check if border_char is a valid single character.
  if( strlen( argv[THREE] ) != ONE ) {
    fprintf( stderr, STR_ERR_SINGLE_CHAR, STR_BORDER_CHAR, 
    argv[THREE] );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; }
  
  // Check if char is within range.
  else if( borderChar < ASCII_MIN || borderChar > ASCII_MAX ) {
    fprintf(stderr, STR_ERR_ASCII_RANGE, STR_BORDER_CHAR, 
                          borderChar, ASCII_MIN, ASCII_MAX );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; }

  // Extract the first character from the diamond_char argument.
  char diamondChar = argv[FOUR][0];
  
  // Check if diamond_char is a valid single character.
  if( strlen( argv[FOUR] ) != ONE ) {
    fprintf( stderr, STR_ERR_SINGLE_CHAR, STR_DIAMOND_CHAR, 
                                              argv[FOUR] );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE; }

  // Check if char is within range.
  else if( diamondChar < ASCII_MIN || diamondChar > ASCII_MAX ) {
    fprintf( stderr, STR_ERR_ASCII_RANGE, STR_DIAMOND_CHAR, 
                            diamondChar, ASCII_MIN, ASCII_MAX );
    fprintf( stderr, NL ); 
    
    // Input invalid,
    errCount = ONE; }

  // Check if no errors and border_char and diamond_char different,
  if( errCount == ZERO && diamondChar == borderChar ) {
    fprintf( stderr, STR_ERR_BORDER_DIAMOND_DIFF, borderChar, 
                                                diamondChar );
    fprintf( stderr, NL ); 
    
    // Input invalid.
    errCount = ONE;
    return EXIT_FAILURE; }
  
  // If no errors were encountered, draw the diamond pattern.
  if( errCount == ZERO ) {
    displayDiamond( wid, hei, borderChar, diamondChar );
    return EXIT_SUCCESS; }
  
  // If errors were encountered, return EXIT_FAILURE.
  return EXIT_FAILURE;
}
