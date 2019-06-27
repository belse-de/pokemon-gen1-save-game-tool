#ifndef SRAM_BANK1_MAIN_DATA_HPP
#define SRAM_BANK1_MAIN_DATA_HPP

#include "../traits.h"
#include "../constans.hpp"
#include "../types/coordinate.hpp"
#include "../types/name.hpp"
#include "../types/pokemon.hpp" //FIXME

// offset in safe 0x2598
struct MainData {
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
    Coordinate     player_pos;
    Coordinate     player_block_pos;
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
    uint8_t        sprite_picture_set_IDs[0x0B];
    uint8_t        sprite_set_ID;
    be_uint16_t    tmp_obj_data_pointers[2];
    uint8_t        out_of_bound_tile_ID;
    uint8_t        warp_count;
    uint8_t        warp_entries[0x80];
    uint8_t        warp_destination_ID; // 0x26DB
    uint8_t        _26DC[0x80];
    uint8_t        sign_count;
    Coordinate     sign_pos[0x10]; // y,x
    uint8_t        sign_text_IDs[0x10];
    uint8_t        sprite_count;
    Coordinate     offset_from_last_special_warp;
    uint8_t        sprite_data[0x20];
    uint8_t        sprite_data_extra[0x20];
    uint8_t        current_map_meta_height; //meta = tile 2x2
    uint8_t        current_map_meta_width; //meta = tile 2x2
    be_uint16_t    current_map_view_vram_ptr;
    uint8_t        player_move_direction;
    uint8_t        player_last_stop_direction;
    uint8_t        player_direction;
    uint8_t        tileset_bank;
    be_uint16_t    tileset_block_ptr;
    be_uint16_t    tileset_gfx_ptr;
    be_uint16_t    tileset_collision_ptr;
    uint8_t        tileset_talkover[3];
    uint8_t        tileset_grass;
    uint8_t        _27E2[4];
    ItemList_PC    player_pc;
    uint8_t        pc_box_active_idx[2];
    uint8_t        HOF_teams_count;
    uint8_t        _284F;
    uint8_t        casino_coins[2]; // slot coins BCD BE
    uint8_t        hidden_objects_flags[0x20]; //bit array, set = removed
    uint8_t        _2872[0x07]; // padding
    uint8_t        _2879; // scratch
    uint8_t        hidden_object_list[0x22]; // 17 * 2 {sprite id, index}
    uint8_t        completed_scripts[0x100];
    uint8_t        optained_hidden_objects_flags[0x0E];
    uint8_t        optained_hidden_coins_flags[0x02];
    MovementType   movement_state;
    uint8_t        _29AD[0x0A];
    uint8_t        town_visited_flags[2]; // 13
    uint8_t        safari_steps[2];
    uint8_t        cinnabar_lab_fossil_given;
    uint8_t        cinnabar_lab_fossil_pokemon;
    uint8_t        _29BD[2];
    uint8_t        enemy_mon_or_trainer_class;
    uint8_t        _29C0;
    uint8_t        rival_started;
    uint8_t        _29C2;
    uint8_t        player_starter;
    uint8_t        boulder_sprite_starter;
    uint8_t        last_blackout_map;
    uint8_t        destination_map;
    uint8_t        _29C7;
    uint8_t        collision_or_boulder;
    uint8_t        dungeon_warp_destination;
    uint8_t        dungeon_warp_source;
    uint8_t        _29CB[0x09];
    uint8_t        flags_1;
    uint8_t        _29D5;
    uint8_t        defeated_flags;
    uint8_t        _29D7;
    uint8_t        flags_2;
    uint8_t        flags_3;
    uint8_t        flags_4;
    uint8_t        _29DB;
    uint8_t        flags_5;
    uint8_t        _29DD;
    uint8_t        flags_6;
    uint8_t        flags_7;
    uint8_t        defeated_lorelei[2];
    uint8_t        flags_8;
    uint8_t        ingame_trades_flags[2];
    uint8_t        _29E5;
    uint8_t        pikachu_friendship; //_29E6
    uint8_t        warped_from_warp;
    uint8_t        warped_from_map;
    uint8_t        _29E9[2];
    uint8_t        card_key_door_x;
    uint8_t        card_key_door_y;
    uint8_t        _29ED[2];
    uint8_t        trash_can_look[2];
    uint8_t        _29F1[2];
    uint8_t        completed_game_events_flags[0x140];
    uint8_t        grass_rate;
    uint8_t        grass_pokemon[0x14];
    uint8_t        enemy_party_count; // 2B48
    uint8_t        _2B49[0x2CDC - 0x2B49];
    be_uint16_t    trainer_header_ptr; // 3DCE
    uint8_t        _2CDE[6];
    uint8_t        wrong_answer_opponent_ID;
    uint8_t        current_map_script;
    uint8_t        _2CE6[7];
    uint8_t        time_played[5];
    uint8_t        safari_game_over;
    uint8_t        safari_ball_count;
    uint8_t        daycare_in_use;
    Name           daycare_pokemon_name;
    Name           daycare_pokemon_original_trainer;
    PokeMon_Slim   daycare_pokemon;


    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(pokedex),
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
               CEREAL_NVP(time_played)//,
               //CEREAL_NVP(_2CF2),

              );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<MainData>::value);
static_assert (sizeof (MainData) == 0x789);
static_assert (sizeof (MainData) == offsetof(MainData, daycare_pokemon) + sizeof (PokeMon_Slim));



#endif // SRAM_BANK1_MAIN_DATA_HPP
