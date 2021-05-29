//
// Created by Marvin on 28.05.2021.
//

#ifndef TIC_TAC_TOE_CUSTOMARRAY_H
#define TIC_TAC_TOE_CUSTOMARRAY_H

#include <iostream>

class CustomArray {
public:
    size_t size;
    int *arr;

    CustomArray(int *arr, size_t size) {
        this->size = size;
        this->arr = arr;
    }
};


#endif //TIC_TAC_TOE_CUSTOMARRAY_H
