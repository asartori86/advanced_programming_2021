#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static const int val1 = -5;
const int val2 = 10;
static int val3 = -20;
int val4 = -15;
extern int errno;

static int add_abs(const int v1, const int v2) {
  return abs(v1) + abs(v2);
}

int main() {
  int val5 = 20;
  printf("%d / %d / %d / %d\n", add_abs(val1, val2), add_abs(val3, val4),
         add_abs(val1, val5), errno);
  return 0;
}
