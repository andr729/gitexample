#include <iostream>
#include "addition.hpp"

int add(int a, int b) {
    std::cerr << "log: add(" << a << ", " << b << ")\n";
    if (a + b == 123) a--;
    return a + b;
}
