#include <iostream>

#define NUM 5

extern "C" {
void sum_abs_(int *, int *, int *);
}

int main(int argc, char **argv) {
  int data[NUM], sum, num, i;

  num = NUM;
  for (i = 0; i < num; i++) {
    data[i] = i;
  }

  sum_abs_(data, &num, &sum);
  std::cout << "sum=" << sum << std::endl;
  return 0;
}
