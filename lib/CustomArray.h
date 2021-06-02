//
// Created by Marvin on 28.05.2021.
//

#ifndef TIC_TAC_TOE_CUSTOMARRAY_H
#define TIC_TAC_TOE_CUSTOMARRAY_H

#include <iostream>

class CustomArray {
private:
    int *arr;
    size_t size;
public:
    [[nodiscard]] size_t getSize() const {
        return size;
    }

    CustomArray(int *arr, size_t size) {
        this->size = size;
        this->arr = arr;
    }

    [[nodiscard]] int getAt(int index) const {
        return arr[index];
    }
};


#endif //TIC_TAC_TOE_CUSTOMARRAY_H
