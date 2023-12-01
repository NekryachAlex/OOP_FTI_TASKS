#include "gtest/gtest.h"
#include "../ParallelQuickSort/QuickSort.h"
#include "../ParallelQuickSort/Policies.h"
#include <array>

TEST(oneElemInt, Vectors) {
    std::vector<int>  testVector = { 1 };
    SuitablePolicy policy;
    EXPECT_NO_THROW(sortFunction::quickSort(testVector.begin(), testVector.end()));

}

TEST(noElemInt, Vectors) {
    std::vector<int>  testVector;
    EXPECT_NO_THROW(sortFunction::quickSort(testVector.begin(), testVector.end()));

}

TEST(someElemInt, Vectors) {
    std::vector<int>  testVector = { 3,2,1 };
    std::vector<int>  sortedVector = { 1,2,3 };
    const SuitablePolicy policy;
    sortFunction::quickSort(testVector.begin(), testVector.end());
    EXPECT_EQ(testVector, sortedVector);
}

TEST(manyElemInt, Vectors) {
    std::vector<int> testVector(10000);
    for (auto& iterVector : testVector) {
        iterVector = rand();
    }
    std::vector<int>  sortedVector(testVector);
    std::sort(sortedVector.begin(), sortedVector.end());
    sortFunction::sort(testVector.begin(), testVector.end());
    EXPECT_EQ(testVector, sortedVector);
}



TEST(manyElemDouble, Vectors) {
    std::vector<double> testVector(1000);
    for (auto& iterVector : testVector) {
        iterVector = rand();
    }
    std::vector<double>  sortedVector(testVector);
    std::sort(sortedVector.begin(), sortedVector.end());
    sortFunction::quickSort(testVector.begin(), testVector.end());
    EXPECT_EQ(testVector, sortedVector);
}

TEST(oneElemDouble, Vectors) {
    std::vector<double>  testVector = { 1.2 };
    EXPECT_NO_THROW(sortFunction::quickSort(testVector.begin(), testVector.end()));
}

TEST(manyElemInt, Arrays) {
    std::array<int, 1000> testArray;
    for (int i = 0; i < 1000; i++) {
        testArray.at(i) = rand();
    }
    std::array<int, 1000>  sortedArray(testArray);
    std::sort(sortedArray.begin(), sortedArray.end());
    sortFunction::quickSort(testArray.begin(), testArray.end());
    EXPECT_EQ(testArray, sortedArray);
}

TEST(someElemInt, Arrays) {
    std::array<int, 1>  testArray1 = { 1 };
    std::array<int, 1>  testArray2 = { 1 };
    sortFunction::quickSort(testArray1.begin(), testArray1.end());
    EXPECT_EQ(testArray1, testArray2);
}

TEST(manyElemDouble, Arrays) {
    std::array<double, 10000> testArray;
    for (int i = 0; i < 1000; i++) {
        testArray.at(i) = rand();
    }
    std::array<double, 10000>  sortedArray(testArray);
    std::sort(sortedArray.begin(), sortedArray.end());
    sortFunction::quickSort(testArray.begin(), testArray.end());
    EXPECT_EQ(testArray, sortedArray);
}

TEST(someElemDouble, Arrays) {
    std::array<double, 1>  testArray1 = { 1.2 };
    std::array<double, 1>  testArray2 = { 1.2 };
    sortFunction::quickSort(testArray1.begin(), testArray1.end());
    EXPECT_EQ(testArray1, testArray2);
}