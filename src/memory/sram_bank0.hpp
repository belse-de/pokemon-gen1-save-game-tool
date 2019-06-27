#ifndef SRAM_BANK0_HPP
#define SRAM_BANK0_HPP

#include <cereal/cereal.hpp>

#include "../traits.hpp"
#include "../constans.hpp"
#include "../types/hall_of_fame.hpp"

struct SRAM_Bank0{
    uint8_t spriteBuffer0[SPRITE_BUFFER_SIZE]; // 0x0000
    uint8_t spriteBuffer1[SPRITE_BUFFER_SIZE]; // 0x0188
    uint8_t spriteBuffer2[SPRITE_BUFFER_SIZE]; // 0x0310
    uint8_t _0498[0x100];
    HallOfFame hallOfFame; // 0x0598/0x12C0
    uint8_t _1858[0x07A8];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( //CEREAL_NVP(spriteBuffer0), // 0x0000
               //CEREAL_NVP(spriteBuffer1), // 0x0188
               //CEREAL_NVP(spriteBuffer2), // 0x0310
               //CEREAL_NVP(_0498),
               //CEREAL_NVP(hallOfFame), // 0x0598/0x12C0
               //CEREAL_NVP(_1858), //FIXME
              );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<SRAM_Bank0>::value);
static_assert (sizeof (SRAM_Bank0) == 0x2000);

#endif // SRAM_BANK0_HPP
