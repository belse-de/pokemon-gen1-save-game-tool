#ifndef TRAITS_H
#define TRAITS_H

#include <type_traits>

template <typename T>
struct is_standard_layouted_trivial {
    static constexpr bool value =
            std::is_standard_layout<T>::value
            and std::is_trivial<T>::value;
};

template <typename T>
struct is_standard_layouted_trivial_aggregate {
    static constexpr bool value =
            std::is_standard_layout<T>::value
            and std::is_trivial<T>::value
            and std::is_aggregate<T>::value;
};

#endif // TRAITS_H
