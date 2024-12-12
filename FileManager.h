// FileManager.h
#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include "Movie.h"
#include "GenreMovie.h"

class FileManager {
public:
    static void loadMoviesFromFile(std::vector<Movie*>& movies) {
        std::ifstream file("movies.txt");
        if (!file) {
            throw std::runtime_error("Error opening movie file for reading.");
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string title, genre;
            float rating;
            std::getline(ss, title, ',');
            std::getline(ss, genre, ',');
            ss >> rating;
            movies.push_back(new GenreMovie(title, genre, rating));
        }
        file.close();
    }

    static void saveMoviesToFile(const std::vector<Movie*>& movies) {
        std::ofstream file("movies.txt");
        if (!file) {
            throw std::runtime_error("Error opening movie file for writing.");
        }

        for (const auto& movie : movies) {
            file << movie->getTitle() << "," << movie->getGenre() << "," << movie->getRating() << std::endl;
        }
        file.close();
    }
};
