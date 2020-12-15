/*
* This example is taken straight from wikipedia.
* https://en.wikipedia.org/wiki/Template_metaprogramming
* This is just being used as a simple example of
* how template metaprogramming works
*/

// RECURSIVE CASE
template <unsigned int n>
struct factorial {
	enum { value = n * factorial<n - 1>::value };
};

// BASE CASE SPECIALIZATION
template <>
struct factorial<0> {
	enum { value = 1 };
};
