// WatchHistory.cpp
#include "WatchHistory.h"
#include <fstream>
#include <stdexcept>

// addMovieToHistory 함수: 영화 시청 기록을 history 벡터에 추가하는 함수
void WatchHistory::addMovieToHistory(const std::string& movieTitle, const std::string& date, float rating) {
    history.push_back({movieTitle, date, rating});
}

void WatchHistory::saveHistoryToFile() {
    std::ofstream file("watch_history.txt");
    if (!file) {
        throw std::runtime_error("Error opening history file for writing.");
    }
// history 벡터에 저장된 각 시청 기록을 파일에 저장
    for (const auto& record : history) {
        file << record.movieTitle << "," << record.date << "," << record.rating << std::endl;
    }
    file.close();
}
