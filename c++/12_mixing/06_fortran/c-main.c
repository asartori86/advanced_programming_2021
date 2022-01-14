#include <stdio.h>

#define NUM 5

void sum_abs_(int *, int *, int *); /* trailing underscore, pointers */

int main(int argc, char **argv) {
  int data[NUM], sum, num, i;

  num = NUM;
  for (i = 0; i < num; i++) {
    data[i] = i;
  }

  sum_abs_(data, &num, &sum);
  printf("sum=%d\n", sum);
  return 0;
}
