CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic

main: main.o account.o
	$(CXX) $(CXXFLAGS) -o main main.o account.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o main.o main.cpp

account.o: account.cpp account.h
	$(CXX) $(CXXFLAGS) -c -o account.o account.cpp

run:
	./main

clean:
	rm -rf *.o main