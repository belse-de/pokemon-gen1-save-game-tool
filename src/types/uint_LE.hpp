//
// Created by belse on 12.06.18.
//

#ifndef POKESAVEGAMETOOL_UINT_LE_HPP
#define POKESAVEGAMETOOL_UINT_LE_HPP

#include <cstddef> // offsetof, std::size_t
#include <cstdint>

#include <type_traits>

template <typename T>
struct le_uint{
    std::uint8_t raw[sizeof(T)];

    le_uint& set(T val){
        for(std::size_t i=0; i < sizeof(T); ++i){
            raw[i] = val & (0xFFu << ((sizeof(T) - 1 - i) * 8u));
        }
        return *this;
    }

    //TODO: check trait unsigned; operator<< is not well defined for signed
    //TODO: replace 8u with char/byte width


    operator T() const{
        T res = 0;
        for(std::size_t i=0; i < sizeof(T); ++i){
            res += raw[i] << ((sizeof(T) - 1 - i) * 8u);
        }
        return res;
    }
};


using le_uint8_t  = le_uint<std::uint8_t>;
using le_uint16_t = le_uint<std::uint16_t>;
using le_uint32_t = le_uint<std::uint32_t>;
using le_uint64_t = le_uint<std::uint64_t>;

static_assert(std::is_standard_layout<le_uint8_t>::value);
static_assert(std::is_aggregate<le_uint8_t>::value);
static_assert(std::is_trivial<le_uint8_t>::value);

static_assert(std::is_standard_layout<le_uint16_t>::value);
static_assert(std::is_aggregate<le_uint16_t>::value);
static_assert(std::is_trivial<le_uint16_t>::value);

static_assert(std::is_standard_layout<le_uint32_t>::value);
static_assert(std::is_aggregate<le_uint32_t>::value);
static_assert(std::is_trivial<le_uint32_t>::value);

static_assert(std::is_standard_layout<le_uint64_t>::value);
static_assert(std::is_aggregate<le_uint64_t>::value);
static_assert(std::is_trivial<le_uint64_t>::value);

static_assert(sizeof(le_uint8_t) == 1);
static_assert(sizeof(le_uint16_t) == 2);
static_assert(sizeof(le_uint32_t) == 4);
static_assert(sizeof(le_uint64_t) == 8);

#endif //POKESAVEGAMETOOL_UINT_LE_HPP
