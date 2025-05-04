
#include <gtest/gtest.h>

#include "add_binary_integers.cc"

#include <vector>

struct AddBinaryNumbers : public testing::Test {

	std::vector<int> seven{0,1,1,1};
	std::vector<int> five {0,1,0,1};
	std::vector<int> twelve {0,1,1,0,0};

	std::vector<int> empty{};
};

TEST_F(AddBinaryNumbers, EmptyInput)
{
	auto C{binary::addBinaryIntegers(empty, empty)};
	ASSERT_EQ(C, empty);
}

TEST_F(AddBinaryNumbers, ValidInput)
{
	std::vector<int> C{binary::addBinaryIntegers(seven, five)};
	ASSERT_EQ(C, twelve);
}

TEST_F(AddBinaryNumbers, DiffSizeInput)
{
	std::vector<int> C{binary::addBinaryIntegers(seven, empty)};
	ASSERT_EQ(C, seven);
}

