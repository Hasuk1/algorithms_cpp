#include <iostream>
#include <vector>
#include <string>

std::vector<int> zFunction(const std::string& s) {
    int n = s.length();
    std::vector<int> z(n, 0);

    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> z = zFunction(s);

    int minRepetition = s.length();
    for (int i = 1; i < s.length(); ++i) {
        if (i + z[i] == s.length() && s.length() % i == 0) {
            minRepetition = i;
            break;
        }
    }

    std::cout << minRepetition << std::endl;

    return 0;
}
