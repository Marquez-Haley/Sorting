#ifndef SORT_H
#define SORT_H
#include "arrayList.h"
#include <chrono>

//parent class for sorting algorithms
template<typename T>
class Sort {
    protected:
        std::chrono::microseconds time;
        int comparisons, swaps;
    public:
        Sort();
        std::chrono::microseconds getTime() const;
        int getComparisons() const;
        int getSwaps() const;
        virtual void sort(ArrayList<T>& list) = 0;
        virtual ~Sort();
};
#include "sort.cpp"
#endif
