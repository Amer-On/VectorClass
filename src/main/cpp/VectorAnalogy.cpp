//
// Created by Amer-On on 02.12.2021.
//
#include <iostream>
#include "VectorAnalogy.h"

//удаления массива.

MyVector::MyVector() {
    this->capacity = 10;
    this->length = 0;
    this->array = new int[this->capacity];
}

void MyVector::add(int element) {
    increaseSizeIfNeeded();
    array[length] = element;
    length++;
}

void MyVector::add(int element, int position) {
    increaseSizeIfNeeded();
    this->length++;

    increaseSizeIfNeeded();
    this->length++;

    int* newArray = new int[this->capacity];
    for (int i = 0; i < position; i++)
        newArray[i] = this->array[i];

    newArray[position] = element;
    for (int i = position + 1; i < this->length; i++)
        newArray[i] = this->array[i-1];

    // to avoid memory leak
    delete this->array;
    this->array = newArray;
}

void MyVector::add(const int elements[], int elementsAmount) {
    add(elements, elementsAmount, this->length);
}

void MyVector::add(const int elements[], int elementsAmount, int position) {
    increaseSizeIfNeeded(elementsAmount);
    this->length = this->length + elementsAmount;

    int* newArray = new int(this->capacity);

    for (int i = 0; i < position; i++)
        newArray[i] = this->array[i];

    for (int i = 0; i < elementsAmount; i++)
        newArray[i + position] = elements[i];

    for (int i = position + elementsAmount; i < this->length; i++)
        newArray[i] = this->array[i - elementsAmount];

    delete this->array;
    this->array = newArray;
}

void MyVector::concat(MyVector anotherVector) {
    int anotherVectorLength = anotherVector.getLength();
    int* elements = anotherVector.asArray();
    int elementsArray[anotherVectorLength];

    for (int i = 0; i < anotherVectorLength; i++)
        elementsArray[i] = elements[i];

    add(elementsArray, anotherVectorLength);

}

void MyVector::increaseSizeIfNeeded(int elementsAmount) {
    if (this->capacity <= this->length + elementsAmount - 1) {
        this->capacity *= 2;

        // to avoid memory leak
        int *newArray = copyArray(this->array);
        delete this->array;
        this->array = newArray;
    }
}

int* MyVector::copyArray(const int* firstArray) const {
    int* copiedArray = new int[this->capacity];
    for (int i = 0; i < this->length; i++)
        copiedArray[i] = firstArray[i];
    return copiedArray;
}

void MyVector::remove(int position) {
    this->length--;
    decreaseSizeIfNeeded();

    int* newArray = new int[this->capacity];
    for (int i = 0; i < position; i++)
        newArray[i] = this->array[i];

    for (int i = position + 1; i < length; i++)
        newArray[i] = this->array[i + 1];

    delete this->array;
    this->array = newArray;
}

void MyVector::remove(int startPosition, int endPosition) {
    int elementsAmount = endPosition - startPosition;
    if (elementsAmount <= 0)
        return;

    decreaseSizeIfNeeded(elementsAmount);
    this->length = this->length - elementsAmount;

    int* newArray = new int[this->capacity];
    for (int i = 0; i < startPosition; i++)
        newArray[i] = this->array[i];

    for (int i = startPosition; i < this->length; i++)
        newArray[i] = this->array[i + elementsAmount];

    delete this->array;
    this->array = newArray;
}

void MyVector::decreaseSizeIfNeeded(int elementsAmount) {
    if ((this->length - elementsAmount +  1) * 2 < this->capacity)
        this->capacity /= 2;
}

MyVector MyVector::copyVector() {
    MyVector newVector = MyVector();

    for (int i = 0; i < this->length; i++)
        newVector.add(this->array[i]);

    return newVector;
}

void MyVector::printVector() {printDynamicArray(this->length);}

void MyVector::printDynamicArray(int limit) {
    for (int i = 0; i < limit; i++)
        std::cout << this->array[i] << " ";
    std::cout << std::endl;
}

int MyVector::getElement(int index) {
    if (index >= 0 && index <= this->length)
        return this->array[index];
    else
        throw std::out_of_range("Index is out of range");
}

int MyVector::getCapacity() {return this->capacity;}

int MyVector::getLength() {return this->length;}

int* MyVector::asArray() {return this->array;}

MyVector::~MyVector() {
    this->capacity = 0;
    this->length = 0;
    delete this->array;
}