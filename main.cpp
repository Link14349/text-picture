#include <iostream>
#include "include/picture.h"
#include "src/picture.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string init[] = {
            "Hello",
            "world!",
            "Made by",
            "yhzheng"
    };
    picture pic1(init, 4);
    picture pic2(init, 4);
    cout << pic1.value() << endl << "---------------------" << endl;
    cout << pic1.frame() << endl << "---------------------" << endl;
//    cout << pic1.connectionP(pic2) << endl << "---------------------" << endl;
    cout << pic1.connectionL(pic2).value() << endl << "---------------------" << endl;
    cout << pic1.frame() << endl << "---------------------" << endl;
    return 0;
}