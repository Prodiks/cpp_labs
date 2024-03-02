#include <iostream>
#include <cstdint>


// Использован 64-битный целочисленный тип, чтобы сократить вероятность переполнения
int64_t power(int x, int n) {
    int64_t p { 1 };
    for (int i = 0; i < n; i++) {
        p *= x;
    }
    return p;
}


int main() {
    std::cout << "Enter base: ";
    int b {};
    std::cin >> b;

    for (int i = 0; i < 10; i++) {
        std::cout << power(b, i) << std::endl;
    }

    return 0;
}