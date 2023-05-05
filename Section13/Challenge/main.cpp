#include <iostream>
#include <string>
#include "Movies.h"

void add_Movie(Movies &movies, std::string name, std::string rating, int watch_count){
    movies.add_movie(name, rating, watch_count);
 }
void increment_watch_count(Movies &movies, std::string name){
    movies.increment_watched(name);
 }

int main() {    
    Movies my_movies;
    my_movies.display();

    add_Movie(my_movies, "The Lord of the Rings", "PG-13", 32);
    add_Movie(my_movies, "Shawshank Redemption", "PG", 2);
    add_Movie(my_movies, "Tarzan", "G", 4);
    my_movies.display();

    increment_watch_count(my_movies, "Lord of the Rings");
    increment_watch_count(my_movies, "Shawshank Redemption");
    increment_watch_count(my_movies, "Lord of the Rings");
    my_movies.display();
}