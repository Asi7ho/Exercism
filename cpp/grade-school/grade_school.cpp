#include "grade_school.h"

namespace grade_school {

void school::add(std::string name, int grade) {
  if (this->list.count(grade)) {
    this->list[grade].push_back(name);
    std::sort(this->list[grade].begin(), this->list[grade].end());
  } else {
    this->list[grade] = std::vector<std::string>{name};
  }
}

std::map<int, std::vector<std::string>> school::roster() const {
  return this->list;
}

std::vector<std::string> school::grade(int g) const {
  if (this->list.count(g)) {
    return this->list.at(g);
  }

  return {};
}

}  // namespace grade_school
