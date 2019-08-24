cmake_minimum_required(VERSION 3.14)
project(cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp basic/creditcard.cpp basic/ngram.cpp main.cpp main.h)