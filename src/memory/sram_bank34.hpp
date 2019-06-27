#ifndef SRAM_BANK34_HPP
#define SRAM_BANK34_HPP

#include "../traits.h"
#include "../constans.hpp"
#include "../types/pokemon.hpp" //FIXME

struct SRAM_BoxBank{
    BoxBank boxses; // 0x4000/0x1A4C(6 * 1122 = 6732)
    uint8_t _unused[0x05AD];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(boxses) );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<SRAM_BoxBank>::value);
static_assert (sizeof (SRAM_BoxBank) == 0x2000);

#endif // SRAM_BANK34_HPP
