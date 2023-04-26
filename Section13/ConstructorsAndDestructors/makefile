CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g

main: main.o player.o
	$(CXX) $(CXXFLAGS) -o main main.o player.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

account.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) -c -o player.o player.cpp

run:
	./main

clean:
	rm -rf *.o main