#include "word_count.h"

namespace word_count {

std::string remove_punctuation(std::string str) {
  std::string new_str = "";

  int N = str.length();
  for (int i = 0; i < N; i++) {
    if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
      new_str += str[i];
    } else if (str[i] == '\'' && isalnum(str[i - 1]) && isalnum(str[i + 1])) {
      new_str += str[i];
    } else if (str[i] == ',' || str[i] == ':') {
      new_str += ' ';
    } else if (isalnum(str[i])) {
      new_str += str[i];
    } else {
      continue;
    }
  }
  return new_str;
}

std::vector<std::string> get_words(std::string str) {
  std::vector<std::string> list_of_words;
  std::string word;
  std::stringstream iss(str);

  while (iss >> word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    list_of_words.push_back(word);
  }

  return list_of_words;
}

std::map<std::string, int> words(std::string words) {
  std::map<std::string, int> word_count;

  std::string str = remove_punctuation(words);
  std::vector<std::string> list_of_words = get_words(str);

  int N = list_of_words.size();
  for (int i = 0; i < N; i++) {
    word_count[list_of_words[i]] += 1;
  }

  return word_count;
}

}  // namespace word_count
