#if !defined(BOB_H)
#define BOB_H

#include <algorithm>
#include <string>

namespace bob {

std::string trim(std::string str);
bool is_a_question(std::string str);
bool is_all_capitals(std::string str);
bool saying_anything(std::string str);
std::string hey(std::string str);

}  // namespace bob

#endif  // BOB_H