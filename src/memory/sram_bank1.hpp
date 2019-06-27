#ifndef SRAM_BANK1_HPP
#define SRAM_BANK1_HPP

#include <cereal/cereal.hpp>

#include "../traits.hpp"
#include "../constans.hpp"
#include "../types/name.hpp"
#include "../types/pokemon.hpp" //FIXME
#include "sram_bank1_main_data.hpp"

struct SRAM_Bank1{
    uint8_t _2000[0x0598];
    Name           player_name;
    MainData  main_data; // 0x2598/0x06D2(1746)

    uint8_t        sprite_data[0x200];
    PokeList_Bag pokemon_team;
    PokeList_Box   box_active;
    uint8_t        tileset_type;
    uint8_t        main_data_checksum;
    uint8_t _3524[0x0ADC];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(player_name),
               CEREAL_NVP(main_data),
               //CEREAL_NVP(sprite_data),
               CEREAL_NVP(pokemon_team),
               CEREAL_NVP(box_active)//,
               //CEREAL_NVP(tileset_type),
               //CEREAL_NVP(main_data_checksum)
               );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<SRAM_Bank1>::value);
static_assert (sizeof (SRAM_Bank1) == 0x2000);

#endif // SRAM_BANK1_HPP
