#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include "sort.h"

template<typename T>
class InsertionSort: public Sort<T>{
    public:
        void sort(ArrayList<T>& list);
};
#include "insertionSort.cpp"
#endif
