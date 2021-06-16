#
# Makefile for CSE 30 -- PA2
# You should not need to change anything in this file.
#
# XXX DO NOT EDIT
#


HEADERS		= pa2.h pa2Strings.h
C_SRCS		= checkCmd.c checkPrompt.c
EXE_C_SRCS	= main.c $(C_SRCS)
ASM_SRCS	= displayLights.s set.s shift.s toggle.s rotate.s ripple.s \
		  printChar.s clear.s

C_OBJS		= $(C_SRCS:.c=.o)
EXE_C_OBJS	= $(EXE_C_SRCS:.c=.o)
ASM_OBJS	= $(ASM_SRCS:.s=.o)
OBJS		= $(C_OBJS) $(ASM_OBJS)
EXE_OBJS	= $(EXE_C_OBJS) $(ASM_OBJS)

EXE		= pa2
TEST_BINS	= testdisplayLights testcheckCmd testset testclear testtoggle \
		  testshift testrotate testripple


#
# Extra Credit Sources
#

HEADERS_EC	= pa2.h pa2Strings.h pa2EC.h
C_SRCS_EC	= mainEC.c jumbotronEC.c
ASM_SRCS_EC	= displayLightsEC.s

C_OBJS_EC	= $(C_SRCS_EC:.c=.o)
ASM_OBJS_EC	= $(ASM_SRCS_EC:.s=.o)
OBJS_EC		= $(C_OBJS_EC) $(ASM_OBJS_EC)

EXE_EC		= pa2EC


GCC		= gcc
ASM		= $(GCC)
RM		= rm

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
	$(RM) -f mainEC.o test*.o
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(EXE_OBJS)
	@echo ""
	@echo "Compilation Successful!"

#
# Target to create EC program named $(EXE_EC)
#

$(EXE_EC):	$(OBJS_EC) $(OBJS)
	$(RM) -f main.o test*.o
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE_EC) $(LD_FLAGS) $(OBJS_EC) $(OBJS)
	@echo ""
	@echo "Compilation Successful!"

$(C_OBJS):	$(HEADERS)

$(C_OBJS_EC):	$(HEADERS_EC)


clean:
	@echo "Cleaning up project directory ..."
	$(RM) -f *.o $(EXE) $(EXE_EC) core a.out $(TEST_BINS)
	@echo ""
	@echo "Clean."

new:
	make clean
	make

#
# Unit test targets
#
testdisplayLights: test.h pa2.h displayLights.o testdisplayLights.o \
	printChar.o ripple.o rotate.o
	@echo "Compiling testdisplayLights.c"
	$(GCC) $(LD_FLAGS) -o testdisplayLights testdisplayLights.o \
	displayLights.o printChar.o ripple.o rotate.o
	@echo "Compilation Successful!"

testcheckCmd: test.h pa2.h checkCmd.o testcheckCmd.o
	@echo "Compiling testcheckCmd.c"
	$(GCC) $(LD_FLAGS) -o testcheckCmd testcheckCmd.o checkCmd.o
	@echo "Compilation Successful!"

testset: test.h pa2.h set.o testset.o
	@echo "Compiling testset.c"
	$(GCC) $(LD_FLAGS)  -o testset testset.o set.o
	@echo "Compilation Successful!"

testclear: test.h pa2.h clear.o testclear.o
	@echo "Compiling testclear.c"
	$(GCC) $(LD_FLAGS)  -o testclear testclear.o clear.o
	@echo "Compilation Successful!"

testtoggle: test.h pa2.h toggle.o testtoggle.o
	@echo "Compiling testtoggle.c"
	$(GCC) $(LD_FLAGS)  -o testtoggle testtoggle.o toggle.o
	@echo "Compilation Successful!"

testshift: test.h pa2.h shift.o testshift.o
	@echo "Compiling testshift.c"
	$(GCC) $(LD_FLAGS)  -o testshift testshift.o shift.o
	@echo "Compilation Successful!"

testrotate: test.h pa2.h rotate.o testrotate.o shift.o
	@echo "Compiling testrotate.c"
	$(GCC) $(LD_FLAGS)  -o testrotate testrotate.o rotate.o shift.o
	@echo "Compilation Successful!"

testripple: test.h pa2.h ripple.o testripple.o rotate.o displayLights.o \
	printChar.o
	@echo "Compiling testripple.c"
	$(GCC) $(LD_FLAGS)  -o testripple testripple.o ripple.o rotate.o \
	displayLights.o printChar.o
	@echo "Compilation Successful!"

