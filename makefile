all: methods.o shell.o
	@gcc -o tester methods.o shell.o


methods.o: methods.c shell.h
	@gcc -c methods.c

shell.o: shell.c shell.h 
	@gcc -c shell.c

clean:
	@rm *.o
	@rm *~

run: all
	@./tester
