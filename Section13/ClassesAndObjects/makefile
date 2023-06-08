CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic

# Directory for header files
INCLUDE = -I/home/luclib/Repo/CppBeginBeyond/Section14/include
# Directory for souce code files
SRC = -I/home/luclib/Repo/CppBeginBeyond/Section14/src


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