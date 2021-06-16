/*
 * File: pa3.h
 * Description: Header file that contains function prototypes and
 *              constants.
 *
 * XXX Only add constants to this file at the bottom.
 * DO NOT EDIT FUNCTION PROTOTYPES OR PREDEFINED CONSTANTS
 *
 */
#ifndef PA3_H      /* Macro Guard */
#define PA3_H

#include <stdio.h>


// For evaluating flags (command line arguments)
#define ARG_STR "d:a:h"
#define FLAG_DICTIONARY_FILE 'd'
#define FLAG_ANAGRAM_FILE    'a'
#define FLAG_HELP            'h'

// Default dictionary/anagram files, anagram file extension
#define ANAGRAM_FILE_EXT        ".ao"
#define DEFAULT_DICTIONARY_FILE "/usr/share/dict/words"
#define DEFAULT_ANAGRAM_FILE    "anagramPrey"


#define MAX_WORD_LEN 40

struct Anagram {
  char word[MAX_WORD_LEN];
  char key[MAX_WORD_LEN];
};


// C function prototypes
int evaluateFlags( int argc, char * argv[], char ** dictionaryFile,
                   char ** anagramFile );
int spawnAnagramArray( char * dictionaryFile, struct Anagram ** anagramsArray );
void spawnKey( char * key, const char * const word, int keyLen );
int spawnAnagramFile( char * anagramFile, struct Anagram * anagramsArray, 
                      int numAnagrams );
int readAnagramFile( char * anagramFile, struct Anagram ** anagramsArray );
void huntForAnagrams( struct Anagram * anagramsArray, int numAnagrams );

// Assembly function prototypes
void spawnAnagram( char const * originalWord, struct Anagram * anagram );
int compareChar( const void * p1, const void * p2 );
int compareAnagram( const void * p1, const void * p2 );
int compareKey( const void * p1, const void * p2 );
void printUsage( FILE * stream, const char * const usageStr, 
                 const char * const progName );


// TODO: Add any extra constants after this line
#define DISPLAY_PROMPT ( (void) printf( STR_USER_PROMPT ) ) 


#endif /* PA3_H */
