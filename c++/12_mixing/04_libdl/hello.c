#include <stdio.h>

void hello() {
  puts("Hello from shared lib");
}

int repeat(char* c) {
  printf("Cow say: %s\n", c);
  return 0;
}
