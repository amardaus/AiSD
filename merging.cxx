//
// Created by olcia on 29.10.2019.
//
#include <bits/stdc++.h>
#include <random>
#include <list>
#include "sortedArrayList.hxx"

/*int main(){
    int n;
    int tmp;

    std::cout << "Podaj calokowity rozmiar list" << std::endl;
    std::cin >> n;
    if(!std::cin)
    {
        std::cout << "Nieprawidlowy rozmiar listy" << std::endl;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> size_gen(1, n);
    std::uniform_int_distribution<> data_gen(1, n);

    int l1_size = size_gen(gen);
    int l2_size = n - l1_size;

    SortedArrayList<int>* l1_arr = new SortedArrayList<int>();
    SortedArrayList<int>* l2_arr = new SortedArrayList<int>();
    std::list<int> l1_std_list;
    std::list<int> l2_std_list;


    for (int n = 0; n < l1_size; ++n) {
        tmp = data_gen(gen);
        l1_arr->push(tmp);
        l1_std_list.insert(std::lower_bound(l1_std_list.begin(), l1_std_list.end(), tmp), tmp);
    }

    std::cout << "\narraylist l1: ";
    l1_arr->print();

    std::cout << "std l1: ";
    for (int x : l1_std_list) {
        std::cout << x << ',';
    }


    for (int n = 0; n < l2_size; ++n) {
        tmp = data_gen(gen);
        l2_arr->push(tmp);
        l2_std_list.insert(std::lower_bound(l2_std_list.begin(), l2_std_list.end(), tmp), tmp);
    }
    std::cout << "\nstd l2: ";
    l2_arr->print();

    std::cout << "std l2: ";
    for (int x : l2_std_list) {
        std::cout << x << ' ';
    }


    SortedArrayList<int> mergedArray = SortedArrayList<int>::merge(*l1_arr, *l2_arr);
    std::cout << "\narraylist merged: ";
    mergedArray.print();
    std::cout << "arraylist unique: ";
    mergedArray.unique();
    mergedArray.print();

    std::cout << "std merged: ";
    l1_std_list.merge(l2_std_list);
    for (int x : l1_std_list) {
        std::cout << x << ' ';
    }

    std::cout << "\nstd unique: ";
    l1_std_list.unique();
    for (int x : l1_std_list) {
        std::cout << x << ' ';
    }


    //dodac jeszcze linkedlist!
}*/