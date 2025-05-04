#include <gtest/gtest.h>

#include "insertion_sort.cc"
#include "selection_sort.cc"

#include <vector>

struct Sorting : public testing::Test {

	std::vector<int> four_elements{2,4,3,1};
	std::vector<int> four_elements_result {std::vector<int>{1,2,3,4}};
	std::vector<int> four_elements_result_reverse {std::vector<int>{4,3,2,1}};

	std::vector<int> duplicates{2,4,1,3,1};
	std::vector<int> duplicates_result {std::vector<int>{1,1,2,3,4}};

	std::vector<int> empty{};
	std::vector<int> empty_result{};
};

// INSERTION
TEST_F(Sorting, InsertionRunOnFourElements)
{
	sorting::insertionSort(four_elements);
	EXPECT_EQ(four_elements, four_elements_result);
}

TEST_F(Sorting, InsertionRunOnFourElementsReverse)
{
	sorting::insertionSort(four_elements, true);
	EXPECT_EQ(four_elements, four_elements_result_reverse);
}

TEST_F(Sorting, InsertionRunOnEmpty)
{
	sorting::insertionSort(empty);
	EXPECT_EQ(empty, empty_result);
}

TEST_F(Sorting, InsertionCompareEmptyWithSorted)
{
	sorting::insertionSort(four_elements);
	EXPECT_NE(four_elements, empty);
}

TEST_F(Sorting, InsertionRunOnDuplicateData)
{
	sorting::insertionSort(duplicates);
	EXPECT_EQ(duplicates, duplicates_result);
}


// SELECTION
TEST_F(Sorting, SelectionRunOnFourElements)
{
	sorting::selectionSort(four_elements);
	EXPECT_EQ(four_elements, four_elements_result);
}

TEST_F(Sorting, SelectionRunOnFourElementsReverse)
{
	sorting::selectionSort(four_elements, true);
	EXPECT_EQ(four_elements, four_elements_result_reverse);
}

TEST_F(Sorting, SelectionRunOnEmpty)
{
	sorting::selectionSort(empty);
	EXPECT_EQ(empty, empty_result);
}

TEST_F(Sorting, SelectionCompareEmptyWithSorted)
{
	sorting::selectionSort(four_elements);
	EXPECT_NE(four_elements, empty);
}

TEST_F(Sorting, SelectionRunOnDuplicateData)
{
	sorting::selectionSort(duplicates);
	EXPECT_EQ(duplicates, duplicates_result);
}
