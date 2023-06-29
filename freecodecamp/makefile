# Reference: https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

CC = gcc
CFLAGS = -I.
CFLAGS += -Wall
CFLAGS += -Werror
CFLAGS += -Wpedantic

DEPS = info.h # macro, set of .h files on which .c files depend

# rule applying to all files with .o suffix
# -> .o file depends on .c version and the included .h files included in DEPS macro
# -> make will use the compiler defined in CC macro
# -c flag: generate the object file
# -o $@ flag: put output of compilation in the file named on the left of ':'
# $< flag: first item in the dependencies list
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: main.o
	$(CC) -o main main.o 
	@./main

	