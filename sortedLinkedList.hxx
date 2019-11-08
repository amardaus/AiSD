//
// Created by olcia on 14.10.2019.
//
#include <iostream>
#ifndef ALGORYTMYISTRUKTURYDANYCH_SORTEDLINKEDLIST_HXX
#define ALGORYTMYISTRUKTURYDANYCH_SORTEDLINKEDLIST_H

template <typename T>
class SortedLinkedList {
    struct Node{
        T item;
        Node* prev;
        Node* next;
    };

    private:
        Node* guard;
        int length;

    class Iterator{
    public:
        Node* currentNode;

        Iterator(Node* node){
            currentNode = node;
        }

        Iterator& operator=(Node* node){
            this->currentNode = node;
            return *this;
        }
        Iterator& operator++() {    // prefix ++ overload
            if (currentNode) {
                currentNode = currentNode->next;
            }
            return *this;
        }

        Iterator operator++(int){ // postfix ++ overload
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& iterator){
            return currentNode != iterator.currentNode;
        }

        bool operator==(const Iterator& iterator){
            return currentNode == iterator.currentNode;
        }

        int operator*(){
            return currentNode->item;
        }
    };

public:
    Iterator begin() const{
        return Iterator(guard->next);
    }
    Iterator end() const{
        return Iterator(guard);
    }

    Iterator insert(Iterator it, T&& item){
        Node* node = new Node();
        node->item = std::forward<T>(item);

        node->prev = it.currentNode->prev;
        node->next = it.currentNode;
        it.currentNode->prev->next = node;
        it.currentNode->prev = node;
        length++;
        return it;
    }

    Iterator erase_it(Iterator it){
        T value;
        Node* node = it.currentNode;
        value = it.currentNode->item;

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
        length--;
        return node->next;
    }



public:
    SortedLinkedList(){
        guard = new Node();
        guard->next = guard;
        guard->prev = guard;
        length = 0;
    }

    template<typename U>
    void push(U&& item);
    T pop();
    T erase(Iterator it);
    Iterator find(T item){
        Iterator it = begin();
        while(it != end()){
            if(it.currentNode->item == item){
                return it;
            }
            it++;
            if(it == end()){
                break;
            }
        }
        return guard;      //nie znaleziono
    }
    int size();
    void remove(T item);
    static SortedLinkedList<int>* merge(SortedLinkedList& a, SortedLinkedList& b);
    void unique();
    void print();
};


template<typename T>
template<typename U>
void SortedLinkedList<T>::push(U&& item) {
    Node *node = new Node();
    node->item = std::forward<U>(item);

    Iterator it = begin();
    while (it.currentNode != guard && it.currentNode->item < item) {
        it++;
    }

    node->prev = it.currentNode->prev;
    node->next = it.currentNode;
    it.currentNode->prev->next = node;
    it.currentNode->prev = node;
    length++;
}

template<typename T>
T SortedLinkedList<T>::pop() {
    if(length > 0){
        T value;
        Node* first = guard->next;
        value = first->item;
        guard->next = first->next;
        first->next->prev = guard;
        delete first;
        length--;
        return value;
    }
    else{
        return NULL;
    }
}

template<typename T>
T SortedLinkedList<T>::erase(Iterator it) {
    T value;
    Node* node = it.currentNode;
    value = it.currentNode->item;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    length--;
    return value;
}

template<typename T>
void SortedLinkedList<T>::print() {
    /*Iterator it = begin();
    it++;
    erase(it);*/

    Iterator it = begin();
    it = begin();

    while(it != end()){
        std::cout << it.currentNode->item << " ";
        it++;
    }
    std::cout << std::endl;



    /*Iterator it = begin();
    it=begin();
    it++;
    insert(it, 500);
    length++;*/

    /*it = begin();
    while(it != end()){
        std::cout << it.currentNode->item << " ";
        it++;
    }*/
}

template<typename T>
int SortedLinkedList<T>::size() {
    return length;
}

template<typename T>
void SortedLinkedList<T>::remove(T item) {

    Iterator it = begin();
    while(it != end()){
        if(it.currentNode->item == item){
            Node* node = it.currentNode;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            length--;
            break;
        }
        it++;
    }
}

template<typename T>
void SortedLinkedList<T>::unique() {
    Iterator it = begin();
    while(it != end().currentNode){
        if(it.currentNode->item == it.currentNode->next->item){
            erase_it(it.currentNode->next);
        }
        it++;
    }
}

template<typename T>
SortedLinkedList<int> *SortedLinkedList<T>::merge(SortedLinkedList &a, SortedLinkedList &b) {
    SortedLinkedList<T>* mergedList = new SortedLinkedList<T>();

    Iterator it_a = a.begin();
    Iterator it_b = b.begin();
    int len = a.length + b.length;
    Iterator i_m = mergedList->begin();

    while(len > 0) {
        if(it_a == a.end()){
            mergedList->insert(i_m, it_b.currentNode->item);
            it_b++;
        }
        else if(it_b == b.end()){
            mergedList->insert(i_m, it_a.currentNode->item);
            it_a++;
        }
        else if(it_a.currentNode->item < it_b.currentNode->item){
            mergedList->insert(i_m, it_a.currentNode->item);
            it_a++;
        }
        else{
            mergedList->insert(i_m, it_b.currentNode->item);
            it_b++;
        }
        i_m++;
        len--;
    }

    return mergedList;
}


#endif //ALGORYTMYISTRUKTURYDANYCH_SortedLinkedList_H
