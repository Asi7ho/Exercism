#if !defined(WORD_COUNT_H)
#define WORD_COUNT_H

#include <algorithm>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace word_count {

std::string remove_punctuation(std::string str);
std::vector<std::string> get_words(std::string str);
std::map<std::string, int> words(std::string word);

}  // namespace word_count

#endif  // WORD_COUNT_H