#include <cassert>
#include <cstddef>
#include <utility>
#include <vector>

namespace sorting {

void selectionSort(std::vector<int>& A, bool reverse=false)
{
	if (A.size() < 2)
	{
		return;
	}
	for (std::size_t i = 0; i < (A.size() - 1); i++)
	{
		assert(i < A.size());
		size_t min_i{i};
		for (std::size_t j = i; j < A.size(); j++)
		{
			if (A.at(j) < A.at(min_i))
			{
				min_i = j;
			}
		}
		std::swap(A.at(i), A.at(min_i));
	}
}
} // namespace sorting
