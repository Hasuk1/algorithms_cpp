#include <cmath>
#include <iostream>
#include <vector>

int main() {
  int a, b, n;
  std::cin >> a >> b >> n;
  if (std::ceil(static_cast<double>(b) / n) < a) {
    std::cout << "Yes" << std::endl;
  } else
    std::cout << "No" << std::endl;
  return 0;
}
