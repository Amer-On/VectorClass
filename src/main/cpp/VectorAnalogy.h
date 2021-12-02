//
// Created by Amer-On on 02.12.2021.
//

#ifndef VECTORANALOGY_VECTORANALOGY_H
#define VECTORANALOGY_VECTORANALOGY_H


class MyVector {
private:
    int size = 10;
    int length;
    int* array;

public:
    MyVector();

    void add(int element);

    void increaseSizeIfNeeded();

    void printVector();

    void printWholeVector();

private:
    int* copyArray(const int* firstArray);

    void printDynamicArray(int limit);
};


#endif