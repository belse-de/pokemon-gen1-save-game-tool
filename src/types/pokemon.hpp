//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_TYPES_POKEMON_HPP
#define POKESAVEGAMETOOL_TYPES_POKEMON_HPP

#include <cstdint>
#include <type_traits>
#include "../constans.hpp"
#include "../check_size.hpp"
#include "name.hpp"
#include "uint_BE.hpp"
#include <cereal/cereal.hpp>

enum class StatusCondition : uint8_t {
    Asleep = 0x04,
    Poisoned = 0x08,
    Burned = 0x10,
    Frozen = 0x20,
    Paralyzed = 0x40,
};

enum class Type : uint8_t {
    Normal = 0,
    Fighting = 1,
    Flying = 2,
    Poison = 3,
    Ground = 4,
    Rock = 5,
    Bug = 7,
    Ghost = 8,
    Fire = 20,
    Water = 21,
    Grass = 22,
    Electric = 23,
    Psychic = 24,
    Ice = 25,
    Dragon = 26,
};

struct EffortValues {
    be_uint16_t health;
    be_uint16_t attack;
    be_uint16_t defense;
    be_uint16_t speed;
    be_uint16_t special;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(health),
               CEREAL_NVP(attack),
               CEREAL_NVP(defense),
               CEREAL_NVP(speed),
               CEREAL_NVP(special) );
    }
};

struct EffectivStats {
    be_uint16_t health;
    be_uint16_t attack;
    be_uint16_t defense;
    be_uint16_t speed;
    be_uint16_t special;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(health),
               CEREAL_NVP(attack),
               CEREAL_NVP(defense),
               CEREAL_NVP(speed),
               CEREAL_NVP(special) );
    }
};


struct PokeMon_Slim {
    uint8_t ID;
    be_uint16_t health_points;
    uint8_t level;
    StatusCondition status_condition;
    Type type[2];
    uint8_t catch_rate;
    uint8_t moves_idxs[4];
    be_uint16_t original_trainer_ID;
    be_uint24_t experience_points;
    EffortValues ev;
    uint8_t individual_values[2];
    uint8_t moves_powerpoints[4];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(ID),
               CEREAL_NVP(health_points),
               CEREAL_NVP(level),
               CEREAL_NVP(status_condition),
               CEREAL_NVP(type),
               CEREAL_NVP(catch_rate),
               CEREAL_NVP(moves_idxs),
               CEREAL_NVP(original_trainer_ID),
               CEREAL_NVP(experience_points),
               CEREAL_NVP(ev),
               CEREAL_NVP(individual_values),
               CEREAL_NVP(moves_powerpoints)
             );
    }
};

struct PokeMon {
    PokeMon_Slim base;
    uint8_t _levelCopy;
    EffectivStats stats;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(base), CEREAL_NVP(_levelCopy), CEREAL_NVP(stats) );
    }
};

template<int size, typename PT>
struct PokeList {
    uint8_t count;
    uint8_t species[size + 1];
    PT pokemon[size];
    Name OT[size];
    Name pokemon_names[size];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(count),
               CEREAL_NVP(species),
               CEREAL_NVP(pokemon),
               CEREAL_NVP(OT),
               CEREAL_NVP(pokemon_names) );
    }
};
using PokeList_Bag = PokeList<PARTY_LENGTH, PokeMon>;
using PokeList_Box = PokeList<MONS_PER_BOX, PokeMon_Slim>;

struct BoxBank {
    PokeList_Box boxes[6];
    uint8_t checksum;
    uint8_t boxes_checksum[6];

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(boxes), CEREAL_NVP(checksum), CEREAL_NVP(boxes_checksum) );
    }
};

static_assert(sizeof(StatusCondition) == 1);
static_assert(sizeof(Type) == 1);

static_assert(sizeof(EffortValues) == 10);
static_assert(std::is_standard_layout<EffortValues>::value);
static_assert(std::is_aggregate<EffortValues>::value);
static_assert(std::is_trivial<EffortValues>::value);
static_assert(offsetof(EffortValues, health) == 0x00);
static_assert(offsetof(EffortValues, attack) == 0x02);
static_assert(offsetof(EffortValues, defense) == 0x04);
static_assert(offsetof(EffortValues, speed) == 0x06);
static_assert(offsetof(EffortValues, special) == 0x08);

static_assert(sizeof(EffectivStats) == 10);
static_assert(std::is_standard_layout<EffectivStats>::value);
static_assert(std::is_aggregate<EffectivStats>::value);
static_assert(std::is_trivial<EffectivStats>::value);
static_assert(offsetof(EffectivStats, health) == 0x00);
static_assert(offsetof(EffectivStats, attack) == 0x02);
static_assert(offsetof(EffectivStats, defense) == 0x04);
static_assert(offsetof(EffectivStats, speed) == 0x06);
static_assert(offsetof(EffectivStats, special) == 0x08);

static_assert(validate_size<PokeMon_Slim, 33>::value);
static_assert(sizeof(PokeMon_Slim) == 33);
static_assert(std::is_standard_layout<PokeMon_Slim>::value);
static_assert(std::is_aggregate<EffortValues>::value);
static_assert(std::is_trivial<EffortValues>::value);
static_assert(offsetof(PokeMon_Slim, ID) == 0x00);
static_assert(offsetof(PokeMon_Slim, health_points) == 0x01);
static_assert(offsetof(PokeMon_Slim, level) == 0x03);
static_assert(offsetof(PokeMon_Slim, status_condition) == 0x04);
static_assert(offsetof(PokeMon_Slim, type) == 0x05);
static_assert(offsetof(PokeMon_Slim, catch_rate) == 0x07);
static_assert(offsetof(PokeMon_Slim, moves_idxs) == 0x08);
static_assert(offsetof(PokeMon_Slim, original_trainer_ID) == 0x0C);
static_assert(offsetof(PokeMon_Slim, experience_points) == 0x0E);
static_assert(offsetof(PokeMon_Slim, ev) == 0x11);
static_assert(offsetof(PokeMon_Slim, individual_values) == 0x1B);
static_assert(offsetof(PokeMon_Slim, moves_powerpoints) == 0x1D);

static_assert(sizeof(PokeMon) == 44);
static_assert(std::is_standard_layout<PokeMon>::value);
static_assert(std::is_aggregate<PokeMon>::value);
static_assert(std::is_trivial<PokeMon>::value);
static_assert(offsetof(PokeMon, base) == 0x00);
static_assert(offsetof(PokeMon, _levelCopy) == 0x21);
// FIXME: missing offset check

static_assert(sizeof(PokeList_Bag) == 404);
static_assert(std::is_standard_layout<PokeList_Bag>::value);
static_assert(std::is_aggregate<PokeList_Bag>::value);
static_assert(std::is_trivial<PokeList_Bag>::value);
static_assert(offsetof(PokeList_Bag, count) == 0x0000);
static_assert(offsetof(PokeList_Bag, species) == 0x0001);
static_assert(offsetof(PokeList_Bag, pokemon) == 0x0008);
static_assert(offsetof(PokeList_Bag, OT) == 0x0110);
static_assert(offsetof(PokeList_Bag, pokemon_names) == 0x0152);

static_assert(sizeof(PokeList_Box) == 1122);
static_assert(std::is_standard_layout<PokeList_Box>::value);
static_assert(std::is_aggregate<PokeList_Box>::value);
static_assert(std::is_trivial<PokeList_Box>::value);
static_assert(offsetof(PokeList_Box, count) == 0x0000);
static_assert(offsetof(PokeList_Box, species) == 0x0001);
static_assert(offsetof(PokeList_Box, pokemon) == 0x0016);
static_assert(offsetof(PokeList_Box, OT) == 0x02AA);
static_assert(offsetof(PokeList_Box, pokemon_names) == 0x0386);

static_assert(sizeof(BoxBank) == 0x1A53);
static_assert(std::is_standard_layout<BoxBank>::value);
static_assert(std::is_aggregate<BoxBank>::value);
static_assert(std::is_trivial<BoxBank>::value);
static_assert(offsetof(BoxBank, boxes) == 0x0000);
static_assert(offsetof(BoxBank, checksum) == 0x1A4C);
static_assert(offsetof(BoxBank, boxes_checksum) == 0x1A4D);

#endif //POKESAVEGAMETOOL_TYPES_POKEMON_HPP
