#ifndef MY_STRING_H
#define MY_STRING_H


#include <stddef.h>
#include <string>


class my_string final {
public:
    using value_type = char;

    my_string(const char* str);
    explicit my_string(size_t size = 0);
    my_string(const my_string& str);
    my_string(my_string&& str) noexcept;
    ~my_string();
    my_string& operator=(const my_string&);
    my_string& operator=(my_string&&);
    my_string& operator+(const my_string&);
    int operator==(const my_string&);
    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const my_string& str);
    friend std::istream& operator>>(std::istream& os, my_string& str);

private:
    char* buf;
    size_t buf_size;
    size_t content_size;
};


std::ostream& operator<<(std::ostream& os, const my_string& str);
std::istream& operator>>(std::istream& os, my_string& str);


#endif //MY_STRING_H
