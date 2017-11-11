#include <iostream>

#include "tiny_matrix.h"

int main(int argc, char **argv) {
  TinyMatrix a(5, 5);

  for (int i = 0; i < 25; i += 1) {
    a.Set(i/5, i%5, i%16);
  }

  for (int i = 0; i < 25; i += 1) {
    std::cout << static_cast<unsigned int>(a.Get(i/5, i%5)) << std::endl;
  }

  return 0;
}
