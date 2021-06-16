#
# Makefile template for CSE 30 -- PAMT1
#

#
# You need to change these next lines for each assignment
#

HEADERS		= pamt1.h

C_SRCS		= initData.cpp sequentialSquaredSumMinMax.cpp main.cpp 

C_OBJS		= initData.o sequentialSquaredSumMinMax.o main.o

OBJS		= ${C_OBJS}

EXE		= squaredSumMinMax

#
# You should not need to change anything below this line
#

#
# Relevant man pages:
#
# man -M /software/common/gnu/man g++
#

GCC		= g++

GCC_FLAGS	= -g -O3 -lpthread -c -Wall -std=c++11
LD_FLAGS	= -g -lpthread -Wall

#
# Standard rules
#

.cpp.o:
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
	@echo ""

#
# Simply have our project target be a single default $(EXE) executable.
#

$(EXE):	$(OBJS)
	@echo "Linking all object modules ..."
	$(GCC) -o $(EXE) $(LD_FLAGS) $(OBJS)
	@echo ""
	@echo "Done."

${C_OBJS}:      ${HEADERS}

clean:
	@echo "Cleaning up project directory ..."
	rm -f *.o $(EXE) *.ln core a.out
	@echo ""
	@echo "Clean."

new:
	make clean
	make
