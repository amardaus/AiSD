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

    Iterator begin(){
        return Iterator(guard->prev);
    }
    Iterator end(){
        return Iterator(guard);
    }

    Iterator insert(Iterator it, const T& item){
        Node* node = new Node();
        node->item = item;

        it.currentNode->prev->next = node;
        it.currentNode->prev = node;
        node->prev = it.currentNode->prev;
        node->next = it.currentNode;

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

private:
    Node* guard;
    int length;

public:
    SortedLinkedList(){
        guard = new Node;
        guard->next = guard;
        guard->prev = guard;
        length = 0;
    }

    void push(T item);
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
    /*static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);*/
    void unique();
    void print();
};



template<typename T>
void SortedLinkedList<T>::push(T item) {
    Node *node = new Node();
    node->item = item;

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
            if(it == guard->prev){
                it++;
                Node *first = guard->prev;
                guard->prev = first->next;
                first->prev = nullptr;
                first->next = nullptr;
                delete first;
                length--;

                std::cout << "poczatek!";
            }
            else if(it == guard->next){
                std::cout << "koniec!";
                it++;
            }
            else{
                //std::cout << "srodek" << std::endl;
                Node* node = it.currentNode;
                //it++;
                Node* prev = node->prev;
                Node* next = node->next;
                //std::cout << "prev: "  << prev->item << std::endl;
                //std::cout << "node: " << node->item << std::endl;
                //std::cout << "next" << next->item << std::endl;

                prev->next = next;
                next->prev = prev;
                //node->prev->next = it.currentNode;
                //it.currentNode->prev = node->prev;
                //node->prev = nullptr;
                //node->next = nullptr;
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

#endif //ALGORYTMYISTRUKTURYDANYCH_SortedLinkedList_H
