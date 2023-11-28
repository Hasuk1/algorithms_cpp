#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, a, b;
    std::cin >> n >> a >> b;
    bool can_be_divided = false;

    for (int j = a; j <= b; j++) {
      if (n % j == 0 || n % j <= static_cast<int>(n / j) * (b - a)) {
        can_be_divided = true;
        break;
      }
    }

    if (can_be_divided) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }

  return 0;
}
