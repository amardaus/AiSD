cmake_minimum_required(VERSION 3.15)
project(AlgorytmyiStrukturyDanych)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgorytmyiStrukturyDanych main.cpp sortedArrayList.hxx sortedLinkedList.hxx merging.cxx sortAddRemove.cxx generateInput.cxx)
add_executable(generateInput generateInput.cxx)
add_executable(main main.cpp)
add_executable(sortAddRemove sortAddRemove.cxx)
add_executable(merging merging.cxx)