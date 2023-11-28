#include <cmath>
#include <iostream>
#include <string>
#include <vector>

const unsigned long int p = 1e9 + 7;

long int calchash(const std::string& text, int x,
                  std::vector<unsigned long int>& hash_string,
                  std::vector<unsigned long int>& x_pow) {
  hash_string[0] = text[0] - 60;
  x_pow[0] = 1;
  for (int i = 1; i < hash_string.size(); ++i) {
    hash_string[i] = (hash_string[i - 1] * x + (text[i] - 60)) % p;
    x_pow[i] = (x_pow[i - 1] * x) % p;
  }
  return hash_string.back();
}

bool hash_use(int len, int first, int second,
              std::vector<unsigned long int>& hash_string,
              std::vector<unsigned long int>& x_pow) {
  long long int first_hash =
      (hash_string[first + len - 1] +
       ((second > 0) ? hash_string[second - 1] : 0) * x_pow[len]) %
      p;
  long long int second_hash =
      (hash_string[second + len - 1] +
       ((first > 0) ? hash_string[first - 1] : 0) * x_pow[len]) %
      p;
  return first_hash == second_hash;
}

int main() {
  std::string S;
  std::cin >> S;
  int Q;
  std::cin >> Q;
  int x = 257;
  std::vector<unsigned long int> hash_string(S.size());
  std::vector<unsigned long int> x_pow(S.size());
  calchash(S, x, hash_string, x_pow);

  for (int i = 0; i < Q; ++i) {
    unsigned long int L, A, B;
    std::cin >> L >> A >> B;
    if (hash_use(L, A, B, hash_string, x_pow)) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }

  return 0;
}