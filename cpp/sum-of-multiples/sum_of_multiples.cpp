#include "sum_of_multiples.h"

namespace sum_of_multiples {

int to(std::vector<int> list, int n) {
  int sum = 0;

  int N = list.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < N; j++) {
      if (i % list[j] == 0) {
        sum += i;
        break;
      }
    }
  }

  return sum;
}

}  // namespace sum_of_multiples
