CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic

main: main.cpp account.cpp account.h
	mkdir bin  
	$(CXX) $(CXXFLAGS) -o bin/main main.cpp account.cpp

run:
	./bin/main

clean:
	rm -rf bin