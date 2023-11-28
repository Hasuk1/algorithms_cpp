#include <iostream>
#include <vector>

int main() {
  int N, M, maxSide = 0;
  std::cin >> N >> M;
  std::vector<std::vector<int>> garden(N, std::vector<int>(M));
  std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> garden[i][j];
      if (garden[i][j] == 1) {
        dp[i + 1][j + 1] =
            std::min(std::min(dp[i][j + 1], dp[i + 1][j]), dp[i][j]) + 1;
        maxSide = std::max(maxSide, dp[i + 1][j + 1]);
      }
    }
  }
  std::cout << maxSide << std::endl;
  return 0;
}