# Makefile
CXX_FLAG = --std=c++11 -g

all: testcards game

testcards: testcards.o cards.o
	g++ $(CXX_FLAG) -o testcards testcards.o cards.o

testcards.o: testcards.cpp
	g++ -c $(CXX_FLAG) testcards.cpp

cards.o: cards.cpp
	g++ -c $(CXX_FLAG) cards.cpp

clean:
	rm -f testcards *.o

