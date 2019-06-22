
#ifndef POKE_TYPES_HPP
#define POKE_TYPES_HPP

#include <cstdint>
#include <bitset>

#include "check_size.hpp"
#include "constans.hpp"
#include "traits.h"
#include "types/item.hpp"
#include "types/pokemon.hpp"
#include "types/name.hpp"
#include "types/hall_of_fame.hpp"
#include "types/bitarray.hpp"



// TODO: make template
struct PlayerPokeDex{
    BitArray<151> owned;
    BitArray<151> seen;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(owned), CEREAL_NVP(seen) );
    }
};

// offset in safe 0x2598
struct Player {
    Name           player_name;
    PlayerPokeDex  pokedex;
    ItemList_Bag   bag;
    uint8_t        money[3];
    Name           rival;
    uint8_t        options;
    uint8_t        badges;
    uint8_t        _2603;
    uint8_t        letter_delay;
    be_uint16_t    trainerID;
    uint8_t        music_ID;
    uint8_t        music_bank;
    uint8_t        contrast_ID;
    uint8_t        current_map_ID;
    be_uint16_t    current_map_ptr;
    uint8_t        pos_y;
    uint8_t        pos_x;
    uint8_t        block_pos_y;
    uint8_t        block_pos_x;
    uint8_t        last_map_ID;
    uint8_t        _2612;
    uint8_t        current_tileset_ID;
    uint8_t        current_map_block_height;
    uint8_t        current_map_block_width;
    be_uint16_t    current_map_data_ptr;
    be_uint16_t    current_map_text_ptr;
    be_uint16_t    current_map_script_ptr;
    uint8_t        current_map_connections;
    uint8_t        current_map_connections_north[0x0B];
    uint8_t        current_map_connections_south[0x0B];
    uint8_t        current_map_connections_west[0x0B];
    uint8_t        current_map_connections_east[0x0B];

    uint8_t        pikachu_friendship;
    uint8_t        _271D[201];
    ItemList_PC    player_pc;
    uint8_t        pc_box_active_idx;
    uint8_t        _284D[3];
    uint8_t        casino_coins[2];
    uint8_t        _2852[1180];
    uint8_t        time_played[4];
    uint8_t        _2CF2[570-512];


    uint8_t        sprite_data[512];
    PokeList_Bag pokemon_team;
    PokeList_Box   box_active;
    uint8_t        tilesetType;
    uint8_t        checksum;


    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(player_name),
               CEREAL_NVP(pokedex),
               CEREAL_NVP(bag),
               CEREAL_NVP(money),
               CEREAL_NVP(rival),
               CEREAL_NVP(options),
               CEREAL_NVP(badges),
               //CEREAL_NVP(_2603),
               CEREAL_NVP(trainerID),
               //CEREAL_NVP(_2607),
               CEREAL_NVP(pikachu_friendship),
               //CEREAL_NVP(_271D),
               CEREAL_NVP(player_pc),
               CEREAL_NVP(pc_box_active_idx),
               //CEREAL_NVP(_284D),
               CEREAL_NVP(casino_coins),
               //CEREAL_NVP(_2852),
               CEREAL_NVP(time_played),
               //CEREAL_NVP(_2CF2),
               CEREAL_NVP(sprite_data),
               CEREAL_NVP(pokemon_team),
               CEREAL_NVP(box_active),
               CEREAL_NVP(tilesetType),
               CEREAL_NVP(checksum)
              );
    }
};

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

struct SRAM_Bank1{
    uint8_t _2000[0x0598];
    Player  player; // 0x2598/0x06D2(1746)
    uint8_t _3524[0x0ADC];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( //CEREAL_NVP(_2000),
               CEREAL_NVP(player)//, // 0x2598/0x06D2(1746)
               //CEREAL_NVP(_3524),
               );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<SRAM_Bank1>::value);
static_assert (sizeof (SRAM_Bank1) == 0x2000);

struct SRAM_Bank2{
    BoxBank boxses0; // 0x4000/0x1A4C(6 * 1122 = 6732)
    uint8_t _5A53[0x05AD];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( //CEREAL_NVP(boxses0), // 0x4000/0x1A4C(6 * 1122 = 6732)
               //CEREAL_NVP(_5A53),
             );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<SRAM_Bank2>::value);
static_assert (sizeof (SRAM_Bank2) == 0x2000);

struct SRAM_Bank3{
    BoxBank boxses1; // 0x6000/0x1A4C(6 * 1122 = 6732)
    uint8_t _7A53[0x05AD];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( //CEREAL_NVP(boxses1)//, // 0x6000/0x1A4C(6 * 1122 = 6732)
               //CEREAL_NVP(_7A53)
             );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<SRAM_Bank3>::value);
static_assert (sizeof (SRAM_Bank3) == 0x2000);

struct SRAM_SaveFile{
    // 0x0000: SRAM BANK 0: "Sprite Buffers"
    SRAM_Bank0 bank0;

    // 0x2000: SRAM BANK 1: "Save Data"
    SRAM_Bank1 bank1;

    // 0x4000: SRAM BANK 2: "Saved Boxes 1"
    SRAM_Bank2 bank2;

    // 0x6000: SRAM BANK 3: "Saved Boxes 2"
    SRAM_Bank3 bank3;

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

static_assert( validate_size< PlayerPokeDex,  2 * 19>::value, "PlayerPokeDex size does not match" );
static_assert(is_standard_layouted_trivial_aggregate<PlayerPokeDex>::value);

static_assert( validate_size< Player,  0x0F8C >::value, "Player size does not match" );  // 3980
static_assert(is_standard_layouted_trivial_aggregate<Player>::value);
static_assert(offsetof(Player, player_name) == 0x0000);
static_assert(offsetof(Player, pokedex) == 0x000B);
static_assert(offsetof(Player, sprite_data) == 0x0794);
static_assert(offsetof(Player, pokemon_team) == 0x0994);
static_assert(offsetof(Player, box_active) == 0x0B28);
static_assert(offsetof(Player, tilesetType) == 0x0F8A);
static_assert(offsetof(Player, checksum) == 0x0F8B);

static_assert( validate_size< SRAM_SaveFile,  0x8000 >::value);  // 32768
static_assert(is_standard_layouted_trivial_aggregate<SRAM_SaveFile>::value);

static_assert(offsetof(SRAM_SaveFile, bank0.spriteBuffer0) == 0x0000);
static_assert(offsetof(SRAM_SaveFile, bank0.spriteBuffer1) == 0x0188);
static_assert(offsetof(SRAM_SaveFile, bank0.spriteBuffer2) == 0x0310);
static_assert(offsetof(SRAM_SaveFile, bank0._0498) == 0x0498);
static_assert(offsetof(SRAM_SaveFile, bank0.hallOfFame) == 0x0598);
static_assert(offsetof(SRAM_SaveFile, bank0._1858) == 0x1858);

static_assert(offsetof(SRAM_SaveFile, bank1._2000) == 0x2000);
static_assert(offsetof(SRAM_SaveFile, bank1.player) == 0x2598);

static_assert(offsetof(SRAM_SaveFile, bank2.boxses0) == 0x4000);
static_assert(offsetof(SRAM_SaveFile, bank2._5A53) == 0x5A53);

static_assert(offsetof(SRAM_SaveFile, bank3.boxses1) == 0x6000);
static_assert(offsetof(SRAM_SaveFile, bank3._7A53) == 0x7A53);

#endif //POKE_TYPES_HPP
