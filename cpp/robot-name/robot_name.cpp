#include "robot_name.h"

namespace robot_name {

std::string robot::generate_name() {
  std::string robot_id;

  for (int i = 0; i < 2; i++) {
    robot_id += std::toupper('a' + rand() % 26);
  }

  for (int i = 0; i < 3; i++) {
    robot_id += std::to_string(std::rand() % 10);
  }

  return robot_id;
}

robot::robot() {
  std::string new_id = this->generate_name();
  this->id = new_id;
}

std::string robot::name() const {
  return this->id;
}

void robot::reset() {
  std::string old_id = this->id;

  while (old_id == this->id) {
    this->id = this->generate_name();
  }
}

}  // namespace robot_name
