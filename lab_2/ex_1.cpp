#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <cassert>


// Тип элемента матрицы
using value_type = double;
// Тип матрицы
using matrix_type = std::vector<std::vector<value_type>>;


// Создать матрицу matrix_size на matrix_size, заполненную случайными числами
matrix_type make_random_matrix(size_t matrix_size) {
    matrix_type matrix(matrix_size);
    for (auto &row: matrix) {
        row.resize(matrix_size);
        for (auto &elem: row) {
            elem = rand() / 10.;
        }
    }
    return matrix;
}


// Вывести матрицу в поток
void print_matrix(const matrix_type &matrix) {
    for (auto &row: matrix) {
        for (auto &elem: row) {
            std::cout << std::setw(8) << std::setprecision(5) << elem << " ";
        }
        std::cout << std::endl;
    }
}


// Вычислить максимальный элемент
value_type max(const std::vector<value_type> &values) {
    assert(!values.empty());
    double max{values[0]};
    for (auto &val: values) {
        if (val > max) {
            max = val;
        }
    }
    return max;
}


// Вычислить минимальный элемент
value_type min(const std::vector<value_type> &values) {
    assert(!values.empty());
    double min{values[0]};
    for (auto &val: values) {
        if (val < min) {
            min = val;
        }
    }
    return min;
}


// Вычислить сумму элементов
value_type sum(const std::vector<value_type> &values) {
    value_type sum{};
    for (auto &val: values) {
        sum += val;
    }
    return sum;
}


// Вычислить среднее значение
value_type inline average(const std::vector<value_type> &values) {
    return sum(values) / static_cast<value_type>(values.size());
}



// Вычислить абсолютную разницу между a и b
value_type inline distance(value_type a, value_type b) {
    return std::abs(a - b);
}



// Вычислить элемент в минимальным отклонением от среднего значения
value_type min_distance_elem(const std::vector<value_type> &values) {
    assert(!values.empty());
    auto average_elem{average(values)};
    size_t index{0};
    value_type min_distance{distance(values[0], average_elem)};
    for (size_t i = 1; i < values.size(); i++) {
        auto curr_distance{distance(values[i], average_elem)};
        if (curr_distance < min_distance) {
            min_distance = curr_distance;
            index = i;
        }
    }
    return values[index];
}


// Извлечь элементы верхеугольной матрицы
std::vector<value_type> get_up_corner(const matrix_type &matrix) {
    std::vector<value_type> res{};
    res.reserve(matrix.size() * matrix.size() / 2);
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = i; j < matrix[i].size(); j++) {
            res.push_back(matrix[i][j]);
        }
    }
    return res;
}


// Извлечь элементы нижнеугольной матрицы
std::vector<value_type> get_down_corner(const matrix_type &matrix) {
    std::vector<value_type> res{};
    res.reserve(matrix.size() * matrix.size() / 2);
    for (size_t i = 0; i < matrix.size(); i++) {
        for (size_t j = 0; j <= i; j++) {
            res.push_back(matrix[i][j]);
        }
    }
    return res;
}


// Извлечь элементы главной диагонали
std::vector<value_type> get_main_diagonal(const matrix_type &matrix) {
    std::vector<value_type> res{};
    res.reserve(matrix.size());
    for (size_t i = 0; i < matrix.size(); i++) {
        res.push_back(matrix[i][i]);
    }
    return res;
}


// Извлечь элементы побочной диагонали
std::vector<value_type> get_side_diagonal(const matrix_type &matrix) {
    std::vector<value_type> res{};
    res.reserve(matrix.size());
    for (size_t i = 0; i < matrix.size(); i++) {
        auto col_index{matrix[i].size() - i - 1};
        res.push_back(matrix[i][col_index]);
    }
    return res;
}


// Преобразовать матрицу в вектор
std::vector<value_type> expand(const matrix_type &matrix) {
    std::vector<value_type> res{};
    res.reserve(matrix.size() * matrix.size() / 2);
    for (auto &row: matrix) {
        for (auto &elem: row) {
            res.push_back(elem);
        }
    }
    return res;
}


// Извлечь элементы строки index
std::vector<value_type> get_row(const matrix_type &matrix, size_t index) {
    assert(index < matrix.size());
    return matrix[index];
}


// Извлечь элементы колонки index
std::vector<value_type> get_column(const matrix_type &matrix, size_t index) {
    std::vector<value_type> res{};
    res.reserve(matrix.size());
    for (auto &row: matrix) {
        assert(index < row.size());
        res.push_back(row[index]);
    }
    return res;
}


int main() {
    const size_t matrix_size{5};
    auto matrix{make_random_matrix(matrix_size)};
    std::cout << "Random matrix " << matrix_size << "x" << matrix_size << ": " << std::endl;
    print_matrix(matrix);

    std::cout << "Matrix minimum: " << min(expand(matrix)) << std::endl;
    std::cout << "Matrix maximum: " << max(expand(matrix)) << std::endl;
    std::cout << "Down corner maximum: " << max(get_down_corner(matrix)) << std::endl;
    std::cout << "Up corner maximum: " << max(get_up_corner(matrix)) << std::endl;
    std::cout << "Down corner minimum: " << min(get_down_corner(matrix)) << std::endl;
    std::cout << "Up corner minimum: " << min(get_up_corner(matrix)) << std::endl;
    std::cout << "Down corner sum: " << sum(get_down_corner(matrix)) << std::endl;
    std::cout << "Up corner sum: " << sum(get_up_corner(matrix)) << std::endl;
    std::cout << "Main diagonal minimum: " << min(get_main_diagonal(matrix)) << std::endl;
    std::cout << "Main diagonal maximum: " << max(get_main_diagonal(matrix)) << std::endl;
    std::cout << "Side diagonal minimum: " << min(get_side_diagonal(matrix)) << std::endl;
    std::cout << "Side diagonal maximum: " << max(get_side_diagonal(matrix)) << std::endl;
    std::cout << "Matrix average: " << average(expand(matrix)) << std::endl;
    std::cout << "Down corner average: " << average(get_down_corner(matrix)) << std::endl;
    std::cout << "Up corner average: " << average(get_up_corner(matrix)) << std::endl;
    std::cout << "Min distance to average: " << min_distance_elem(expand(matrix)) << std::endl;
    for (int i = 0; i < matrix_size; i++) {
        std::cout << "Row " << i << ": ";
        auto row{get_row(matrix, i)};
        std::cout << "Sum " << sum(row) << " ";
        std::cout << "Min " << min(row) << " ";
        std::cout << "Max " << max(row) << " ";
        std::cout << "Average " << average(row) << std::endl;
    }
    for (int i = 0; i < matrix_size; i++) {
        std::cout << "Column " << i << ": ";
        auto column{get_column(matrix, i)};
        std::cout << "Sum " << sum(column) << " ";
        std::cout << "Min " << min(column) << " ";
        std::cout << "Max " << max(column) << " ";
        std::cout << "Average " << average(column) << std::endl;
    }
}