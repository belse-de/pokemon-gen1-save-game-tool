//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_MEM_MANIPULATION_HPP
#define POKESAVEGAMETOOL_MEM_MANIPULATION_HPP


#include <cstdint>

//Bit = ( Data[ RoundDown(PokeNum / 8) ] / 2 ^ (PokeNum Mod 8) ) AND 1
constexpr bool pokedex_isSet(uint8_t const * const data, uint8_t poke_num){
    uint8_t byte_idx = poke_num >> 3;
    uint8_t bit_idx = (poke_num & 0b0111);
    uint8_t bit = 1 << bit_idx;
    return data[byte_idx] & bit == bit;
}

constexpr void pokedex_set(uint8_t * const data, uint8_t poke_num){
    uint8_t byte_idx = poke_num >> 3;
    uint8_t bit_idx = (poke_num & 0b0111);
    uint8_t bit = 1 << bit_idx;
    data[byte_idx] |= bit;
}

constexpr void pokedex_reset(uint8_t * const data, uint8_t poke_num){
    uint8_t byte_idx = poke_num >> 3;
    uint8_t bit_idx = (poke_num & 0b0111);
    uint8_t bit = 1 << bit_idx;
    data[byte_idx] &= ~bit;
}

constexpr uint8_t calc_checksum(uint8_t const * const begin, uint8_t const * const end){
    uint8_t sum = 0;
    for(uint8_t const * iter = begin; iter != end; ++iter){
        sum += *iter;
        // TODO: std algorithm
    }
    return ~sum;
}

#endif //POKESAVEGAMETOOL_MEM_MANIPULATION_HPP
