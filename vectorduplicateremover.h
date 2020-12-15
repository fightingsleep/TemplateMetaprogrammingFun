#include <type_traits>

// PRIMARY TEMPLATES
template <int...>
struct Vector;

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
