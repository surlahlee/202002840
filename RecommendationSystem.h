// RecommendationSystem.h
#pragma once
#include <vector>
#include "Movie.h"
#include "GenreMovie.h"

class RecommendationSystem {
private:
    std::vector<Movie*> movies;

public:
    void addMovie(Movie* movie) {
        movies.push_back(movie);
    }

    void recommendMovies(const std::string& preferredGenre) {
        bool found = false;
        for (auto movie : movies) {
            if (movie->getGenre() == preferredGenre) {
                movie->showDetails();
                movie->watch();
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "No movies found for your preferred genre!" << std::endl;
        }
    }

    ~RecommendationSystem() {
        for (auto movie : movies) {
            delete movie;
        }
    }
};
