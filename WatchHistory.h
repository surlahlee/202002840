// WatchHistory.h
#pragma once
#include <vector>
#include <string>
#include <fstream>

class WatchHistory {
public:
    void addMovieToHistory(const std::string& movieTitle, const std::string& date, float rating) {
        history.push_back({movieTitle, date, rating});
    }

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
    struct WatchRecord {
        std::string movieTitle;
        std::string date;
        float rating;
    };
    
    std::vector<WatchRecord> history;
};
