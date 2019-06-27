#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include <cereal/cereal.hpp>

#include "bitarray.hpp"

struct PlayerPokeDex{
    BitArray<151> owned;
    BitArray<151> seen;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(owned), CEREAL_NVP(seen) );
    }
};
static_assert( sizeof(PlayerPokeDex) == 2 * 19 );
static_assert(is_standard_layouted_trivial_aggregate<PlayerPokeDex>::value);

#endif // POKEDEX_HPP
