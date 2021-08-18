#include "isogram.h"

using namespace std;

namespace isogram {

bool is_isogram(string word) {
  if (word.empty()) {
    return true;
  }

  map<char, bool> m;

  for (char& c : word) {
    if (isalpha(c)) {
      if (m[tolower(c)]) {
        return false;
      } else {
        m[tolower(c)] = true;
      }
    }
  }

  return true;
}

}  // namespace isogram
