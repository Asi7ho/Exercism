#if !defined(ANAGRAM_H)
#define ANAGRAM_H

#include <algorithm>
#include <string>
#include <vector>

namespace anagram {

class anagram {
 public:
  anagram(std::string str);
  std::vector<std::string> matches(std::vector<std::string> array);

 private:
  std::string word;
  std::string sort_word;
  int length;

  bool is_anagram(std::string word);
};

}  // namespace anagram

#endif  // ANAGRAM_H