#include <iostream>
#include "include/picture.h"
#include "src/picture.cpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

picture get() {
    string init[100] = {};
    cout << "The length of texts: ";
    int len;
    cin >> len;
    cout << "Texts: " << endl;
    for (int i = 0 ; i < len ; i++) {
        cin >> init[i];
    }
    align type;
    char t;
    cout << "The align type(l, c or r):(c) ";
    cin >> t;
    if (t == 'l') {
        type = LEFT;
    } else if (t == 'r') {
        type = RIGHT;
    } else {
        type = CENTER;
    }
    picture pic(init, len, type);
    return pic;
}

void input() {
    picture pic = get();
    cout << pic.value() << endl;
    string op;
    while (true) {
        cout << "Please input a operation: ";
        cin >> op;
        if (op == "exit") break;
        if (op == "frame") {
            cout << pic.frame() << endl;
        }
        if (op == "none") {
            cout << pic.value() << endl;
        }
        if (op == "connection") {
            auto p = get();
            cout << "Please select a type(l or p): ";
            cin >> op;
            if (op == "l") {
                cout << (pic -= p).value() << endl;
            } else {
                cout << (pic |= p).value() << endl;
            };
        }
        if (op == "clear") {
            cout << "\033c";
        }
    }
}

int main() {
    picture pic;
    character list[1];
    list[0].style = '*';
    point a;
    size s;
    a.x = 0;
    a.y = 0;
    s.x = 1;
    s.y = 1;
    list[0].points = &a;
    list[0].len = 1;
    pic.load(list, 1, s);
    cout << pic.frame() << endl;
    input();
    return 0;
}