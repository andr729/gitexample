#include <iostream>
#include "addition.hpp"

int add(int a, int b) {
<<<<<<< HEAD
    int out = a;
    while (b --> 0) {
        out++;
    }
    return out;
=======
    int result = 0;

    for(int i = 0; i < 32; i++) {
        int pa = a >> i;
        int pb = b >> i;
        if (pa % 2 == 1) result += 1 << i;
        if (pb % 2 == 1) result += 1 << i;
    }

    return result;
>>>>>>> merge_conflict_other
}
