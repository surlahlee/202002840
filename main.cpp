/* [과제설명]
    컴퓨터프로그래밍 및 실습 평가과제(배점25점)
    학과: 컴퓨터전자시스템공학과
    학번: 202002840
    이름: 이설아
    과제주제: 사용자가 OTT에서 영화나 TV 프로그램을 선택하는 데 어려움을 겪지 않도록, 시스템이 자동으로 추천을 해줍니다. 사용자가 영화를 시작하면, 일정 시간(예: 10분) 동안 해당 콘텐츠를 시청하고, 그 후 "계속 시청할지" 여부를 선택하게 하는 방식입니다.
*/ 

#include <iostream>
#include <vector>
#include "RecommendationSystem.h"
#include "FileManager.h"
#include "WatchHistory.h"

void watchFor10Minutes() {
    std::cout << "Watching movie for 10 minutes..." << std::endl;
}

int main() {
    // RecommendationSystem 객체 생성
    std::vector<Movie*> movies;
    try {
        FileManager::loadMoviesFromFile(movies);
    } catch (const std::exception& e) {
        std::cerr << "Error loading movies: " << e.what() << std::endl;
        return 1;
    }

    // 영화 객체 생성
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
