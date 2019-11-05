#include <iostream>
#include "sortedArrayList.hxx"
#include "sortedLinkedList.hxx"

int main() {
    SortedArrayList<int>* sortedArrayList = new SortedArrayList<int>();
    SortedArrayList<int>* sortedArrayList2 = new SortedArrayList<int>();
    sortedArrayList->push(222);
    sortedArrayList->push(111);
    sortedArrayList->push(333);
    for(const auto& a : *sortedArrayList){
        std::cout << "item:" << a << std::endl;
    }



    //sortedArrayList->unique();
    sortedArrayList->print();

    /*SortedArrayList<int> mergedArray = SortedArrayList<int>::merge(*sortedArrayList, *sortedArrayList2);
    mergedArray.print();
    delete sortedArrayList;
    delete sortedArrayList2;*/



    SortedLinkedList<int>* sortedLinkedList = new SortedLinkedList<int>();
    SortedLinkedList<int>* sortedLinkedList2 = new SortedLinkedList<int>();
    SortedLinkedList<int>* mergedList = new SortedLinkedList<int>();
    sortedLinkedList->push(300);
    sortedLinkedList->push(200);
    sortedLinkedList->push(100);
    sortedLinkedList2->push(400);
    sortedLinkedList2->push(200);
    sortedLinkedList2->push(500);
    sortedLinkedList->print();
    sortedLinkedList2->print();

    mergedList = mergedList->merge(*sortedLinkedList, *sortedLinkedList2);
    mergedList->print();

    for(const auto& a : *mergedList)
        std::cout << "item:" << a << std::endl;

    //std::cout << "found: " << sortedLinkedList->find(500).currentNode->item << std::endl;
    //sortedLinkedList->erase(sortedLinkedList->find(300));*/

    return 0;
}