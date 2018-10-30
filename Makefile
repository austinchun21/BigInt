#
# Makefile for BigInt
# Austin Chun
# 

###############################################################################
# MAKEFILE VARIABLES
###############################################################################

# CXX is the name of the compiler we are using (clang++)

CXX = g++

# CXXFLAGS are the flags we will be passing each compile

CXXFLAGS = -g -std=c++11 -Wall -Wextra -pedantic 

# TARGETS is the list of all programs created when we do "make all"
#   (and which should be deleted when we do "make clean")

TARGETS = Test Factorial

###############################################################################
# "PHONY" (BUT USEFUL) MAKEFILE TARGETS
###############################################################################


# "make all" brings all programs up-to-date (recursively)
#     and then runs no commands.

all: $(TARGETS)

# "make clean" brings nothing up to date, but always
#      runs commands to delete all created files

clean:
	rm -f $(TARGETS)
	rm -rf *.o


###############################################################################
# CREATING PROGRAMS
###############################################################################
 
# In a command run by the makefile, $^ stands for the things the target
#      depends on
#      This is useful so that we don't have to duplicate this list
#      both in the dependency list and in the linking command


# "make bigint-test" brings the relevant .o files up-to-date (recursively)
#      and then links them.

Test: bigint-test.o bigint.o 
	$(CXX) $(CXXFLAGS) -o Test $^

Factorial: bigfactorial.o bigint.o
	$(CXX) $(CXXFLAGS) -o Factorial $^

###############################################################################
# GENERATING OBJECT FILES
###############################################################################

# The .o files depend on the corresponding .cpp file and the .hpp
#      files that C++ code includes.
#      In each case, the command to generate the .o file uses
#      our C++ compiler to compile the .cpp file, with the -c flag.

bigint-test.o: bigint-test.cpp bigint.hpp
	$(CXX) $(CXXFLAGS) -c bigint-test.cpp

bigfactorial.o: bigfactorial.cpp bigint.hpp
	$(CXX) $(CXXFLAGS) -c bigfactorial.cpp

bigint.o: bigint.hpp bigint.cpp
	$(CXX) $(CXXFLAGS) -c bigint.cpp

