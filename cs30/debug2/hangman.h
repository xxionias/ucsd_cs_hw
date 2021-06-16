/*
 * Filename: hangman.h
 * Author: Bugs Bunny
 * UserId: cs30x420
 * Description: Declares function prototypes and constants for the hangman game.
 * Date: 4/20/30
 * Sources of help: None.
 */
#ifndef HANGMAN_H /* Macro Guard */
#define HANGMAN_H

/*** XXX: DO NOT CHANGE ANYTHING IN THIS FILE ! ***/

#include <ctype.h>   // isalpha, isspace, ispunct
#include <string.h>

/* Function prototypes for Hangman */
int interpretCommand(char * commandArg, char * commandStr, size_t len);
void trimWhitespace(char * dest, char * str, size_t len);
void guessLetter(char letter, char * guessBuf, char * answerBuf, int * count,
                 char * caseDiff);
void guessPhrase(const char * phrase, char * guessBuf, const char * answerBuf,
                 int * count);
int isValidPhrase(const char * str, size_t len);
void initGuess(char * guessBuf, const char * answerBuf, size_t len);
void printGuess(const char * guessBuf, size_t len);

/* Strings */
#define WELCOME_STR "Welcome to Hangman!\n"
#define INTRO_STR "Type in a word for someone to guess, then hit ENTER.\n"
#define INTRO_STR_PLAYER "Your worst enemy is about to hang your friend! "\
                         "You must guess the mystery word to save them!\n"\
                         "Unfortunately, you can only make 6 mistakes... "\
                         "(yep, no extra ears, hair, mustaches, etc.).\n\n"\
                         "Here we go! It's up to you now!\n"

#define MISTAKE_STR "\nYou didn't reveal any letters :(\n"\
                    "You have %d mistakes left.\n"
#define CASE_MISMATCH_STR "Your guess was off by case!\n"
#define REVEAL_STR "\nNice work, you revealed %d blanks!\n"
#define CONGRATS_STR "Congratulations! You've guessed the phrase, which was "\
                     "\"%s\".\n"
#define LOSE_STR "You lost :(\n"\
                 "The phrase was \"%s\".\n"\
                 "Better luck next time!\n"

#define QUIT_STR "Bye!\n"

#define ERR_BADCMD_STR "\nUnrecognized command format. See 'help' for "\
                       "details.\n\n"
#define ERR_EMPTY_STR  "Please enter a valid string.\n"
#define ERR_PHRASE_STR "Your phrase should contain only alphabetical "\
                       "characters and punctuation.\n"

#define EXIT_STR "^D\n"

#define HELP_STR "\nCommands:\n"\
                 "  letter <CHAR>\t\tguess a letter in the phrase\n"\
                 "  phrase <WORDS...>\tguess the whole phrase\n"\
                 "  display\t\tcheck up on your friend :(\n"\
                 "  help\t\t\tdisplay this help message\n"\
                 "  quit\t\t\tend this game, losing your friend\n\n"

#define PROMPT_STR "hangman> "
#define SHOW_PROMPT (printf(PROMPT_STR))
#define LINES_PER_PROMPT 2

/*
 * Constants for guessLetter to indicate case matching.
 */
#define CASE_MATCH    0x20
#define CASE_MISMATCH 0x10

/*
 * Constants and strings defined for matching valid commands
 * Constants are indices of the commands in the commands array
 */
#define HELP 0
#define LETTER 1
#define PHRASE 2
#define DISPLAY 3
#define QUIT 4

#define HELP_CMD "help"
#define LETTER_CMD "letter"
#define PHRASE_CMD "phrase"
#define DISPLAY_CMD "display"
#define QUIT_CMD "quit"

#define DELIM_CHARS " \t"

/*
 * Constants bounding gameplay.
 */
#define MAX_ATTEMPTS   6  // Maximum number of guess attempts.
#define MAX_PHRASE_LEN 40 // Maximum number of chars allowed in a phrase.


/*
 * Map the commands strings to indexes for easy association when parsing
 * the commands string to the command.
 */
#define COMMANDS HELP_CMD, LETTER_CMD, PHRASE_CMD, DISPLAY_CMD, QUIT_CMD

/* Define constants for ease of readability */
#define FALSE 0
#define TRUE 1

#define ATTEMPT_0 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t======   \n"

#define ATTEMPT_1 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||    O"\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t======   \n"

#define ATTEMPT_2 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||   \\O"\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t======   \n"

#define ATTEMPT_3 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||   \\O/"\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t======   \n"

#define ATTEMPT_4 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||   \\O/"\
                  "\n\t  ||    |"\
                  "\n\t  ||     "\
                  "\n\t  ||     "\
                  "\n\t======   \n"

#define ATTEMPT_5 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||   \\O/"\
                  "\n\t  ||    |"\
                  "\n\t  ||     \\"\
                  "\n\t  ||     "\
                  "\n\t======   \n"

#define ATTEMPT_6 "\n\t  ||====="\
                  "\n\t  ||    |"\
                  "\n\t  ||   \\O/"\
                  "\n\t  ||    |"\
                  "\n\t  ||   / \\"\
                  "\n\t  ||     "\
                  "\n\t======   \n"

/*
 * Map the attempt strings to indexes for easy association when
 * displaying the hangman.
 */
#define ATTEMPTS ATTEMPT_0, ATTEMPT_1, ATTEMPT_2, ATTEMPT_3, \
                 ATTEMPT_4, ATTEMPT_5, ATTEMPT_6

#endif
