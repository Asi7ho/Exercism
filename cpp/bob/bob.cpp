#include "bob.h"

namespace bob {

std::string trim(std::string str) {
  const char* typeOfWhitespaces = " \t\n\r\f\v";
  str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
  str.erase(0, str.find_first_not_of(typeOfWhitespaces));
  return str;
}

bool is_a_question(std::string str) {
  return str.back() == '?';
}

bool is_all_capitals(std::string str) {
  return std::any_of(str.begin(), str.end(), isalpha) && std::none_of(str.begin(), str.end(), islower);
}

bool saying_anything(std::string str) {
  return str.empty();
}

std::string hey(std::string str) {
  std::string trim_str = trim(str);

  if (is_all_capitals(trim_str) && is_a_question(str)) {
    return "Calm down, I know what I'm doing!";
  } else if (is_a_question(trim_str)) {
    return "Sure.";
  } else if (is_all_capitals(trim_str)) {
    return "Whoa, chill out!";
  } else if (saying_anything(trim_str)) {
    return "Fine. Be that way!";
  } else {
    return "Whatever.";
  }
}

}  // namespace bob
