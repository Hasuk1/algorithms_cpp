#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<long long> dissatisfaction(n);
    long long total_dissatisfaction = 0;

    for (int i = 0; i < n; i++) {
        dissatisfaction[i] = static_cast<long long>(a[i]) * i - total_dissatisfaction;
        total_dissatisfaction += a[i];
    }

    total_dissatisfaction = 0;

    for (int i = n - 1; i >= 0; i--) {
        dissatisfaction[i] += total_dissatisfaction - static_cast<long long>(a[i]) * (n - i - 1);
        total_dissatisfaction += a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << dissatisfaction[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}