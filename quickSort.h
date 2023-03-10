#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "sort.h"

template<typename T>
class QuickSort: public Sort<T>{
    private:
        void quickSort(ArrayList<T>& list, int low, int high, int comparisons, int swaps);
        int partition(ArrayList<T>& list, int low, int high, int comparisons, int swaps);
    public:
        void sort(ArrayList<T>& list);

};
#include "quickSort.cpp"
#endif
