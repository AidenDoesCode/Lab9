#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    void start_timer() {
        start_time_ = std::chrono::steady_clock::now();
        running_ = true;
    }

    void end_timer() {
        end_time_ = std::chrono::steady_clock::now();
        running_ = false;
    }

    double elapsed_time() const {
        if (running_) {
            auto now = std::chrono::steady_clock::now();
            return std::chrono::duration<double>(now - start_time_).count();
        }
        return std::chrono::duration<double>(end_time_ - start_time_).count();
    }

private:
    std::chrono::steady_clock::time_point start_time_;
    std::chrono::steady_clock::time_point end_time_;
    bool running_ = false;
};

#endif
