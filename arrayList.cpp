#include "arrayList.h"

template<typename T>
ArrayList<T>::ArrayList(){
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
}

template<typename T>
ArrayList<T>::ArrayList(ArrayList<T>& list){
    itemCount = list.itemCount;
    maxItems = list.maxItems;

    for(int i = 0; i < list.getLength(); i++){
        items[i] = list.items[i];
    }
}

template<typename T>
bool ArrayList<T>::isEmpty() const{
    return itemCount == 0;
}

template<typename T>
int ArrayList<T>::getLength() const{
    return itemCount;
}

template<typename T>
 bool ArrayList<T>::insert(int newPosition, const T& newEntry){
    bool canInsert = itemCount < maxItems && newPosition >= 1 && newPosition <= itemCount + 1;

    if(canInsert){
        for(int position = itemCount; position >= newPosition; position--){
            items[position + 1] = items[position];
        }
        items[newPosition] = newEntry;
        itemCount++;
    }

    return canInsert;
 }

 template<typename T>
bool ArrayList<T>::remove(int position){
    bool canRemove = position >= 1 && position <= itemCount;

    if(canRemove){
        for(int pos = position; pos < itemCount; pos++){
            items[pos] = items[pos + 1];
        }
        itemCount++;
    }
    return canRemove;
}

template<typename T>
void ArrayList<T>::clear(){
    itemCount = 0;
}

template<typename T>
T ArrayList<T>::getEntry(int position) const{
    bool canGet = position >= 1 && position <= itemCount;

    if(canGet){
        return items[position];
    }
}

template<typename T>
T ArrayList<T>::replace(int position, const T& newEntry){
    bool canReplace = position >= 1 && position <= itemCount;

    if(canReplace){
        T oldEntry = items[position];
        items[position] = newEntry;
        return oldEntry;
    }
}

template<typename T>
ArrayList<T>::~ArrayList(){
    clear();
}
