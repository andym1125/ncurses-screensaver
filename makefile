saver: main.o
	g++ main.o -lncurses -o saver

main.o: main.cpp
	g++ main.cpp -c -o main.o

clean:
	rm *.o saver *.out 