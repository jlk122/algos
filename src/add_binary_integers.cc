#include <cassert>
#include <ranges>
#include <vector>

namespace binary {

std::vector<int> addBinaryIntegers(const std::vector<int>& A, const std::vector<int>& B)
{
	assert (A.size() == B.size());
	if (A.empty())
	{
		return {};
	}
	std::size_t n{A.size()}; // Size of input vector

	std::vector<int> C(n + 1);

	int overflow{};
	for (std::size_t i : std::views::iota(std::size_t{0}, n) | std::views::reverse) // i belongs to [0, n]
	{
		assert(A.size() > i);
		int a{A.at(i) > 0 ? 1 : 0};
		int b{B.at(i) > 0 ? 1 : 0};

		overflow = overflow + a + b;
		switch (overflow) {
			case 0:
				C.at(i + 1) = 0;
				break;
			case 1:
				C.at(i + 1) = 1;
				overflow = 0;
				break;
			case 2:
				C.at(i + 1) = 0;
				overflow = 1;
				break;
			case 3:
				C.at(i + 1) = 1;
				overflow = 1;
				break;
			default:
				// error
				break;
		}
	}

	C[0] = overflow;

	return C;
}

} // namespace binary
