all: methods.o shell.o
	@gcc -o tester methods.o shell.o


methods.o: methods.c shell.h
	@gcc -c methods.c

shell.o: shell.c shell.h 
	@gcc -c shell.c

shell_debug: methods_debug.o shell_debug.o
	@gcc -o shell_debug methods_debug.o shell_debug.o

methods_debug.o: methods.c shell.h
	@gcc -g -c methods.c -o methods_debug.o

shell_debug.o: shell.c shell.h
	@gcc -g -c shell.c -o shell_debug.o

debug: shell_debug
	valgrind --leak-check=yes ./shell_debug

clean:
	@rm *.o
	@rm *~

run: all
	@./tester
