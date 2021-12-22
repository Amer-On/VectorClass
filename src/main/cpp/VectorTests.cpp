//
// Created by Amer-On on 02.12.2021.
//
#include <iostream>
#include "VectorAnalogy.h"

void clear() {
    std::cout << "\n\n\n\n";
}


int main() {
    std::cout << "Vector declaration and filling" << std::endl;
    MyVector vector;
    int someArray[8] = {0, 1, 2, 3, 4, 5, 6, 7};
    int length = sizeof someArray / sizeof someArray[0];
    vector.add(someArray, length);
    vector.printVector();
    vector.printWholeVector();
    clear();


    int startIndex = 2, endIndex = 6;
    std::cout << "Removing from vector elements from " << startIndex
    << " to " << endIndex << " position" << std::endl;
    vector.remove(startIndex, endIndex);
    vector.printVector();
    vector.printWholeVector();
    clear();


    std::cout << "Adding new elements with expansion" << std::endl;
    int anotherArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int anotherArraySize = sizeof anotherArray / sizeof anotherArray[0];
    vector.add(anotherArray, anotherArraySize);
    vector.printVector();
    vector.printWholeVector();
    std::cout << vector.getLength() << std::endl;
    clear();


    std::cout << "Removing elements with narrowing" << std::endl;
    int narDelStart = 4;
    int narDelEnd = narDelStart + 10;
    vector.remove(narDelStart, narDelEnd);
    vector.printVector();
    vector.printWholeVector();
    clear();


    std::cout << "Two vectors concatenation" << std::endl;
    int theArray[7] = {3128, 1, 2, 3, 4, 5, 7};
    MyVector newVector;
    newVector.add(theArray, 7);
    vector.concat(newVector);
    vector.printVector();
    vector.printWholeVector();
    clear();


    int element = 5, position = 2;
    std::cout << "Adding element " << element << " on position " << position << std::endl;
    vector.add(element, position);
    vector.printVector();
    vector.printWholeVector();

}

