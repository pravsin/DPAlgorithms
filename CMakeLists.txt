cmake_minimum_required(VERSION 3.3)
project(DPAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LongestIncreasingSubsequence.cpp LongestIncreasingSubsequence.h LongestNonDecreasingSubsequence.cpp LongestNonDecreasingSubsequence.h CoinChageProblem.cpp CoinChageProblem.h)
add_executable(DPAlgorithms ${SOURCE_FILES})