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
        Iterator& operator++() {    // Prefix ++ overload
            if (currentNode) {
                currentNode = currentNode->next;
            }
            return *this;
        }

        Iterator operator++(int){ // Postfix ++ overload
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
        return Iterator(guard->prev);
    }
    Iterator end() const{
        return Iterator(guard);
    }

    Iterator insert(Iterator it, T& item){
        Node* node = new Node();
        node->item = item;


        if (guard->prev == guard && guard->next == guard)//lista pusta
        {
            guard->prev = node;
            guard->next = node;
            node->prev = guard;
            node->next = guard;
        }

        else if (guard->prev->item >= item)  //na poczatku listy
        {
            it.currentNode->prev = node;
            node->prev = guard;
            node->next = it.currentNode;
            guard->prev = node;
        }

        else
        {
            while (it.currentNode->next != guard && it.currentNode->next->item < item) {
                it++;
            }

            if(it.currentNode->next == guard){
                it.currentNode->next = node;
                node->next = guard;
                node->prev = it.currentNode;
                guard->next = node;
                //std::cout << "[end]INSERTING: " << node->item << "; prev = " << node->prev->item << "; next= " << node->next->item << std::endl;
            }
            else{
                node->next = it.currentNode->next;
                node->prev = it.currentNode;
                it.currentNode->next->prev = node;
                it.currentNode->next = node;
                //std::cout << "[mid]INSERTING: " << node->item << "; prev = " << node->prev->item << "; next= " << node->next->item << std::endl;
            }
        }

        length++;

        return it;
    }

    Iterator erase_it(Iterator it){
        Node* node;

        if(it == begin()){
            node = guard->prev;
            guard->prev = node->next;
        }
        else if(it == end().currentNode->next){
            node = guard->next;
            node->prev->next = guard;
            guard->next = node->prev;
        }
        else{
            node = it.currentNode;
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        it++;
        length--;
        delete node;

        return it;
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
    //std::cout << "guard->prev_item=: " << guard->prev->item << std::endl;
    if (guard->prev == guard && guard->next == guard)//lista pusta
    {
        guard->prev = node;
        guard->next = node;
        node->prev = guard;
        node->next = guard;
        //std::cout << "[empty]INSERTING: " << node->item << "; prev = " << node->prev->item << "; next= " << node->next->item << std::endl;
    }

    else if (guard->prev->item >= item)  //na poczatku listy
    {
        it.currentNode->prev = node;
        node->prev = guard;
        node->next = it.currentNode;
        guard->prev = node;
        //std::cout << "[begin]INSERTING: " << node->item << "; prev = " << node->prev->item << "; next= " << node->next->item << std::endl;
    }

    else
    {
        while (it.currentNode->next != guard && it.currentNode->next->item < item) {
            it++;
        }

        if(it.currentNode->next == guard){
            it.currentNode->next = node;
            node->next = guard;
            node->prev = it.currentNode;
            guard->next = node;
            //std::cout << "[end]INSERTING: " << node->item << "; prev = " << node->prev->item << "; next= " << node->next->item << std::endl;
        }
        else{
            node->next = it.currentNode->next;
            node->prev = it.currentNode;
            it.currentNode->next->prev = node;
            it.currentNode->next = node;
            //std::cout << "[mid]INSERTING: " << node->item << "; prev = " << node->prev->item << "; next= " << node->next->item << std::endl;
        }
    }
    length++;
}

template<typename T>
T SortedLinkedList<T>::pop() {
    if(length > 0){
        T value;
        Node *first = guard->prev;
        value = first->item;
        guard->prev = first->next;
        first->prev = nullptr;
        first->next = nullptr;
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
    Node* node;

    if(it == begin()){
        node = guard->prev;
        guard->prev = node->next;
    }
    else if(it == end().currentNode->next){
        node = guard->next;
        node->prev->next = guard;
        guard->next = node->prev;
    }
    else{
        node = it.currentNode;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    length--;
    delete node;

    return -1;
}

template<typename T>
void SortedLinkedList<T>::print() {
    Iterator it = begin();
    while(it != end()){
        std::cout << it.currentNode->item << " ";
        it++;
    }
    std::cout << std::endl;


    /*it=begin();
    it++;
    erase_it(it);
    length--;*/

    /*it=begin();
    it++;
    insert(it, 500);
    length++;

    it = begin();
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
            if(it == guard->prev){
                it++;
                Node *first = guard->prev;
                guard->prev = first->next;
                first->prev = nullptr;
                first->next = nullptr;
                delete first;
                length--;

            }
            else if(it == guard->next){
                it++;
            }
            else{
                Node* node = it.currentNode;
                Node* prev = node->prev;
                Node* next = node->next;

                prev->next = next;
                next->prev = prev;
                length--;
                delete node;
                it = next;
            }
        }
        else{
            it++;
        }
    }
}

template<typename T>
void SortedLinkedList<T>::unique() {
    Iterator it = begin();
    while(it != end().currentNode->next){
        if(it.currentNode->item == it.currentNode->next->item){
            //std::cout << "znaleziono duplikat: " << it.currentNode->item << std::endl;
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
