/*
 * Filename: testevaluateArgs.c
 * Author:   Xinyi Bian
 * Userid:   cs30xfw
 * Description: 
 *           Unit test program to test the function evaluateArgs().
 * Date:     3/5/2018
 * Sources of Help: 
 *          Tutor
 */ 
#include <string.h>
#include <getopt.h>
#include "test.h"
#include "pa4.h"


/*
 * Unit Test for evaluateArgs.c
 *
 * int evaluateArgs(int argc, char * argv[], char ** infile, char ** outfile, 
 *                  char ** rangeStr, OutType * type, int * convert)
 *
 * evaluateArgs will parse the command line arguments. 
 *
 * Returns -1 if error; 0 if no error; 1 if help flag was entered.
 */
void testevaluateArgs() {
  
  extern int optind;

  /* generate our own argv for testing */
  char * argv1[3];
  argv1[0] = "myxd";
  argv1[1] = "-o";
  argv1[2] = "infile";
  int argc = 3;

  /* variables to hold return values */
  char * infile;
  char * outfile;
  char * rangeStr;
  OutType type;
  int convert;

  /* call evaluateArgs and save the return value */
  int result = evaluateArgs(argc, argv1, &infile, &outfile,
                            &rangeStr, &type, &convert);

  /* check the return value */
  TEST( result == 0 );
  /* check that infile was set properly */
  TEST( strncmp(infile, "infile", strlen("infile")) == 0 );
  /* check that type was set properly */
  TEST( type == OCTAL );

  /* now, reset the value of optind before the next call to evaluateArgs */
  /* read the man page for getopt_long to understand why we need this */
  optind = 1;

  /* Extra input */
  char * argv2[4];
  argv2[0] = "myxd";
  argv2[1] = "-c";
  argv2[2] = "infile";
  argv2[3] = "extrafile";
  argc = 4;

  result = evaluateArgs(argc, argv2, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );

  /* undump no args */
  optind = 1;
  char * argv3[4];
  argv3[0] = "myxd";
  argv3[1] = "-u";
  argv3[2] = "infile";
  argc = 3;

  result = evaluateArgs(argc, argv3, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );
  
  /* Missing args for "-r" */
  optind = 1;
  char * argv4[3];
  argv4[0] = "myxd";
  argv4[1] = "-r";
  argv4[2] = "-u";
  argc = 3;

  result = evaluateArgs(argc, argv4, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );
  
  /* No args */
  optind = 1;
  char * argv5[1];
  argv5[0] = "myxd";
  argc = 1;

  result = evaluateArgs(argc, argv5, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );

  /* Too many type flags */
  optind = 1;
  char * argv6[4];
  argv6[0] = "myxd";
  argv6[1] = "-s";
  argv6[2] = "-x";
  argv6[3] = "infile";
  argc = 4;

  result = evaluateArgs(argc, argv6, &infile, &outfile,
                        &rangeStr, &type, &convert);

  TEST( result == -1 );

  /* Invald flags */
  optind = 1;
  char * argv7[4];
  argv7[0] = "myxd";
  argv7[1] = "-p";
  argv7[1] = "-x";
  argv7[2] = "infile";
  argc = 4;

  result = evaluateArgs(argc, argv7, &infile, &outfile,
                        &rangeStr, &type, &convert);

  /* Has both endian flags */
  optind = 1;
  char * argv8[4];
  argv8[0] = "myxd";
  argv8[1] = "-l";
  argv8[2] = "-b";
  argv8[3] = "infile";
  argc = 4;
  
  result = evaluateArgs(argc, argv8, &infile, &outfile,
                        &rangeStr, &type, &convert);
  
  TEST( result == -1 );

  /* Help flag */
  optind = 1;
  char * argv9[5];
  argv9[0] = "myxd";
  argv9[1] = "-c";
  argv9[2] = "-b";
  argv9[3] = "infile";
  argv9[4] = "-h";
  argc = 5;
  
  result = evaluateArgs(argc, argv9, &infile, &outfile,
                        &rangeStr, &type, &convert);
  
  TEST( result == 1 );
  
  /* infile invalid */
  optind = 1;
  char * argv10[3];
  argv10[0] = "myxd";
  argv10[1] = "-x";
  argv10[2] = "nosuchfile";
  argc = 5;
  
  result = evaluateArgs(argc, argv10, &infile, &outfile,
                        &rangeStr, &type, &convert);
  
  TEST( result == -1 );
}

int main() {
  printf("Running tests on evaluateArgs()\n");
  testevaluateArgs();
  printf("Finished running tests on evaluateArgs()\n");
  return 0;
}
