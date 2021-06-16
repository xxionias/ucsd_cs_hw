#
# Makefile for CSE 30 -- debug1
#

HEADERS		= debug.h

C_SRCS		= main.c

ASM_SRCS	= reverse.s swapChars.s findEnd.s

C_OBJS		= main.o

ASM_OBJS	= reverse.o swapChars.o findEnd.o

EXE_OBJS    = $(C_OBJS) $(ASM_OBJS)

EXE         = reverseString

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
