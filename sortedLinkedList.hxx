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
        //return Iterator(guard->next);
        return Iterator(guard);
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
    /*static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);
    void unique();*/
    void print();
};



template<typename T>
void SortedLinkedList<T>::push(T item) {
    Node *node = new Node;
    node->item = item;

    Iterator it = begin();
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
            node->prev = it.currentNode->next;
            guard->next = node;
        }
        else{
            node->next = it.currentNode->next;
            node->prev = it.currentNode->prev;
            it.currentNode->next->prev = node;
            it.currentNode->next = node;
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
    /*it = begin();
    while(it){
        if(it.currentNode == index){
            std::cout << "znaleziono!";
        }
        it++;
        if(it == end()){
            break;
        }
        it = begin();
    }*/

    return -1;
}

template<typename T>
void SortedLinkedList<T>::print() {
    Iterator it = begin();
    while(it != end()){
        std::cout << it.currentNode->item << std::endl;
        it++;
    }
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
                std::cout << "srodek";
                it++;

                    Node *first = guard->prev;
                guard->prev = first->next;
                first->prev = nullptr;
                first->next = nullptr;
                delete first;
                length--;
            }
        }
        else{
            it++;
        }
    }

}

#endif //ALGORYTMYISTRUKTURYDANYCH_SortedLinkedList_H
