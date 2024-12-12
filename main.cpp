// main.cpp
#include <iostream>
#include <vector>
#include "RecommendationSystem.h"
#include "FileManager.h"
#include "WatchHistory.h"

void watchFor10Minutes() {
    std::cout << "Watching movie for 10 minutes..." << std::endl;
}

int main() {
    // 영화 목록 로딩
    std::vector<Movie*> movies;
    try {
        FileManager::loadMoviesFromFile(movies);
    } catch (const std::exception& e) {
        std::cerr << "Error loading movies: " << e.what() << std::endl;
        return 1;
    }

    // 추천 시스템 설정
    RecommendationSystem recommender;
    for (auto movie : movies) {
        recommender.addMovie(movie);
    }

    // 영화 추천
    std::string preferredGenre;
    std::cout << "Enter your preferred genre: ";
    std::cin >> preferredGenre;
    recommender.recommendMovies(preferredGenre);

    // 시청 기록 저장
    WatchHistory history;
    history.addMovieToHistory("Action Movie 1", "2024-12-12", 4.5);
    try {
        history.saveHistoryToFile();
    } catch (const std::exception& e) {
        std::cerr << "Error saving watch history: " << e.what() << std::endl;
    }

    return 0;
}
