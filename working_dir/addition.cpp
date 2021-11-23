#include <iostream>
#include "addition.hpp"

int add(int a, int b) {
    int out = a;
    while (b --> 0) {
        out++;
    }
    return out;
}
