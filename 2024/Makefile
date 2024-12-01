# Makefile

# Default target
all:

# Pattern rule to compile a target with util.cpp
%: %/%.cpp util.cpp
	g++ -o out $< main.cpp

# Prevents make from interpreting file named "all" as a target
.PHONY: all

