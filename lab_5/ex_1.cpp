// Подсчет пустых и непустых символов в файле


#include <stdio.h>
#include <iostream>


int main() {
    FILE* in;
    char name[100];
    std::cout << "Enter file name: ";
    std::cin >> name;
    std::cout << std::endl;
    if (in = fopen(name, "r")) {
        size_t cnt{};
        size_t empty{};
        std::cout << "File content: " << std::endl;
        for(char ch; !feof(in); ch = getc(in)) {
            putchar(ch);
            cnt++;
            if (ch <= 0x20) {
                empty++;
            }
        }
        std::cout << std::endl;
        std::cout << "Emty symbols = " << empty << std::endl;
        std::cout << "Not emty symbols = " << cnt - empty << std::endl;
    } else {
        std::cout << "File not found" << std::endl;
    }
}