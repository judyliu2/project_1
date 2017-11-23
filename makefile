tester: methods.o shell.o
	@gcc methods.o shell.o -o tester

run: tester
	@./tester

methods.o: methods.c shell.h
	@gcc -c methods.c

shell.o: shell.c shell.h
	@gcc -c shell.c

clean:
	@rm *.o
	@rm *~
