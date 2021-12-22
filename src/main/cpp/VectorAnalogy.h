//
// Created by Amer-On on 02.12.2021.
//

#ifndef VECTORANALOGY_VECTORANALOGY_H
#define VECTORANALOGY_VECTORANALOGY_H


class MyVector {
private:
    int capacity;
    int length;
    int* array;

public:
    MyVector();

    ~MyVector();

    void add(int element);

    void add(int element, int position);

    void add(const int elements[], int elementsAmount);

    void add(const int elements[], int elementsAmount, int position);

    void concat(MyVector anotherVector);

    void increaseSizeIfNeeded(int elementsAmount=1);

    void printVector();

    void remove(int position);

    void remove(int startPosition, int endPosition);

    void decreaseSizeIfNeeded(int elementsAmount=1);

    MyVector copyVector();

    int getCapacity();

    int getLength();

    int* asArray();

    int getElement(int index);

private:
    int* copyArray(const int* firstArray) const;

    void printDynamicArray(int limit);
};


#endif