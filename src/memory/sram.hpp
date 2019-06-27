#ifndef SRAM_HPP
#define SRAM_HPP

#include "../traits.h"
#include "sram_bank0.hpp"
#include "sram_bank34.hpp"

struct SRAM_SaveFile{
    // 0x0000: SRAM BANK 0: "Sprite Buffers"
    SRAM_Bank0 bank0;

    // 0x2000: SRAM BANK 1: "Save Data"
    SRAM_Bank1 bank1;

    // 0x4000: SRAM BANK 2: "Saved Boxes 1"
    SRAM_BoxBank bank2;

    // 0x6000: SRAM BANK 3: "Saved Boxes 2"
    SRAM_BoxBank bank3;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(bank0),
               CEREAL_NVP(bank1),
               CEREAL_NVP(bank2),
               CEREAL_NVP(bank3)
             );
    }
};

static_assert( validate_size< SRAM_SaveFile,  0x8000 >::value);  // 32768
static_assert(is_standard_layouted_trivial_aggregate<SRAM_SaveFile>::value);

static_assert(offsetof(SRAM_SaveFile, bank0.spriteBuffer0) == 0x0000);
static_assert(offsetof(SRAM_SaveFile, bank0.spriteBuffer1) == 0x0188);
static_assert(offsetof(SRAM_SaveFile, bank0.spriteBuffer2) == 0x0310);
static_assert(offsetof(SRAM_SaveFile, bank0._0498) == 0x0498);
static_assert(offsetof(SRAM_SaveFile, bank0.hallOfFame) == 0x0598);
static_assert(offsetof(SRAM_SaveFile, bank0._1858) == 0x1858);

static_assert(offsetof(SRAM_SaveFile, bank1._2000) == 0x2000);
static_assert(offsetof(SRAM_SaveFile, bank1.player_name) == 0x2598);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data) == 0x25A3);
static_assert(offsetof(SRAM_SaveFile, bank1.sprite_data) == 0x2D2C);
static_assert(offsetof(SRAM_SaveFile, bank1.pokemon_team) == 0x2F2C);
static_assert(offsetof(SRAM_SaveFile, bank1.box_active) == 0x30C0);
static_assert(offsetof(SRAM_SaveFile, bank1.tileset_type) == 0x3522);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data_checksum) == 0x3523);

static_assert(offsetof(SRAM_SaveFile, bank2.boxses0) == 0x4000);
static_assert(offsetof(SRAM_SaveFile, bank2._5A53) == 0x5A53);

static_assert(offsetof(SRAM_SaveFile, bank3.boxses1) == 0x6000);
static_assert(offsetof(SRAM_SaveFile, bank3._7A53) == 0x7A53);

#endif // SRAM_HPP
