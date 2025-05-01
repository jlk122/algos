#include <vector>

namespace sorting{

void insertionSort(std::vector<int>& v, bool reverse=false)
{
	for (int i = 1; i < v.size(); i++)
	{
		// Keeps a copy of current key
		auto key{v[i]};

		// set j to former index(if first iter then j is first element in vector)
		auto j = i - 1;
		while (j >= 0 && (reverse ? (v[j] < key) : (v[j] > key))) // if index valid and element bigger than key. i.e searches where to insert
		{
			// Write current element to next one (in first iter position of key is overwritten, therefore copied into key var)
			v[j + 1] = v[j];
			j--;
		}

		// While loop exits with index position one less than where to insert key
		v[j + 1] = key;
	}
}

} // namespace sorting
