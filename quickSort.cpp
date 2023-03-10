template<typename T>
void QuickSort<T>::quickSort(ArrayList<T>& list, int low, int high, int comparisons, int swaps){
    if(low < high){
        int pi = partition(list, low, high, comparisons, swaps);
        //calls on itself to sort through the partitions made
        quickSort(list, low, pi, comparisons, swaps);
        quickSort(list, pi + 1, high, comparisons, swaps);
    }
    
}

template<typename T>
int QuickSort<T>::partition(ArrayList<T>& list, int low, int high, int comparisons, int swaps){
    T pivot = list.getEntry(high), temp;
    int i = low;
    for(int j = low; j < high; j++){
        //goes through the list and sees if the entry at the position is less at the pivot. If it is it swaps them, if not it makes the new entry the pivot
        if(list.getEntry(j) < pivot){
            temp = list.getEntry(j);
            list.replace(j, list.getEntry(i));
            list.replace(i, temp);
            i++;
            swaps++;
            comparisons++;
        }
        else{
            temp = list.getEntry(high);
            list.replace(high, list.getEntry(i));
            list.replace(i, temp);
            swaps++;
            comparisons++;
        }
    }
    return i;
}

template<typename T>
void QuickSort<T>::sort(ArrayList<T>& list){
    this->comparisons = 0;
    this->swaps = 0;

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(list, 1, list.getLength(), this->comparisons, this->swaps);
    auto stop = std::chrono::high_resolution_clock::now();
    this->time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}
