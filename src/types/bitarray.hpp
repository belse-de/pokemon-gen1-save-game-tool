#ifndef BITARRAY_HPP
#define BITARRAY_HPP

#include <iostream>

#include <cstddef>
#include <cstdlib>
#include <array>
#include "../traits.h"


struct BitArrayPos
{
    std::size_t byte = 0;
    std::size_t bit  = 0;
};

constexpr std::size_t calc_byte_pos(std::size_t pos) {
    return pos >> 3;
}
constexpr std::size_t calc_bit_pos(std::size_t pos) {
    return pos & 0b0111;
}
constexpr BitArrayPos calc_pos(std::size_t pos){
    return {.byte = calc_byte_pos(pos), .bit = calc_bit_pos(pos)};
}


template <std::size_t BITS>
struct BitArray
{
    static constexpr std::size_t bits = BITS;
    static constexpr std::size_t bytes = BITS / 8u + ((BITS % 8u) ? 1u : 0u);

    std::array<uint8_t, bytes> data;

    std::string to_string() const{
        std::string str(bits, '0');
        for(size_t i=0; i<bits; ++i){
            str.at(i) = get(i) ? '1' : '0';
        }
        return str;
    }

    BitArray& from_string(std::string const& str){
        for(size_t i=0; i<bits and i < str.size(); ++i){
            set(i, str.at(i) == '1' ? true : false);
        }
        return *this;
    }

    bool get(std::size_t pos) const{
        auto [byte, bit] = calc_pos(pos);
        return (data.at(byte) >> bit) & 0x01 ? true : false;
    }

    BitArray& set(std::size_t pos){
        auto [byte, bit] = calc_pos(pos);
        data.at(byte) |= 1u << bit;
        return *this;
    }

    BitArray& clear(std::size_t pos){
        auto [byte, bit] = calc_pos(pos);
        data.at(byte) &= ~(1u << bit);
        return *this;
    }

    BitArray& toggle(std::size_t pos){
        auto [byte, bit] = calc_pos(pos);
        data.at(byte) ^= 1u << bit;
        return *this;
    }


    BitArray& set(std::size_t pos, bool val){
        auto [byte, bit] = calc_pos(pos);
        data.at(byte) ^= ((val ? ~0u : 0u) ^ data.at(byte))& (1u << bit);
        return *this;
    }

    bool operator[](std::size_t pos) const{
        return get(pos);
    }

    template<class Archive>
    std::string save_minimal(Archive const&) const
    {
        return to_string();
    }

    template<class Archive>
    void load_minimal(Archive const&, std::string const& val)
    {
        from_string(val);
    }
};
static_assert(sizeof(BitArray<151>) == 19 );
static_assert (is_standard_layouted_trivial_aggregate<BitArray<151>>::value);

#endif // BITARRAY_HPP
