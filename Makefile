all: program

program: main.o series.o
	g++ -Wall -Wextra -O2 -o program main.o series.o

main.o: main.cpp series.h
	g++ -Wall -Wextra -O2 -c main.cpp

series.o: series.cpp series.h
	g++ -Wall -Wextra -O2 -c series.cpp

clean:
	rm -f *.o program

