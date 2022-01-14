#include <stdio.h>

void hello() {
  puts("Hello from shared lib");
}

int repeat(char* c) {
  printf("Cow say: %s\n", c);
  return 0;
}

double array_sum(const double* p, const size_t l) {
  double sum = 0;
  for (size_t i = 0; i < l; ++i)
    sum += p[i];
  return sum;
}

struct data {
  int i;
  char* name;
  double energy;
};

void use_by_value(struct data d) {
  printf("i=%d, name=%s, energy=%g\n", d.i, d.name, d.energy);
}

void use_by_reference(struct data* d) {
  printf("i=%d, name=%s, energy=%g\n", d->i, d->name, d->energy);
}

void set_energy(struct data* d, double e) {
  d->energy = e;
}
