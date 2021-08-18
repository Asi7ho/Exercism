#include "nucleotide_count.h"

#include <stdexcept>

namespace nucleotide_count {

counter::counter(std::string dna) {
  counts = {{'A', 0},
            {'T', 0},
            {'C', 0},
            {'G', 0}};

  for (const char &c : dna) {
    if (!(c == 'A' || c == 'C' || c == 'G' || c == 'T'))
      throw std::invalid_argument("Contains invalid character...");
    counts[c]++;
  }
}

std::map<char, int> counter::nucleotide_counts() const {
  return counts;
}

int counter::count(char nucleotide) const {
  if (!(nucleotide == 'A' || nucleotide == 'C' || nucleotide == 'G' || nucleotide == 'T')) {
    throw std::invalid_argument("Contains invalid character...");
  }

  return counts.at(nucleotide);
}

}  // namespace nucleotide_count
