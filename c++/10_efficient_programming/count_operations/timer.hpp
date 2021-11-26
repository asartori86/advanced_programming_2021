#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>

template <typename Clock = std::chrono::high_resolution_clock,
          typename Duration = typename Clock::duration>
class timer {
  using time_point = std::chrono::time_point<Clock, Duration>;
  time_point t0;

 public:
  void start() { t0 = Clock::now(); }
  void stop() {
    time_point t1 = Clock::now();
    std::cout << std::setw(15)
              << std::chrono::duration_cast<std::chrono::duration<double>>(t1 -
                                                                           t0)
                     .count()
              << " [seconds]" << std::endl;
  }
};
