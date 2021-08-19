#include "phone_number.h"

#include <iostream>
#include <stdexcept>

namespace phone_number {

phone_number::phone_number(std::string num) {
  int N = num.length();
  std::string trim_num;

  for (int i = 0; i < N; i++) {
    if (isnumber(num[i])) {
      trim_num += num[i];
    }
  }

  if (trim_num.length() != 10 && trim_num.length() != 11) {
    throw std::domain_error("Phone number doesn't have the right length");
  }

  if (trim_num.length() == 11 && trim_num[0] != '1') {
    throw std::domain_error("Wrong country code");
  }

  if (trim_num.length() == 10) {
    if (trim_num[3] < '2') {
      throw std::domain_error("Prefix code should be > 1");
    }

    this->phone = trim_num;
    this->area = trim_num.substr(0, 3);
  }

  if (trim_num.length() == 11) {
    if (trim_num[4] < '2') {
      throw std::domain_error("Prefix code should be > 1");
    }

    this->phone = trim_num.substr(1);
    this->area = trim_num.substr(1, 4);
  }

  if (this->area[0] < '2') {
    throw std::domain_error("Area code should be > 1");
  }
}

std::string phone_number::number() const {
  return this->phone;
}

std::string phone_number::area_code() const {
  return this->phone.substr(0, 3);
}

phone_number::operator std::string() const {
  std::string area_code = this->phone.substr(0, 3);
  std::string prefix = this->phone.substr(3, 3);
  std::string postfix = this->phone.substr(6);

  return '(' + area_code + ')' + ' ' + prefix + '-' + postfix;
}

}  // namespace phone_number
