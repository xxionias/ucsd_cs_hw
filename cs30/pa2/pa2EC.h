/*
 * File: pa2EC.h
 * Description: Header file that contains function prototypes and
 *              constants for the EC.
 *
 * XXX Only add constants to this file at the bottom.
 * DO NOT EDIT FUNCTION PROTOTYPES OR PREDEFINED CONSTANTS
 *
 */
#ifndef PA2EC_H   /* Macro Guard */
#define PA2EC_H

#include <stdio.h>
#include "pa2.h"

/* Local function prototypes for PA2 EC written in C */
void jumbotronEC( unsigned int lightBank[], FILE * jumboFile);

/* Local function prototypes for PA2 EC written in Assembly */
void displayLightsEC( const unsigned int lightBank[], 
                      char onChar, char offChar );

/*
 * Constants and strings defined for matching valid EC commands
 * Constants are indices of the commands in the command array
 */
#define JUMBOTRON 8
#define JUMBOTRON_CMD "jumbotron"

/*
 * Map the commands strings to indexes for easy association when parsing
 * the commands string to the command.
 */
#define COMMANDS_EC SET_CMD, CLEAR_CMD, TOGGLE_CMD, SHIFT_CMD, ROTATE_CMD, \
             RIPPLE_CMD, HELP_CMD, QUIT_CMD, JUMBOTRON_CMD

/*
 * Chars to print for EC
 */
#define ON_CHAR '#'
#define OFF_CHAR ' '


/* 
 * Error message used in EC
 */
#define STR_BAD_FILE "\n\tCould not open jumbotron file: %s\n\n"

#define STR_HELP_MSG_EC "The available commands are:\n"\
  "\tset    bank0BitPattern bank1BitPattern\n"\
  "\tclear  bank0BitPattern bank1BitPattern\n"\
  "\ttoggle bank0BitPattern bank1BitPattern\n"\
  "\tshift  shiftCount\n"\
  "\trotate rotateCount\n"\
  "\tripple rippleCount\n"\
  "\tjumbotron filename\n"\
  "\thelp\n"\
  "\tquit\n"


#endif /* PA2EC_H */
