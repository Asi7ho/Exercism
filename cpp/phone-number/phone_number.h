#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number {

class phone_number {
 public:
  phone_number(std::string num);
  std::string number() const;
  std::string area_code() const;

  operator std::string() const;

 private:
  std::string area;
  std::string phone;
};

}  // namespace phone_number

#endif  // PHONE_NUMBER_H