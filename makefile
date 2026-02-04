# mf.exe - empty file generator - makefile
# Authored on 2026.02.03 by Anthoni Caldwell
# Updated on 2026.02.03


# Output filename
BINARY_NAME=mf.exe

# What to compile with
COMPILER=g++

# Binary Path
BIN_PATH=bin/
# Object Path - Where .o files will be stored
OBJ_PATH=obj/
# Source Path - Where the source files are stored
SRC_PATH=src/

all: mf.o
	$(COMPILER) $(OBJ_PATH)mf.o -o $(BIN_PATH)$(BINARY_NAME)
	
mf.o: $(SRC_PATH)mf.cpp
	$(COMPILER) $(SRC_PATH)mf.cpp -c -o $(OBJ_PATH)mf.o