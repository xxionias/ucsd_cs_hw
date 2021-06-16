#
# Makefile for CSE 30 -- PA4
# You should not need to change anything in this file.
#
# XXX DO NOT EDIT
#

HEADERS		= pa4.h pa4Strings.h test.h
C_SRCS		= main.c printBytes.c printStrings.c undump.c evaluateArgs.c \
		  parseRange.c
ASM_SRCS	= convertOrder.s parseLong.s

C_OBJS		= $(C_SRCS:.c=.o)
ASM_OBJS	= $(ASM_SRCS:.s=.o)
OBJS		= $(C_OBJS) $(ASM_OBJS)

EXE		= myxd
TEST_BINS	= testconvertOrder testevaluateArgs testparseLong \
		  testparseRange testprintBytes testprintStrings testundump

GCC		= gcc
ASM		= $(GCC)
RM		= rm

GCC_FLAGS	= -c -g -std=c99 -pedantic -Wall -D__EXTENSIONS__
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
$(EXE): $(OBJS)
	@echo "Linking all object modules ..."
	$(GCC) $(LD_FLAGS) -o $(EXE) $(OBJS)
	@echo ""
	@echo "Compilation Successful!"

$(C_OBJS): $(HEADERS)


clean:
	@echo "Cleaning up project directory ..."
	$(RM) -f *.o $(EXE) core a.out $(TEST_BINS)
	@echo ""
	@echo "Clean."

new:
	make clean
	make

#
# Unit test targets
#
testconvertOrder: test.h pa4.h testconvertOrder.o convertOrder.o
	@echo "Compiling testconvertOrder.c"
	$(GCC) $(LD_FLAGS) -o testconvertOrder testconvertOrder.o convertOrder.o
	@echo "Compilation Successful!"

testevaluateArgs: test.h pa4.h testevaluateArgs.o evaluateArgs.o
	@echo "Compiling testevaluateArgs.c"
	$(GCC) $(LD_FLAGS) -o testevaluateArgs testevaluateArgs.o evaluateArgs.o
	@echo "Compilation Successful!"

testparseLong: test.h pa4.h testparseLong.o parseLong.o
	@echo "Compiling testparseLong.c"
	$(GCC) $(LD_FLAGS) -o testparseLong testparseLong.o parseLong.o
	@echo "Compilation Successful!"

testparseRange: test.h pa4.h testparseRange.o parseRange.o parseLong.o
	@echo "Compiling testparseRange.c"
	$(GCC) $(LD_FLAGS) -o testparseRange testparseRange.o parseRange.o \
	parseLong.o
	@echo "Compilation Successful!"

testprintBytes: test.h pa4.h testprintBytes.o printBytes.o convertOrder.o
	@echo "Compiling testprintBytes.c"
	$(GCC) $(LD_FLAGS) -o testprintBytes testprintBytes.o printBytes.o \
	convertOrder.o
	@echo "Compilation Successful!"

testprintStrings: test.h pa4.h testprintStrings.o printStrings.o
	@echo "Compiling testprintStrings.c"
	$(GCC) $(LD_FLAGS) -o testprintStrings testprintStrings.o printStrings.o
	@echo "Compilation Successful!"

testundump: test.h pa4.h testundump.o undump.o convertOrder.o
	@echo "Compiling testundump.c"
	$(GCC) $(LD_FLAGS) -o testundump testundump.o undump.o convertOrder.o
	@echo "Compilation Successful!"

