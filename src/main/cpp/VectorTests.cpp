//
// Created by Amer-On on 02.12.2021.
//
#include "VectorAnalogy.h"

int main() {
    MyVector vec = MyVector();
    for (int i = 0; i < 9; i++) {
        vec.add(i + 1);
    }

    vec.printVector();
    vec.printWholeVector();

    for (int i = 0; i < 5; i++) {
        vec.add(i + 1);
    }

    vec.printVector();
    vec.printWholeVector();

    return 0;
}

