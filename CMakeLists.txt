cmake_minimum_required(VERSION 3.3)
project(DPAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    CoinChangeProblem.cpp
    CoinChangeProblem.h
    LongestIncreasingSubsequence.cpp
    LongestIncreasingSubsequence.h
    LongestNonDecreasingSubsequence.cpp
    LongestNonDecreasingSubsequence.h
    main.cpp CuttingRodProblem.cpp CuttingRodProblem.h PickEitherSIdeforMaxValue.cpp PickEitherSIdeforMaxValue.h UnionFind.cpp UnionFind.h SegmentTree.cpp SegmentTree.h FenwickTree.cpp FenwickTree.h)

include_directories(.)

add_executable(DPAlgorithms ${SOURCE_FILES})