//
// Created by marvd on 05.06.2021.
//

#ifndef TIC_TAC_TOE_TIMER_H
#define TIC_TAC_TOE_TIMER_H

#include <chrono>
#include "fstream"

using namespace std::chrono;

class Timer {
public:
    explicit Timer(std::string &filename) {
        this->filename = filename;
        start_timepoint = high_resolution_clock::now();
    }

    ~Timer() {
        Stop();
    }

    void Stop() {
        auto end_timepoint = high_resolution_clock::now();

        auto start = time_point_cast<microseconds>(start_timepoint).time_since_epoch().count();
        auto end = time_point_cast<microseconds>(end_timepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::string output = std::to_string(duration) + " microseconds (" + std::to_string(ms) + " milliseconds)";
        writeToFile(output);
    }

private:
    time_point<high_resolution_clock> start_timepoint;
    std::string filename;

    void writeToFile(std::string &output) {
        std::ofstream file;
        file.open(filename, std::ios::app | std::ios::out);
        file << output << "\n";
        file.close();
    }
};


#endif //TIC_TAC_TOE_TIMER_H
