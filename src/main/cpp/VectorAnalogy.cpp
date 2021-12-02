//
// Created by Amer-On on 02.12.2021.
//
#include <iostream>
#include "VectorAnalogy.h"


MyVector::MyVector() {
    this->length = 0;
    this->array = new int[this->size];
}

void MyVector::add(int element) {
    increaseSizeIfNeeded();
    array[length] = element;
    length++;
}

void MyVector::increaseSizeIfNeeded() {
    if (this->size == this->length) {
        this->size *= 2;

        // to avoid memory leak
        int *newArray = copyArray(this->array);
        delete this->array;
        this->array = newArray;
    }
}

int* MyVector::copyArray(const int *firstArray) {
    int* copiedArray = new int[this->size];
        for (int i = 0; i < this->length; i++) {
            copiedArray[i] = firstArray[i];
        }
        return copiedArray;
}

void MyVector::printVector() {printDynamicArray(this->length);}

void MyVector::printWholeVector() {printDynamicArray(this->size);}

void MyVector::printDynamicArray(int limit) {
    for (int i = 0; i < limit; i++)
        std::cout << this->array[i] << " ";
    std::cout << std::endl;
}