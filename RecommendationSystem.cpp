// RecommendationSystem.cpp
#include "RecommendationSystem.h"
#include <iostream>

void RecommendationSystem::addMovie(Movie* movie) {
    movies.push_back(movie);
}

// recommendMovies 함수: 사용자가 선호하는 장르에 맞는 영화를 추천하는 함수
void RecommendationSystem::recommendMovies(const std::string& preferredGenre) {
    bool found = false; // 해당 장르의 영화를 찾았는지 여부를 추적하는 변수
    for (auto movie : movies) {
        if (movie->getGenre() == preferredGenre) {
            movie->showDetails();
            movie->watch();
            found = true;
            break;
        }
    }
// 선호 장르에 맞는 영화를 찾지 못한 경우
    if (!found) {
        std::cout << "No movies found for your preferred genre!" << std::endl;
    }
}
// RecommendationSystem 소멸자: 시스템이 종료될 때 동적으로 할당된 메모리 해제
RecommendationSystem::~RecommendationSystem() {
    for (auto movie : movies) {
        delete movie;
    }
}
