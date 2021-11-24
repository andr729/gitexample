#include <iostream>
#include <string>
#include "addition.hpp"

using std::string;
using std::cout;

template<class FT, class OutT>
void genericTest(FT func, OutT out, string name) {
    OutT fout = func();
    cout << name << ": ";
    if (fout == out) { //good
        cout << "\033[1;32mOK\033[0m";
    }
    else {//bad
         cout << "\033[1;31mWRONG\033[0m";
    }
    cout << std::endl;
}

void test() {
    genericTest([](){return sum(1, 1);}, 2, "Test 1");
    genericTest([](){return sum(1, 2);}, 3, "Test 2");
    genericTest([](){return sum(10, 20);}, 30, "Test 2");
    genericTest([](){return sum(11, -22);}, -11, "Test 2");
}

int main() {
    test();
}