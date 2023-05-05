#ifndef MOVIE_H
#define MOVIE_H

#include <string>

class Movie {
private:
    std::string name;
    std::string rating;
    int watch_count;
public:
    std::string get_name() const { return name; }
    std::string get_rating() const { return rating; }
    int get_watch_count() const { return watch_count; }
    void increment_watch_count() { ++watch_count; }
    
    Movie(std::string name = "N/A",
          std::string title = "G",
          int watch_count = 1);
    Movie(const Movie& movie);
    ~Movie();
}; 
#endif