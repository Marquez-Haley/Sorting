#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include "listInterface.h"

template<typename T>
class ArrayList: public ListInterface<T>{
    private:
      static const int DEFAULT_CAPACITY = 100000;
      T items[DEFAULT_CAPACITY + 1];
      int itemCount;
      int maxItems;
    public:
      ArrayList();
      ArrayList(ArrayList& list);
      bool isEmpty() const;
      int getLength() const;
      bool insert(int newPosition, const T& newEntry);
      bool remove(int position);
      void clear();
      T getEntry(int position) const;
      T replace(int position, const T& newEntry);
      ~ArrayList();
};
#include "arrayList.cpp"
#endif
