#include "etl.h"

namespace etl {

std::map<char, int> transform(std::map<int, std::vector<char>> old_map) {
  std::map<char, int> new_map;

  std::map<int, std::vector<char>>::iterator it;
  for (it = old_map.begin(); it != old_map.end(); it++) {
    int key = it->first;
    std::vector<char> values = it->second;

    int N = values.size();
    for (int i = 0; i < N; i++) {
      new_map[tolower(values[i])] = key;
    }
  }

  return new_map;
}

}  // namespace etl
