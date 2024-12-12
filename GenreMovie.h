// GenreMovie.h
#pragma once
#include "Movie.h"

class GenreMovie : public Movie {
public:
    GenreMovie(const std::string& title, const std::string& genre, float rating)
        : Movie(title, genre, rating) {}

    void showDetails() const override {
        std::cout << "Title: " << title << ", Genre: " << genre << ", Rating: " << rating << std::endl;
    }

    void watch() const override {
        std::cout << "Watching " << title << " for 10 minutes..." << std::endl;
    }
};
