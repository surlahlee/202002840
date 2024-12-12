// RecommendationSystem.h
#pragma once
#include <vector>
#include "Movie.h"
#include "GenreMovie.h"

// RecommendationSystem 클래스: 영화 추천 시스템을 담당하는 클래스
class RecommendationSystem {
private:
    std::vector<Movie*> movies;

public:
// addMovie 함수: 추천 시스템에 새로운 영화를 추가하는 함수
    void addMovie(Movie* movie) {
        movies.push_back(movie);
    }
// recommendMovies 함수: 사용자가 선호하는 장르에 맞는 영화를 추천하는 함수
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
// RecommendationSystem 소멸자: 시스템이 종료될 때 동적으로 할당된 메모리 해제
    ~RecommendationSystem() {
        for (auto movie : movies) {
            delete movie;
        }
    }
};
