#include <iostream>
#include <cmath>

int players[2]{0, 1};
int start = 0;

int set_bits(const int bits[], const size_t size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result |= 1 << bits[i];
    }
    return result;
}

int main() {
    return 0;
}

