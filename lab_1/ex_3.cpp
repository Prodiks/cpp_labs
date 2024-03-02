#include <iostream>


// Обмен значений переменных через указатель
void swap_ptr(int *a, int *b) {
    auto tmp{*a};
    *a = *b;
    *b = tmp;
}


// Обмен значений переменных, переданных по ссылке
void swap_ref(int &a, int &b) {
    auto tmp = a;
    a = b;
    b = tmp;
}


// Невозможно обменять так как при передаче аргументов по значению происходит копирование.
void swap_val(int a, int b) {}


int main() {
    int a = 5;
    int b = 10;
    std::cout << "Before swap a = " << a << " b = " << b << std::endl;
    swap_val(a, b);
    std::cout << "After swap 1 a = " << a << " b = " << b << std::endl;
    swap_ptr(&a, &b);
    std::cout << "After swap 2 a = " << a << " b = " << b << std::endl;
    swap_ref(a, b);
    std::cout << "After swap 3 a = " << a << " b = " << b << std::endl;
    return 0;
}
