// WatchHistory.h
#pragma once
#include <vector>
#include <string>
#include <fstream>

// WatchHistory 클래스: 영화 시청 기록을 관리하고, 이를 파일에 저장하는 클래스
class WatchHistory {
public:
// addMovieToHistory 함수: 새로운 시청 기록을 history 벡터에 추가하는 함수
    void addMovieToHistory(const std::string& movieTitle, const std::string& date, float rating) {
        history.push_back({movieTitle, date, rating});
    }
// saveHistoryToFile 함수: 시청 기록을 "watch_history.txt" 파일에 저장하는 함수
    void saveHistoryToFile() {
        std::ofstream file("watch_history.txt");
        if (!file) {
            throw std::runtime_error("Error opening history file for writing.");
        }

        for (const auto& record : history) {
            file << record.movieTitle << "," << record.date << "," << record.rating << std::endl;
        }
        file.close();
    }

private:
// WatchRecord 구조체: 영화 시청 기록을 저장하는 구조체
    struct WatchRecord {
        std::string movieTitle;
        std::string date;
        float rating;
    };
    
    std::vector<WatchRecord> history;
};
