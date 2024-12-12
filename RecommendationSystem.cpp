// RecommendationSystem.cpp
#include "RecommendationSystem.h"
#include <iostream>

void RecommendationSystem::addMovie(Movie* movie) {
    movies.push_back(movie);
}

void RecommendationSystem::recommendMovies(const std::string& preferredGenre) {
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

RecommendationSystem::~RecommendationSystem() {
    for (auto movie : movies) {
        delete movie;
    }
}
