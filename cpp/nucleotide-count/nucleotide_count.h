#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {

class counter {
 public:
  counter(std::string dna);
  std::map<char, int> nucleotide_counts() const;
  int count(char nucleotide) const;

 private:
  std::map<char, int> counts;
};

}  // namespace nucleotide_count

#endif  // NUCLEOTIDE_COUNT_H