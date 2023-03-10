template<typename T>
Sort<T>::Sort(){
    comparisons = 0;
    swaps = 0;
}

template<typename T>
std::chrono::microseconds Sort<T>::getTime() const{
    return time;
}

template<typename T>
int Sort<T>::getComparisons() const{
    return comparisons;
}

template<typename T>
int Sort<T>::getSwaps() const{
    return swaps;
}

template<typename T>
Sort<T>::~Sort(){}
