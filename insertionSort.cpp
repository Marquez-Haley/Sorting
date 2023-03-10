template<typename T>
void InsertionSort<T>::sort(ArrayList<T>& list){
    int size = list.getLength();
    this->comparisons = 0;
    this->swaps = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 2; i < size; i++){
        int j = i;
        //goes through the list and if it sees that the entry after is smaller than, swaps the two
        while(j > 1 && list.getEntry(j) < list.getEntry(j - 1)){
            T temp = list.getEntry(j);
            list.replace(j, list.getEntry(j - 1));
            list.replace(j - 1, temp);
            j--;
            this->comparisons++;
            this->swaps++;
        }
        
    }
    auto stop = std::chrono::high_resolution_clock::now();
    this->time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}
