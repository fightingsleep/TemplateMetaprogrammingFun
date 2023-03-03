#ifndef VECTOR_DUPLICATE_REMOVER_HPP
#define VECTOR_DUPLICATE_REMOVER_HPP

#include <vector>

// PRIMARY TEMPLATES
template <int... I>
class Vector
{
public:
    std::vector<int> GetDeduplicatedVector();
};

template<typename>
struct VectorDuplicateRemover;

template<int, typename>
struct VectorBuilder;

// RECURSIVE TEMPLATE SPECIALIZATIONS
template<int el, int... rest>
struct VectorDuplicateRemover<Vector<el, el, rest...>>
{
    // Remove the duplicate
    using type = typename VectorDuplicateRemover<Vector<el, rest...>>::type; // Typedef
};

template<int el, int... rest>
struct VectorDuplicateRemover<Vector<el, rest...>>
{
    using type = typename VectorBuilder<el, typename VectorDuplicateRemover<Vector<rest...>>::type>::type; // Typedef
};

// BASE TEMPLATE SPECIALIZATION
template<int... I>
struct VectorDuplicateRemover<Vector<I...>>
{
    using type = Vector<I...>; // Typedef
};

// UTILITIES
template<int el, int... rest>
struct VectorBuilder<el, Vector<rest...>>
{
    using type = Vector<el, rest...>; // Typedef
};

// This function definition must be included in the header file
// because of the way that templates work.
template <int... I>
std::vector<int> Vector<I...>::GetDeduplicatedVector()
{
    return std::vector<int>{I...};
}

#endif // !VECTOR_DUPLICATE_REMOVER_HPP
