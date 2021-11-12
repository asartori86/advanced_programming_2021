#include "instrumented.hpp"
#include <iostream>

// declare static variables
double instrumented_base::counts[];
const char* instrumented_base::counter_names[] = {
  "n",
  "copy ctor", "copy assign",
  "move ctor", "move assign",
  "default ctr", "dtor",
  "equal",
  "less"};

void instrumented_base::print_summary() {
  const std::size_t n = counts[0];
  std::cout << counter_names[0] << ": "<<n << "\t";
  for (std::size_t i=1; i<n_ops; ++i){
    std::cout << counter_names[i] << ": "<<counts[i]/n << "\t";
  }
  std::cout << std::endl;
}

