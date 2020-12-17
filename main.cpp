#include "factorial.hpp"
#include "vectorduplicateremover.hpp"
#include <iostream>

int main()
{
	static_assert(std::is_same<VectorDuplicateRemover<Vector<1, 2, 2, 2, 3, 4, 4>>::type, Vector<1, 2, 3, 4>>::value);
	static_assert(std::is_same<VectorDuplicateRemover<Vector<1, 2, 2, 2, 3, 4, 4, 1, 5>>::type, Vector<1, 2, 3, 4, 1, 5>>::value);

	static_assert(factorial<10>::value == 3628800);
	static_assert(factorial<9>::value == 362880);
	static_assert(factorial<8>::value == 40320);
	static_assert(factorial<7>::value == 5040);
	static_assert(factorial<6>::value == 720);
	static_assert(factorial<5>::value == 120);
	static_assert(factorial<4>::value == 24);
	static_assert(factorial<3>::value == 6);
	static_assert(factorial<2>::value == 2);
	static_assert(factorial<1>::value == 1);
	static_assert(factorial<0>::value == 1);

	std::cout << factorial<10>::value << std::endl;
	VectorDuplicateRemover<Vector<1, 2, 2, 2, 3, 4, 4, 1, 5>>::type vec;

	for (auto const &el : vec.GetDeduplicatedVector())
	{
		std::cout << el << std::endl;
	}
}