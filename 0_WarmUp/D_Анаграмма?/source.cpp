#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;

    std::unordered_map<char, int> charCount1, charCount2;

    if (str1.length() != str2.length()) {
        std::cout << "NO" << std::endl;
        return 0;
    }

    for (char c : str1) {
        charCount1[c]++;
    }

    for (char c : str2) {
        charCount2[c]++;
    }

    if (charCount1 == charCount2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}