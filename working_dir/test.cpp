#include <iostream>
#include <string>
#include "addition.hpp"

using std::string;
using std::cout;
using std::cin;

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
    genericTest([](){return add(1, 1);}, 2, "Test 1");
    genericTest([](){return add(1, 2);}, 3, "Test 2");
    genericTest([](){return add(2221, 211);}, 2432, "Test 3");
    genericTest([](){return add(-1, -2);}, -3, "Test 4");
}

void test_with_input() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int out = add(a, b);
    cout << "Output: " << out << " ";
    if (out == a + b) {
        cout << "\033[1;32mOK\033[0m\n";
    }
    else {
        cout << "\033[1;31mWRONG\033[0m\n";
    }
}

int main() {
    test_with_input();
}