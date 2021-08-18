#include "anagram.h"

namespace anagram {

anagram::anagram(std::string str) {
  this->word = str;
  std::transform(this->word.begin(), this->word.end(), this->word.begin(), ::tolower);

  this->sort_word = str;
  std::transform(this->sort_word.begin(), this->sort_word.end(), this->sort_word.begin(), ::tolower);
  std::sort(this->sort_word.begin(), this->sort_word.end());

  this->length = str.length();
}

std::vector<std::string> anagram::matches(std::vector<std::string> array) {
  std::vector<std::string> matches;

  for (std::string word : array) {
    if (is_anagram(word)) {
      matches.push_back(word);
    }
  }

  return matches;
}

bool anagram::is_anagram(std::string word) {
  int length = word.length();

  if (this->length != length) {
    return false;
  }

  std::transform(word.begin(), word.end(), word.begin(), ::tolower);

  int count = 0;
  for (int i = 0; i < length; i++) {
    if (this->word[i] == word[i]) {
      count++;
    }
  }

  if (count == length) {
    return false;
  }

  std::sort(word.begin(), word.end());

  for (int i = 0; i < length; i++) {
    if (this->sort_word[i] != word[i]) {
      return false;
    }
  }

  return true;
}

}  // namespace anagram
