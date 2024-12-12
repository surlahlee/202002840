// Movie.h
#pragma once
#include <iostream>
#include <string>

class Movie {
public:
    Movie(const std::string& title, const std::string& genre, float rating)
        : title(title), genre(genre), rating(rating) {}

    virtual void showDetails() const = 0;  // 순수 가상 함수: 영화 정보 출력
    virtual void watch() const = 0;        // 순수 가상 함수: 영화 시청 시작

    virtual ~Movie() {}  // 가상 소멸자

    const std::string& getTitle() const { return title; }
    const std::string& getGenre() const { return genre; }
    float getRating() const { return rating; }

protected:
    std::string title;
    std::string genre;
    float rating;
};
