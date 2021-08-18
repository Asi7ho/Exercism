#include "hamming.h"

#include <stdexcept>

namespace hamming {

int compute(std::string dna1, std::string dna2) {
  if (dna1.length() != dna2.length()) {
    throw std::domain_error("The DNA sequences must have the same length");
  }

  int distance = 0;
  int N = dna1.length();

  for (int i = 0; i < N; i++) {
    distance += (dna1[i] != dna2[i]);
  }

  return distance;
}

}  // namespace hamming
