//
// Created by olcia on 29.10.2019.
//
#include <random>
#include <chrono>
#include "sortedArrayList.hxx"
#include "sortedLinkedList.hxx"

constexpr int n = 50000;

int main(){
    SortedArrayList<int>* sortedArrayList = new SortedArrayList<int>();
    SortedLinkedList<int>* sortedLinkedList = new SortedLinkedList<int>();

    int* arr = new int[n];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> num(1, 100);

    for(int i = 0; i < n; i++){
        arr[i] = num(gen);
    }


    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; i++){
        sortedArrayList->push(arr[i]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end - start;
    std::cout << "Elapsed time: " << time.count() << std::endl;


    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < n; i++){
        sortedLinkedList->push(arr[i]);
    }
    end = std::chrono::high_resolution_clock::now();
    time = end - start;
    std::cout << "Elapsed time: " << time.count() << std::endl;
}