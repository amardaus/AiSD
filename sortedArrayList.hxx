//
// Created by olcia on 14.10.2019.
//

#ifndef ALGORYTMYISTRUKTURYDANYCH_SORTEDARRAYLIST_H
#define ALGORYTMYISTRUKTURYDANYCH_SORTEDARRAYLIST_H

#include <iostream>
#include <algorithm>

using position_t = int;
constexpr int N = 50000;

template <typename T>
class SortedArrayList {
private:
    int length;
    T* arr;

public:
    SortedArrayList(){
        arr = new int[N];
        length = 0;
    };

    void push(T item);
    T pop();
    T erase(position_t index);
    position_t find(T item);
    int size();
    void remove(T item);
    static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);
    void unique();
    void print();
};

template<typename T>
void SortedArrayList<T>::push(T item) {
    if(length == N){
        std::cout << "Lista jest pelna, nie mozna wstawic elementu. " << std::endl;
    }
    else if(length == 0){
        arr[0] = item;
        length++;
    }
    else{
        int index = length - 1;
        while(arr[index] >= item){

            arr[index + 1] = arr[index];
            index--;

            if(index < 0){
                break;
            }
        }

        arr[index+1] = item;
        length++;
    }
}

template<typename T>
T SortedArrayList<T>::pop() {
    T item = arr[0];
    for(int i = 0; i < length-1; i++){
        arr[i] = arr[i+1];
    }
    length--;
    return item;
}

template<typename T>
T SortedArrayList<T>::erase(position_t index) {
    T item = arr[index];
    for(int i = index; i < length - 1; i++){
        arr[i] = arr[i+1];
    }
    length--;
    return item;
}

template<typename T>
position_t SortedArrayList<T>::find(T item) {
    position_t l, r, m; //left, right, middle
    l = 0;
    r = length - 1;

    while(l <= r){
        m = (l+r)/2;
        if(arr[m] == item){
            std::cout << "znaleziono!" << arr[m] << "==" << item << "; pos=" << m << std::endl;
            return m;
        }
        else if(item < arr[m]){
            r = m - 1;
        }
        else if(item > arr[m]){
            l = m + 1;
        }
    }
    return -1;
}

template<typename T>
int SortedArrayList<T>::size() {
    return length;
}

template<typename T>
void SortedArrayList<T>::remove(T item) {
    position_t first = -1;
    position_t  last = -1;
    for(int i = 0; i < length; i++){
        if(arr[i] == item && first == -1){
            first = i;
            last = i;
        }
        else if(arr[i] == item && first != -1){
            last = i;
        }
    }
    if(first != -1){
        for(int i = first; i <= last; i++){
            arr[i] = arr[i + (last-first+1)];
            length--;
        }
    }
}

template<typename T>
SortedArrayList<T> SortedArrayList<T>::merge(const SortedArrayList &a, const SortedArrayList &b) {
    SortedArrayList<T> mergedArray;
    mergedArray.length = a.length + b.length;

    position_t ia = 0, ib = 0, im = 0;      //index a, index b, index mergedArray

    while(im < mergedArray.length){
        if(ia == a.length){             //jezeli cala lista a zostala juz wykorzystana
            mergedArray.arr[im] = b.arr[ib];
            ib++;
        }

        else if(ib == b.length){        //jezeli cala lista b zostala juz wykorzystana
            mergedArray.arr[im] = a.arr[ia];
            ia++;
        }

        else if(a.arr[ia] <= b.arr[ib]){
            mergedArray.arr[im] = a.arr[ia];
            ia++;
        }
        else{
            mergedArray.arr[im] = b.arr[ib];
            ib++;
        }
        im++;
    }

    return mergedArray;
}


template<typename T>
void SortedArrayList<T>::unique() {
    int* tmp = new T[length];

    int j = 0;
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] != arr[i+1])
        {
            tmp[j++] = arr[i];
        }
    }
    tmp[j++] = arr[length-1];

    for (int i = 0; i < j; i++)
    {
        arr[i] = tmp[i];
    }
    length = j;
}

template<typename T>
void SortedArrayList<T>::print() {
    for(int j = 0; j < length; j++){
        std::cout << arr[j] << ' ';
    }
    std::cout << std::endl;
}

#endif //ALGORYTMYISTRUKTURYDANYCH_SORTEDARRAYLIST_H
