#ifndef MOVIES_H
#define MOVIES_H

#include <vector>
#include "Movie.h"


class Movies {
    std::vector<Movie> movies;
public: 
    Movies();
    ~Movies();

    void display() const;
    bool add_movie(std::string, std::string, int);
    bool increment_watched(std::string name);
};
#endif