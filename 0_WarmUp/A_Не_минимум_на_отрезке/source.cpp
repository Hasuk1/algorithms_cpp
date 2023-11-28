#include <iostream>
#include <vector>

int main() {
  unsigned int seq_len, req_num;
  std::cin >> seq_len >> req_num;
  if (seq_len >= 1 && seq_len <= 100 && req_num >= 1 && req_num <= 1000) {
    std::vector<int> sequence(seq_len);
    for (unsigned int i = 0; i < seq_len; ++i) std::cin >> sequence[i];
    for (unsigned int i = 0; i < req_num; ++i) {
      unsigned int L, R;
      std::cin >> L >> R;

      int min_val = sequence[L];

      for (unsigned int j = L; j <= R; ++j) {
        if (sequence[j] < min_val) {
          min_val = sequence[j];
        }
      }

      for (unsigned int j = L; j <= R; ++j) {
        if (sequence[j] != min_val) {
          std::cout << sequence[j] << std::endl;
          break;
        }

        if (j == R) {
          std::cout << "NOT FOUND" << std::endl;
        }
      }
    }
  } else return 1;
  return 0;
}
