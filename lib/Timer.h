//
// Created by marvd on 05.06.2021.
//

#ifndef TIC_TAC_TOE_TIMER_H
#define TIC_TAC_TOE_TIMER_H

#include <chrono>

using namespace std::chrono;

class Timer {
public:
    Timer() {
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

        std::cout << duration << " microseconds (" << ms << " milliseconds)\n";
    }

private:
    time_point<high_resolution_clock> start_timepoint;
};


#endif //TIC_TAC_TOE_TIMER_H
