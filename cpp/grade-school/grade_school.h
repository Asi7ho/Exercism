#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <algorithm>
#include <map>
#include <string>
#include <vector>

namespace grade_school {
class school {
 public:
  void add(std::string name, int grade);
  std::map<int, std::vector<std::string>> roster() const;
  std::vector<std::string> grade(int g) const;

 private:
  std::map<int, std::vector<std::string>> list;
};

}  // namespace grade_school

#endif  // GRADE_SCHOOL_H