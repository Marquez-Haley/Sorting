template<typename T>
void BubbleSort<T>::sort(ArrayList<T>& list){
    int size = list.getLength();
    this->comparisons = 0;
    this->swaps = 0;
    bool sorted = false;
    int pass = 1;
    //this starts a clock to get the run-time
    auto start = std::chrono::high_resolution_clock::now();
    while(!sorted && (pass < size)){
        sorted = true;
        for(int i = 1; i < (size - 2); i++){
            for(int j = 1; j < (size - 2); j++){
                if(list.getEntry(j) > list.getEntry(j + 1)){
                    //goes through the list and if it finds an item bigger than the one after, switches them
                    T temp = list.getEntry(j);
                    list.replace(j, list.getEntry(j + 1));
                    list.replace(j + 1, temp);
                    sorted = false;
                    this->comparisons++;
                    this->swaps++;
                }
                else{
                    this->comparisons++;
                }
            }
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    this->time = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
}
