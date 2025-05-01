#include <gtest/gtest.h>

#include "insertion_sort.cc"

#include <vector>

struct InsertionSort : public testing::Test {

	std::vector<int> four_elements{2,4,3,1};
	std::vector<int> four_elements_result {std::vector<int>{1,2,3,4}};
	std::vector<int> four_elements_result_reverse {std::vector<int>{4,3,2,1}};

	std::vector<int> duplicates{2,4,1,3,1};
	std::vector<int> duplicates_result {std::vector<int>{1,1,2,3,4}};

	std::vector<int> empty{};
	std::vector<int> empty_result{};
};


TEST_F(InsertionSort, RunOnFourElements)
{
	sorting::insertionSort(four_elements);
	EXPECT_EQ(four_elements, four_elements_result);
}

TEST_F(InsertionSort, RunOnFourElementsReverse)
{
	sorting::insertionSort(four_elements, true);
	EXPECT_EQ(four_elements, four_elements_result_reverse);
}

TEST_F(InsertionSort, RunOnEmpty)
{
	sorting::insertionSort(empty);
	EXPECT_EQ(empty, empty_result);
}

TEST_F(InsertionSort, CompareEmptyWithSorted)
{
	sorting::insertionSort(four_elements);
	EXPECT_NE(four_elements, empty);
}

TEST_F(InsertionSort, RunOnDuplicateData)
{
	sorting::insertionSort(duplicates);
	EXPECT_EQ(duplicates, duplicates_result);
}
