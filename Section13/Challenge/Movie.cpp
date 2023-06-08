#include <string>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watch_count)
    : name(name), rating(rating), watch_count(watch_count){
}
Movie::Movie(const Movie &movie)
    : Movie {movie.name, movie.rating, movie.watch_count}{ }
Movie::~Movie(){};
