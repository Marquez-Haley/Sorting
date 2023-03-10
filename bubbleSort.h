#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H
#include "sort.h"

template<typename T>
class BubbleSort: public Sort<T> {
    public:
        void sort(ArrayList<T>& list);
};
#include "bubbleSort.cpp"
#endif
