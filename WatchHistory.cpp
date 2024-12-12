// WatchHistory.cpp
#include "WatchHistory.h"
#include <fstream>
#include <stdexcept>

void WatchHistory::addMovieToHistory(const std::string& movieTitle, const std::string& date, float rating) {
    history.push_back({movieTitle, date, rating});
}

void WatchHistory::saveHistoryToFile() {
    std::ofstream file("watch_history.txt");
    if (!file) {
        throw std::runtime_error("Error opening history file for writing.");
    }

    for (const auto& record : history) {
        file << record.movieTitle << "," << record.date << "," << record.rating << std::endl;
    }
    file.close();
}
