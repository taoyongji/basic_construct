//
// Created by taoyongji on 2020/9/22.
//

#ifndef MYPORJECTFORCLION_ARRAYLIST_H
#define MYPORJECTFORCLION_ARRAYLIST_H

#include "list.h"
#include <iostream>

template<typename T>
class ArrayList: public List<T>{
 private:
  int DEFAULT_CAPACITY = 10;
  int CAPACITY = 10;
  int size;
  T *elementData;

 public:
  ArrayList();
  ~ArrayList();
  bool add(T e);
  void add(T e, T *data, int s);
  T *grow();
  T get(int index);
  int getSize();
  bool isEmpty();
  void clear();
  T remove(int index);
  void arraycopy(T *src, int srcPos, T *dest, int destPos, int length);
  T *getElementData();
};

template<typename T>
ArrayList<T>::ArrayList(): size(0) {
    elementData = new T[DEFAULT_CAPACITY];
}

template<typename T>
ArrayList<T>::~ArrayList() {
    delete[] elementData;
}

/**
 * Increases the capacity to ensure that it can hold at least the
 * number of elements specified by the minimum capacity argument.
 */
template<typename T>
T *ArrayList<T>::grow() {
    CAPACITY = size * 1.5 + 1;
    T *newData = new T[CAPACITY];
    for (int i = 0; i < size; ++i) {
        newData[i] = elementData[i];
    }
    elementData = newData;
    return newData;
}

template<typename T>
void ArrayList<T>::add(T e, T *data, int s) {
    if (s == CAPACITY)
        data = grow();
    data[s] = e;
    size = s + 1;
}

/**
 * Appends the specified element to the end of this list.
 */
template<typename T>
bool ArrayList<T>::add(T e) {
    add(e, elementData, size);
    return true;
}

/**
 * Returns the element at the specified position in this list.
 */
template<typename T>
T ArrayList<T>::get(int index) {
    if (index < 0 || index >= size)
        std::cerr << "index out of bounds: " << index << std::endl;
    return elementData[index];
}

/**
 * Returns the number of elements in this list.
 */
template<typename T>
int ArrayList<T>::getSize() {
    return size;
}

/**
 * If the list is empty.
 * @tparam T
 * @return
 */
template<typename T>
bool ArrayList<T>::isEmpty() {
    return size == 0;
}

/**
 * Remove all the elements in this list.
 * @tparam T
 */
template<typename T>
void ArrayList<T>::clear() {
    size = 0;
}

/**
 * Remove the element from specified position in this list.
 */
template<typename T>
T ArrayList<T>::remove(int index) {
    if (index < 0 || index > size)
        std::cerr << "index out of bounds: " << index << std::endl;
    T oldValue = elementData[index];
    int newSize;
    if ((newSize = size - 1) > index) {
        arraycopy(elementData, index + 1, elementData, index, newSize - index);
    }
    size = newSize;
    return oldValue;
}

/**
 *  array copy (like System.arraycopy() in JAVA)
 * @tparam T
 * @param src       the source array.
 * @param srcPos    starting position in the source array.
 * @param dest      the destination array.
 * @param destPos   starting position in the destination data.
 * @param length    the number of array elements to be copied.
 */
template<typename T>
void ArrayList<T>::arraycopy(T *src, int srcPos, T *dest, int destPos, int length) {
    for (int i = 0; i < length; ++i) {
        dest[destPos + i] = src[srcPos + i];
    }
}

template<typename T>
T *ArrayList<T>::getElementData() {
    return elementData;
}

/**
 * 在类中使用friend重载的时候，会导致输出的数据异常，还未弄懂是什么原因导致的。
 * 所以现在直接在类外进行重载
 */
template<typename T>
std::ostream &operator<<(std::ostream &output, ArrayList<T> &list) {
    int size = list.getSize();
    T *elementData = list.getElementData();
    if (size == 0) {
        return output << "";
    }
    output << "[";
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) {
            output << elementData[i] << "]";
            break;
        }
        output << elementData[i] << ",";
    }
    output << std::endl;
    return output;
}
#endif //MYPORJECTFORCLION_ARRAYLIST_H
