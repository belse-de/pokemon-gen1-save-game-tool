
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

#define SASSERT_EQU(a,b, msg) static_assert((a) == (b), msg ": " ##a " != " ##b)

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
static_assert( validate_size< PlayerPokeDex,  2 * 19>::value, "PlayerPokeDex size does not match" );
static_assert(is_standard_layouted_trivial_aggregate<PlayerPokeDex>::value);


enum struct MovementType : uint8_t{
    Walking = 0,
    Biking = 1,
    Surfing = 2
};
static_assert (is_standard_layouted_trivial_aggregate<MovementType>::value);
static_assert (sizeof (MovementType) == 0x01);





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

#endif //POKE_TYPES_HPP
