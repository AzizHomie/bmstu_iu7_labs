app.exe: io.o calc.o process.o lab08.o
	gcc -o app.exe io.o calc.o process.o lab08.o

test.exe: calc.o process.o test.o
	gcc -o test.exe test.o calc.o process.o

io.o: io.c io.h
	gcc -std=c99 -Wall -Werror -ggdb -c io.c

calc.o: calc.c calc.h
	gcc -std=c99 -Wall -Werror -ggdb -c calc.c

process.o: process.c process.h
	gcc -std=c99 -Wall -Werror -ggdb -c process.c

lab08.o: lab08.c
	gcc -std=c99 -Wall -Werror -ggdb -c lab08.c

test.o: test.c calc.h
	gcc -std=c99 -Wall -Werror -ggdb -c test.c

clean:
	rm *.exe *.o
