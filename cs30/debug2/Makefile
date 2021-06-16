#
# Makefile for CSE 30 -- debug2
#

HEADERS		= utils.h hangman.h

C_SRCS		= main.c interpretCommand.c trimWhitespace.c utils.c \
			guessPhrase.c isValidPhrase.c printGuess.c

ASM_SRCS	= guessLetter.s initGuess.s

C_OBJS		= $(C_SRCS:.c=.o)

ASM_OBJS	= $(ASM_SRCS:.s=.o)

EXE_OBJS    = $(C_OBJS) $(ASM_OBJS)

EXE         = hangman

#
# Relevant man pages:
#
# man gcc
# man as
#

GCC		= gcc
ASM		= $(GCC)

GCC_FLAGS	= -c -g -Wall -D__EXTENSIONS__ -std=c99
ASM_FLAGS	= -c -g
LD_FLAGS	= -g -Wall

#
# Standard rules
#

.s.o:
	@echo "Assembling each assembly source file separately ..."
	$(ASM) $(ASM_FLAGS) $<
	@echo ""

.c.o:
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE):	$(EXE_OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(EXE_OBJS)
	@echo ""
	@echo "Compilation Successful!"

$(C_OBJS):      $(HEADERS)


clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o $(EXE) core a.out
	@echo ""
	@echo "Clean."

new:
	make clean
	make
