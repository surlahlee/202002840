// FileManager.cpp
#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

// 영화 데이터를 파일에서 읽어와 'movies' 벡터에 추가하는 함수
void FileManager::loadMoviesFromFile(std::vector<Movie*>& movies) {
    // 파일을 읽기 모드로 열기
    std::ifstream file("movies.txt");
    // 파일 열기 실패 시 예외를 던짐
    if (!file) {
        throw std::runtime_error("Error opening movie file for reading.");
    }

    std::string line;
    // 파일에서 한 줄씩 읽어옴
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, genre;
        float rating;
        std::getline(ss, title, ',');
        std::getline(ss, genre, ',');
        ss >> rating;
        // 새 GenreMovie 객체를 생성하고, movies 벡터에 추가
        movies.push_back(new GenreMovie(title, genre, rating));
    }
    file.close();
}
// 영화 데이터를 파일에 저장하는 함수
void FileManager::saveMoviesToFile(const std::vector<Movie*>& movies) {
    std::ofstream file("movies.txt");
    if (!file) {
        throw std::runtime_error("Error opening movie file for writing.");
    }

    for (const auto& movie : movies) {
        file << movie->getTitle() << "," << movie->getGenre() << "," << movie->getRating() << std::endl;
    }
    file.close();
}
