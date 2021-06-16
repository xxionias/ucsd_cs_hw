/* Filename:  mainEC.c
 * Author:    Xinyi Bian
 * Userid:    cs30xfw
 * Description:
 *            Main Driver for PA2, will initialize the bank of lights as an
 *            array of two 43-bit unsigned ints, where all the lights are
 *            initialized 0. Either read from a valid file or execute inter-
 *            actively with user's input. Prompt user when input is invalid.
 * Date:      2/13/2018
 * Source of help:
 *           CSE tutor
 */
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pa2.h"
#include "pa2EC.h"
#include "pa2Strings.h"

#define NL "\n"
#define INT 4

/* Function Name:       main()     
 * Function Prototype:  int main( int argc, char * argv[] )
 * Description:         Initialize the bank of lights as an array of two 32-
 *                      bit unsigned ints; Determine the input source: if a
 *                      filename was entered on the command line or prompt the
 *                      user and execute their commands.
 * Return Value:        Return EXIT_SUCCESS on success;
 *                      Return EXIT_FAILURE on failure.
 */
int main( int argc, char * argv[] ) {

  // Initialize the bank of lights as an array of two 32-bit unsigned bits
  unsigned int lightBank[2];
  lightBank[0] = 0x00000000;
  lightBank[1] = 0x00000000;

  // Initialize the array of command strings 
  const char * const commands[] = { COMMANDS_EC, NULL };

  // Initialize the following variables with the main prompt
  FILE * inFile = stdin;
  char des[BUFSIZ];
  char buf[BUFSIZ] = { 0 };
  short prompt = TRUE;
  // Turn off buffering in stdout 
  (void) setvbuf( stdout, NULL, _IONBF, 0 );

  // If too many command line arguments were entered;
  if (argc > 2) {
    fprintf( stderr, STR_USAGE_MSG, argv[0] );
    return EXIT_FAILURE; }

  // Determine the input source
  if ( argc == 2 ) {
    errno = 0;

    // If a filename was entered on the command line
    // Open the file in read mode 
    inFile = fopen( argv[1], "r" );
      
    // File couldn't be opened
    if ( errno != 0 ) {
      perror( argv[1] );
  
      return EXIT_FAILURE; 
    }

    // File was successfully opened
    else { prompt = FALSE; }
  } 
  
  else {
    // Determines whether prompt should be printed or not
    prompt = checkPrompt();
  }

  // Display the initial bank of lights 
  displayLights( lightBank );

  // Main loop to prompt the user and execute their commands
  for( DISPLAY_PROMPT; fgets( buf, BUFSIZ, inFile ) != NULL; DISPLAY_PROMPT ) {
    
    char * wordptr;
    char * endptr;
    
    // First determine which command the user entered
    wordptr = strtok( buf, TOKEN_SEPARATORS );

    // If no seperator tokens were found, reprompt the user
    if ( wordptr == NULL ) { continue; }

    // Check to see if the command entered was valid
    int cmd_rtn = checkCmd( wordptr, commands );
    if ( cmd_rtn == -1 ) {
      fprintf( stderr, STR_BAD_CMD );
      continue;
    }
    
    // Handle "jumbotron"
    if ( cmd_rtn == JUMBOTRON ) {
      FILE * jumboFile;
      
      // First determine if there is argument file
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      
      // Print error messages if there is no argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue;
      }
      
      // Determine if the file is valid
      errno = 0;
      jumboFile = fopen( wordptr, "r" ); 
      
      // Print error messages if file cannot be opened
      if ( errno ) {
        fprintf( stderr, STR_BAD_FILE, wordptr );
        continue;
      }
      
      // Determine if there is extra argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      
      // Print error mesaages if there is extra argument
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue;
      }
      
      // Make function call to jumbotronEC if input is valid 
      jumbotronEC( lightBank, jumboFile );
      
      // Close file after opening
      fclose( jumboFile );
    }
        
    // Handle "help" 
    if ( cmd_rtn == HELP ) {
      fprintf( stderr, STR_HELP_MSG_EC ); 
      continue; 
    }

    // Handle "quit"
    if ( cmd_rtn == QUIT ) { return EXIT_SUCCESS; }

    // Handle "set"
    if ( cmd_rtn == SET ) {
      errno = 0;
      long pattern0;
      long pattern1;
      
      // Determine the argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );

      // Check to see if there is a first argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue; 
      }

      // Convert the next argument into an unsigned int
      pattern0 = strtoul( wordptr, &endptr, 0 );
     
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }
      
      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue; 
      }  

      // Determine the second argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
     
      // Check if there is a second argument
      if ( !wordptr ) {
        fprintf( stderr, STR_TWO_ARGS_REQ );
        continue; 
      }
      
      // Convert the next argument into an unsigned int
      errno = 0;
      pattern1 = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue;
      }

      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue;
      }  
      
      // Handle extra arguments
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue; 
      }

      // Make function call to set.s
      set( lightBank, pattern0, pattern1 );
      
      // Display the lights
      displayLights( lightBank );
    }

    // Handle "clear"
    if (cmd_rtn == CLEAR ) {
      errno = 0;
      long pattern0;
      long pattern1;
      
      // Determine the argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );

      // Check to see if there is a first argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue; 
      }

      // Convert the next argument into an unsigned int
      pattern0 = strtoul( wordptr, &endptr, 0 );
     
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }
      
      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue;
      }  
      
      // Determine the second argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      
      // Check if there is a second argument
      if ( !wordptr ) {
        fprintf( stderr, STR_TWO_ARGS_REQ );
        continue; 
      }
      
      // Convert the next argument into an unsigned int
      errno = 0;
      pattern1 = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }

      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue; 
      }  

      // Handle extra arguments
      wordptr = strtok( NULL, TOKEN_SEPARATORS );  
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue; 
      }

      // Make function call to clear.s
      clear( lightBank, pattern0, pattern1 );
      
      // Display the lights
      displayLights( lightBank );
    }
    
    // Handle "toggle"
    if (cmd_rtn == TOGGLE ) {
      errno = 0;
      long pattern0;
      long pattern1;
      
      // Determine the argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );

      // Check to see if there is a first argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue; 
      }

      // Convert the next argument into an unsigned int
      pattern0 = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }
      
      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue; 
      }  

      // Determine the second argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
     
      // Check if there is a second argument
      if ( !wordptr ) {
        fprintf( stderr, STR_TWO_ARGS_REQ );
        continue; 
      }
      
      // Convert the next argument into an unsigned int
      errno = 0;
      pattern1 = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }

      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue;
      }  

      // Handle extra arguments
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue; 
      }

      // Make function call to toggle.s
      toggle( lightBank, pattern0, pattern1 );
      
      // Display the lights
      displayLights( lightBank );
    }

    // Handle "shift"
    if (cmd_rtn == SHIFT ) {
      errno = 0;
      int shiftCnt;
      
      // Determine the argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );

      // Check to see if there is a first argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue; 
      }

      // Convert the next argument into an unsigned int
      shiftCnt = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }
      
      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue; 
      }  

      // Handle extra arguments
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue; 
      }

      // Make function call to shift.s
      shift( lightBank, shiftCnt );

      // Display the lights
      displayLights( lightBank );
    }

    // Handle "rotate"
    if (cmd_rtn == ROTATE ) {
      errno = 0;
      int rotateCnt;
      
      // Determine the argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );

      // Check to see if there is a first argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue; 
      }

      // Convert the next argument into an unsigned int
      rotateCnt = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }
      
      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue; 
      }  

      // Handle extra arguments
      wordptr = strtok( NULL, TOKEN_SEPARATORS ); 
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue; 
      }

      // Make function call to rotate
      rotate( lightBank, rotateCnt );

      // Display the lights
      displayLights( lightBank );
    }

    // Handle "ripple"
    if (cmd_rtn == RIPPLE ) {
      errno = 0;
      int rippleCnt;
      
      // Determine the argument
      wordptr = strtok( NULL, TOKEN_SEPARATORS );

      // Check to see if there is a first argument
      if ( !wordptr ) {
        fprintf( stderr, STR_ARGS_REQ );
        continue; 
      }

      // Convert the next argument into an unsigned int
      rippleCnt = strtoul( wordptr, &endptr, 0 );
      
      // Check if the argument contained non-numerical characters
      if ( *endptr ) {
        fprintf( stderr, STR_STRTOLONG_NOTINT, wordptr );
        continue; 
      }
      
      // Check if the argument was too large to be converted
      if ( errno ) {
        snprintf( des, BUFSIZ, STR_STRTOLONG_CONVERTING, wordptr, 0 );
        perror( des );
        fprintf( stderr, "\n" );
        continue; 
      }  

      // Handle extra arguments
      wordptr = strtok( NULL, TOKEN_SEPARATORS );
      if ( wordptr ) {
        fprintf( stderr, STR_EXTRA_ARG, wordptr );
        continue; 
      }
      
      // Make function call to ripple.s
      ripple( lightBank, rippleCnt );
    }
  }

  // Close the input file
  fclose( inFile );

  return EXIT_SUCCESS;
}
