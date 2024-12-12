// FileManager.h
#pragma once
#include <fstream>
#include <sstream>
#include <vector>
#include "Movie.h"
#include "GenreMovie.h"

// 파일 읽기 및 저장을 담당하는 FileManager 클래스
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
// 영화 데이터를 'movies' 벡터에서 읽어 "movies.txt" 파일에 저장하는 정적 함수
    static void saveMoviesToFile(const std::vector<Movie*>& movies) {
        std::ofstream file("movies.txt");
        if (!file) {
            throw std::runtime_error("Error opening movie file for writing.");
        }
 // movies 벡터에 있는 각 영화 객체의 정보를 파일에 저장
        for (const auto& movie : movies) {
            file << movie->getTitle() << "," << movie->getGenre() << "," << movie->getRating() << std::endl;
        }
        file.close();
    }
};
