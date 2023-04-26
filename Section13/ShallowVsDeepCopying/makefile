CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g

main: main.o deep.o
	$(CXX) $(CXXFLAGS) -o bin/main output/main.o deep.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c -o output/main.o main.cpp

shallow.o: deep.cpp deep.h
	$(CXX) $(CXXFLAGS) -c -o output/deep.o src/deep.cpp

run:
	./main

clean:
	rm -rf output/* bin/*