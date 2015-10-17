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
    main.cpp CuttingRodProblem.cpp CuttingRodProblem.h PickEitherSIdeforMaxValue.cpp PickEitherSIdeforMaxValue.h UnionFind.cpp UnionFind.h SegmentTree.cpp SegmentTree.h FenwickTree.cpp FenwickTree.h HistogramArea.cpp HistogramArea.h LongestPalindromeSubsequence.cpp LongestPalindromeSubsequence.h Kanpsack01.cpp Kanpsack01.h FFTMultiplication.cpp FFTMultiplication.h kadane.cpp kadane.h LongestCommonIncreasingSubsequence.cpp LongestCommonIncreasingSubsequence.h KMP.cpp KMP.h LongestCommonSubsequenceLCS.cpp LongestCommonSubsequenceLCS.h BitsMagic.cpp BitsMagic.h FloydWarshallAPSP.cpp FloydWarshallAPSP.h LongestCommonSubstring.cpp LongestCommonSubstring.h LongestBitonicSubsequence.cpp LongestBitonicSubsequence.h Zalgorithm.cpp Zalgorithm.h MatrixRotation.cpp MatrixRotation.h)

include_directories(.)

add_executable(DPAlgorithms ${SOURCE_FILES})