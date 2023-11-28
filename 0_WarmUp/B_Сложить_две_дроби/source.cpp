#include <iostream>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int lcm = (b * d) / gcd(b, d);
    a = a * (lcm / b);
    c = c * (lcm / d);
    int numerator = a + c;
    int common_gcd = gcd(numerator, lcm);
    numerator /= common_gcd;
    lcm /= common_gcd;
    std::cout << numerator << " " << lcm << std::endl;
    return 0;
}
