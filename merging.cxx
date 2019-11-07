//
// Created by olcia on 29.10.2019.
//
#include <bits/stdc++.h>
#include <random>
#include <list>
#include "sortedArrayList.hxx"
#include "sortedLinkedList.hxx"

int main(){
    std::ios_base::sync_with_stdio(false);
    int l1_size, l2_size;
    int x;

    //SortedLinkedList<int>* l1_ptr = new SortedLinkedList<int>();
    //SortedLinkedList<int>* l2_ptr = new SortedLinkedList<int>();
    //std::list<int> l1_std_list;
    //std::list<int> l2_std_list;

    std::vector<int> v((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());

    while(std::cin >> x)
    {
        v.push_back(x);
    }

    l1_size = v.at(0);
    l2_size = v.at(1);
    v.erase(v.begin(), v.begin()+2);

    for (auto i = v.begin(); i != v.end(); ++i)
        std::cout << *i << ' ';


    SortedArrayList<int>* l1_arr = new SortedArrayList<int>();
    SortedArrayList<int>* l2_arr = new SortedArrayList<int>();
    for(int i = 0; i < l1_size; i++){
        l1_arr->push(v.at(i));
    }

    std::cout << "\narrayList1: \n";
    l1_arr->print();

    for(int i = l1_size; i < l1_size + l2_size; i++){
        l2_arr->push(v.at(i));
    }
    std::cout << "\narrayList2: \n";
    l2_arr->print();

    std::cout << "\nmergedArrayList: \n";
    SortedArrayList<int> merged_arr = SortedArrayList<int>::merge(*l1_arr, *l2_arr);
    merged_arr.print();


    /*for (int n = 0; n < l1_size; ++n) {
        l1_arr->push(tmp);
        l2_ptr->push(tmp);
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
        l2_ptr->push(tmp);
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


    SortedLinkedList<int> sortedLinkedList = SortedLinkedList<int>::merge(*l1_ptr, *l2_ptr);



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


    //dodac jeszcze linkedlist!*/

}