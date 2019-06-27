//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_MEM_MANIPULATION_HPP
#define POKESAVEGAMETOOL_MEM_MANIPULATION_HPP


#include <cstdint>

//Bit = ( Data[ RoundDown(PokeNum / 8) ] / 2 ^ (PokeNum Mod 8) ) AND 1
constexpr bool pokedex_isSet(std::uint8_t const * const data, std::uint8_t poke_num){
    std::uint8_t byte_idx = poke_num >> 3;
    std::uint8_t bit_idx = (poke_num & 0b0111);
    std::uint8_t bit = 1u << bit_idx;
    return (data[byte_idx] & bit) == bit;
}

constexpr void pokedex_set(std::uint8_t * const data, std::uint8_t poke_num){
    std::uint8_t byte_idx = poke_num >> 3;
    std::uint8_t bit_idx = (poke_num & 0b0111);
    std::uint8_t bit = 1u << bit_idx;
    data[byte_idx] |= bit;
}

constexpr void pokedex_reset(std::uint8_t * const data, std::uint8_t poke_num){
    std::uint8_t byte_idx = poke_num >> 3;
    std::uint8_t bit_idx = (poke_num & 0b0111);
    std::uint8_t bit = 1u << bit_idx;
    data[byte_idx] &= ~bit;
}

constexpr std::uint8_t calc_checksum(std::uint8_t const * const begin, std::uint8_t const * const end){
    std::uint8_t sum = 0;
    for(std::uint8_t const * iter = begin; iter != end; ++iter){
        sum += *iter;
        // TODO: std algorithm
    }
    return ~sum;
}

#endif //POKESAVEGAMETOOL_MEM_MANIPULATION_HPP
