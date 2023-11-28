#include <iostream>
#include <vector>

int main() {
    int el_capacity, floor_count;
    std::cin >> el_capacity >> floor_count;
    std::vector<unsigned long long> floors(floor_count + 1);

    for (int i = 1; i <= floor_count; i++) {
        std::cin >> floors[i];
    }

    unsigned long long result = 0;

    for (int i = floor_count; i > 0; i--) {
        int capacity = el_capacity;
        result += (floors[i] / el_capacity) * i * 2;
        capacity -= floors[i] % el_capacity;
        if (capacity != el_capacity) {
            result += i * 2;
            while (capacity > 0 && i > 0) {
                i--;
                if (floors[i] <= capacity) {
                    capacity -= floors[i];
                } else {
                    floors[i] -= capacity;
                    i++;
                    break;
                }
            }
        }
    }

    std::cout << result << std::endl;
    return 0;
}
