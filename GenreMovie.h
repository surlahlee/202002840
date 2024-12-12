// GenreMovie.h
#pragma once
#include "Movie.h"

class GenreMovie : public Movie {
public:
// GenreMovie 생성자: Movie 클래스의 생성자를 호출하여 title, genre, rating을 초기화
    GenreMovie(const std::string& title, const std::string& genre, float rating)
        : Movie(title, genre, rating) {}
// showDetails 함수: 영화의 제목, 장르, 평점을 출력하는 함수 (override)
    void showDetails() const override {
        std::cout << "Title: " << title << ", Genre: " << genre << ", Rating: " << rating << std::endl;
    }
// watch 함수: 영화를 10분 동안 시청하는 행동을 출력하는 함수 (override)
    void watch() const override {
        std::cout << "Watching " << title << " for 10 minutes..." << std::endl;
    }
};
