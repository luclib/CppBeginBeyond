CXX = g++ 
CXXFLAGS = -Wall -Wextra -pedantic

main: main.cpp Movies.cpp Movie.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

# main.o: main.cpp Movies.cpp Movie.cpp
# 	$(CXX) $(CXXFLAGS) -o $@ $<

# Movie.o: Movie.cpp Movie.h
# 	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Movies.o: Movies.cpp Movies.h
# 	$(CXX) $(CXXFLAGS) -o $@ -c $<

run:
	@./main

clean:
	rm -rf main