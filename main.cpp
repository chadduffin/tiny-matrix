#include <iostream>

#include "tiny_matrix.h"

int main(int argc, char **argv) {
  unsigned int n = 5;

  TinyMatrix a(n, n);

  for (int i = 0; i < (n*n); i += 1) {
    a.Set(i/n, i%n, i%16);
  }

  a.Output();

  return 0;
}
