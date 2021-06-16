#
# Makefile for CSE 30 -- PA3
# You should not need to change anything in this file.
#
# XXX DO NOT EDIT
#

HEADERS		= pa3.h pa3Strings.h test.h
SPAWN_C_SRCS	= spawnAnagramMain.c evaluateFlags.c spawnAnagramArray.c \
		  spawnKey.c spawnAnagramFile.c pa3Globals.c
SPAWN_ASM_SRCS	= spawnAnagram.s compareChar.s printUsage.s
HUNT_C_SRCS	= huntAnagramMain.c readAnagramFile.c huntForAnagrams.c \
		  spawnKey.c pa3Globals.c
HUNT_ASM_SRCS	= compareAnagram.s spawnAnagram.s compareChar.s \
		  printUsage.s compareKey.s

SPAWN_C_OBJS	= $(SPAWN_C_SRCS:.c=.o)
SPAWN_ASM_OBJS	= $(SPAWN_ASM_SRCS:.s=.o)
SPAWN_OBJS	= $(SPAWN_C_OBJS) $(SPAWN_ASM_OBJS)
HUNT_C_OBJS	= $(HUNT_C_SRCS:.c=.o)
HUNT_ASM_OBJS	= $(HUNT_ASM_SRCS:.s=.o)
HUNT_OBJS	= $(HUNT_C_OBJS) $(HUNT_ASM_OBJS)

SPAWN_EXE	= spawn
HUNT_EXE	= hunt
TEST_BINS	= testcompareChar testcompareAnagram testcompareKey \
		  testspawnAnagram testspawnKey testevaluateFlags \
		  testspawnAnagramArray testspawnAnagramFile \
		  testreadAnagramFile testhuntForAnagrams testprintUsage

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
# Target to create both programs (spawn and hunt).  This is the default target
# that gets run when you type 'make' with no target specified
#
all:
	@echo "-----------------------------------------------------------"
	@echo "| Compile SPAWN:                                          |"
	@echo "-----------------------------------------------------------"
	make $(SPAWN_EXE)
	@echo ""
	@echo ""
	@echo "-----------------------------------------------------------"
	@echo "| Compile HUNT:                                           |"
	@echo "-----------------------------------------------------------"
	make $(HUNT_EXE)

#
# Target to create the spawn anagrams program
#
$(SPAWN_EXE):	$(SPAWN_OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(SPAWN_EXE) $(LD_FLAGS) $(SPAWN_OBJS)
	@echo ""
	@echo "SPAWN: Compilation Successful!"

#
# Target to create the hunt anagrams program
#
$(HUNT_EXE):	$(HUNT_OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(HUNT_EXE) $(LD_FLAGS) $(HUNT_OBJS)
	@echo ""
	@echo "HUNT: Compilation Successful!"

$(SPAWN_C_OBJS):	$(HEADERS)
$(HUNT_C_OBJS):		$(HEADERS)

clean:
	@echo "Cleaning up project directory ..."
	$(RM) -f *.o $(SPAWN_EXE) $(HUNT_EXE) core a.out $(TEST_BINS)
	@echo ""
	@echo "Clean."

new:
	make clean
	make

#
# Unit test targets
#
testcompareChar: test.h pa3.h testcompareChar.o compareChar.o
	@echo "Compiling testcompareChar.c"
	$(GCC) $(LD_FLAGS) -o testcompareChar testcompareChar.o compareChar.o
	@echo "Compilation Successful!"

testcompareAnagram: test.h pa3.h testcompareAnagram.o compareAnagram.o \
	pa3Globals.o compareKey.o 
	@echo "Compiling testcompareAnagram.c"
	$(GCC) $(LD_FLAGS) -o testcompareAnagram testcompareAnagram.o \
	compareAnagram.o compareKey.o pa3Globals.o  
	@echo "Compilation Successful!"

testcompareKey: test.h pa3.h testcompareKey.o compareKey.o pa3Globals.o 
	@echo "Compiling testcompareKey.c"
	$(GCC) $(LD_FLAGS) -o testcompareKey testcompareKey.o compareKey.o \
	pa3Globals.o  
	@echo "Compilation Successful!"

testspawnAnagram: test.h pa3.h testspawnAnagram.o spawnAnagram.o spawnKey.o \
	compareChar.o pa3Globals.o
	@echo "Compiling testspawnAnagram.c"
	$(GCC) $(LD_FLAGS) -o testspawnAnagram testspawnAnagram.o spawnKey.o \
	spawnAnagram.o compareChar.o pa3Globals.o
	@echo "Compilation Successful!"

testspawnKey: test.h pa3.h testspawnKey.o spawnKey.o compareChar.o
	@echo "Compiling testspawnKey.c"
	$(GCC) $(LD_FLAGS) -o testspawnKey testspawnKey.o spawnKey.o \
	compareChar.o
	@echo "Compilation Successful!"

testevaluateFlags: test.h pa3.h testevaluateFlags.o evaluateFlags.o \
	printUsage.o
	@echo "Compiling testevaluateFlags.c"
	$(GCC) $(LD_FLAGS) -o testevaluateFlags testevaluateFlags.o \
	evaluateFlags.o printUsage.o
	@echo "Compilation Successful!"

testspawnAnagramArray: test.h pa3.h testspawnAnagramArray.o \
	spawnAnagramArray.o spawnAnagram.o spawnKey.o compareChar.o pa3Globals.o
	@echo "Compiling testspawnAnagramArray.c"
	$(GCC) $(LD_FLAGS) -o testspawnAnagramArray testspawnAnagramArray.o \
	spawnAnagramArray.o spawnAnagram.o spawnKey.o compareChar.o pa3Globals.o
	@echo "Compilation Successful!"

testspawnAnagramFile: test.h pa3.h testspawnAnagramFile.o spawnAnagramFile.o \
	spawnAnagramArray.o spawnAnagram.o spawnKey.o compareChar.o pa3Globals.o
	@echo "Compiling testspawnAnagramFile.c"
	$(GCC) $(LD_FLAGS) -o testspawnAnagramFile testspawnAnagramFile.o \
	spawnAnagramFile.o spawnAnagramArray.o spawnAnagram.o spawnKey.o \
	compareChar.o pa3Globals.o
	@echo "Compilation Successful!"

testreadAnagramFile: test.h pa3.h testreadAnagramFile.o readAnagramFile.o
	@echo "Compiling testreadAnagramFile.c"
	$(GCC) $(LD_FLAGS) -o testreadAnagramFile testreadAnagramFile.o \
	readAnagramFile.o
	@echo "Compilation Successful!"

testhuntForAnagrams: test.h pa3.h testhuntForAnagrams.o huntForAnagrams.o \
	spawnAnagram.o spawnKey.o compareChar.o compareKey.o pa3Globals.o
	@echo "Compiling testhuntForAnagrams.c"
	$(GCC) $(LD_FLAGS) -o testhuntForAnagrams testhuntForAnagrams.o \
	huntForAnagrams.o spawnAnagram.o spawnKey.o compareChar.o compareKey.o \
	pa3Globals.o
	@echo "Compilation Successful!"

testprintUsage: test.h pa3.h testprintUsage.o printUsage.o
	@echo "Compiling testprintUsage.c"
	$(GCC) $(LD_FLAGS) -o testprintUsage testprintUsage.o printUsage.o
	@echo "Compilation Successful!"

