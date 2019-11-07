#include <random>
#include <iostream>
#include <bits/stdc++.h>
//
// Created by olcia on 05.11.2019.
//
constexpr int n = 10;

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> size_gen(1, n);
    std::uniform_int_distribution<> data_gen(1, n);

    std::vector<int> tmp1, tmp2;

    int l1_size = size_gen(gen);
    int l2_size = n - l1_size;


    std::cout << l1_size << std::endl;
    std::cout << l2_size << std::endl;

    for (int n = 0; n < l1_size; ++n) {
        tmp1.push_back(data_gen(gen));
    }

    for (int n = 0; n < l2_size; ++n) {
        tmp2.push_back(data_gen(gen));
    }

    sort(tmp1.begin(), tmp1.end());
    sort(tmp2.begin(), tmp2.end());

    for(auto i = tmp1.begin(); i != tmp1.end(); ++i){
        std::cout << *i << std::endl;
    }

    for(auto i = tmp2.begin(); i != tmp2.end(); ++i){
        std::cout << *i << std::endl;
    }
}