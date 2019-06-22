//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_CHECK_SIZE_HPP
#define POKESAVEGAMETOOL_CHECK_SIZE_HPP

#include <type_traits>

#define TO_XSTR(x) TO_STR(x)
#define TO_STR(x) #x

// src: https://stackoverflow.com/questions/19696942/better-message-for-static-assert-on-object-size
// usage: static_assert( validate_size< int, 4 >::value, "Oops" );
template< typename Type, std::size_t ExpectedSize, std::size_t ActualSize = 0 >
struct validate_size : std::true_type
{
    static_assert( ActualSize == ExpectedSize, "actual size does not match expected size" );
};

template< typename Type, std::size_t ExpectedSize >
struct validate_size< Type, ExpectedSize, 0 >
    : validate_size< Type, ExpectedSize, sizeof( Type ) >
{};

template<int size> struct SIZE { enum { value = size }; };

#endif //POKESAVEGAMETOOL_CHECK_SIZE_HPP
