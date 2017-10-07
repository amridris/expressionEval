cmake_minimum_required(VERSION 3.8)
project(Stacks_Queue_Lab5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp node.cpp node.h queue.cpp queue.h stack.cpp stack.h expression.cpp expression.h)
add_executable(Stacks_Queue_Lab5 ${SOURCE_FILES} node.cpp node.h)