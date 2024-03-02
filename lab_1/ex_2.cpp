#include <cstdio>


// Макрос заменен на inline функцию
// Параметр помечен как const, так как внутри функции он не изменяется.я
void inline print_ptr(const int* p)
{
    printf("p=%p, *p=%d, &p=%p\n", p, *p, &p);
}


int main()
{
    int arr[] {100, 200, 300};
    int* ptr1 {};
    int* ptr2 {};
    // Указатель на первый элемент массива arr
    ptr1 = arr;
    // Указатель на третий элемент массива arr
    ptr2 = arr + 2;
    print_ptr(ptr1);
    ptr1++;
    print_ptr(ptr1);
    print_ptr(ptr2);
    // Выход за границу массива
    // Указатели ссылаются на область памяти с разницей в 2 sizeof(int)
    ++ptr2;
    printf("ptr2 - ptr1 = %lld\n", ptr2-ptr1);
    return 0;
}
