#ifndef TRAITS_H
#define TRAITS_H

#include <type_traits>

template <typename T>
struct is_standard_layouted_trivial_aggregate {
    static constexpr bool value =
            std::is_standard_layout<T>::value
            and std::is_trivial<T>::value
            and std::is_aggregate<T>::value;
};


#include <cstdint>

union bits_uint8_t {
    std::uint8_t ui;
    struct bit8{
        unsigned b0:1;
        unsigned b1:1;
        unsigned b2:1;
        unsigned b3:1;
        unsigned b4:1;
        unsigned b5:1;
        unsigned b6:1;
        unsigned b7:1;
    } b;
};

static_assert (is_standard_layouted_trivial_aggregate<bits_uint8_t>::value);


#endif // TRAITS_H
