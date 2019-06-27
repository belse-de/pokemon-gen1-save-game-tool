#ifndef SRAM_HPP
#define SRAM_HPP

#include <cereal/cereal.hpp>

#include "../traits.hpp"
#include "sram_bank0.hpp"
#include "sram_bank1.hpp"
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

static_assert(offsetof(SRAM_SaveFile, bank2.boxses) == 0x4000);
static_assert(offsetof(SRAM_SaveFile, bank2._unused) == 0x5A53);

static_assert(offsetof(SRAM_SaveFile, bank3.boxses) == 0x6000);
static_assert(offsetof(SRAM_SaveFile, bank3._unused) == 0x7A53);


static_assert(offsetof(SRAM_SaveFile, bank1.main_data.pokedex) == 0x25A3);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.player_pc) == 0x27E6);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2603) == 0x2603);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2612) == 0x2612);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._26DC) == 0x26DC);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._27E2) == 0x27E2);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._284F) == 0x284F);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2872) == 0x2872);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2879) == 0x2879);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29AD) == 0x29AD);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29BD) == 0x29BD);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29C0) == 0x29C0);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29C2) == 0x29C2);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29C7) == 0x29C7);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29CB) == 0x29CB);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29D5) == 0x29D5);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29D7) == 0x29D7);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29DB) == 0x29DB);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29DD) == 0x29DD);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29E5) == 0x29E5);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.pikachu_friendship) == 0x29E6);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29E9) == 0x29E9);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.card_key_door_x) == 0x29EB);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.card_key_door_y) == 0x29EC);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29ED) == 0x29ED);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.trash_can_look) == 0x29EF);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._29F1) == 0x29F1);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.completed_game_events_flags) == 0x29F3);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.grass_rate) == 0x2B33);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.grass_pokemon) == 0x2B34);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.enemy_party_count) == 0x2B48); // 2B48
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2B49) == 0x2B49);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.trainer_header_ptr) == 0x2CDC); // 3DCE
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2CDE) == 0x2CDE);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.wrong_answer_opponent_ID) == 0x2CE4);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.current_map_script) == 0x2CE5);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data._2CE6) == 0x2CE6);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.time_played) == 0x2CED);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.safari_game_over) == 0x2CF2);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.safari_ball_count) == 0x2CF3);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.daycare_in_use) == 0x2CF4);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.daycare_pokemon_name) == 0x2CF5);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.daycare_pokemon_original_trainer) == 0x2D00);
static_assert(offsetof(SRAM_SaveFile, bank1.main_data.daycare_pokemon) == 0x2D0B);
static_assert(offsetof(SRAM_SaveFile, bank1.sprite_data) == 0x2D2C);

#endif // SRAM_HPP
