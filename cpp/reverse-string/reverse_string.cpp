#include "reverse_string.h"

namespace reverse_string {

std::string reverse_string(std::string str) {
  std::string reverse_str = "";

  for (int i = str.length() - 1; i >= 0; i--) {
    reverse_str = reverse_str + str[i];
  }

  return reverse_str;
}

}  // namespace reverse_string
