#include <iostream>
#include <vector>
// #include <algorithm>
#include "Movies.h"
#include "Movie.h"

Movies::Movies(){ }
Movies::~Movies() {}

void Movies::display() const{
    std::cout << std::endl;
    if(movies.size() != 0){
        for(auto movie: movies){
            std::cout << movie.get_name() << ", "
                  << movie.get_rating() << ", "
                  << movie.get_watch_count() << std::endl;
        }
    }
    else { 
        std::cout << "Sorry, there are no movies to display" << std::endl;
    }
}
bool Movies::add_movie(std::string name, std::string rating, int watch_count){
    for(const Movie movie: movies){
        if(movie.get_name() == name)
            return false;
    }
    Movie temp {name, rating, watch_count};
    movies.push_back(temp);
    std::cout << "Added " << temp.get_name() << std::endl;
    return true;
}

bool Movies::increment_watched(std::string name){
    for(Movie &movie: movies){
        if(movie.get_name() == name){
            movie.increment_watch_count();
            return true;
        }
    }
    return false;
}