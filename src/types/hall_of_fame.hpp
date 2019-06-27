#ifndef HALL_OF_FAME_H
#define HALL_OF_FAME_H

#include <cstddef> // offsetof, std::size_t

#include <cereal/cereal.hpp>

#include "../traits.hpp"
#include "../constans.hpp"
#include "name.hpp"

struct HOF_PokeMon {
  uint8_t ID;
  uint8_t level;
  Name    name;
  uint8_t padding[3];

  template<class Archive>
  void serialize(Archive & archive)
  {
    archive(CEREAL_NVP(ID),
            CEREAL_NVP(level),
            CEREAL_NVP(name)
           );
  }
};

static_assert(is_standard_layouted_trivial_aggregate<HOF_PokeMon>::value);
static_assert(std::is_aggregate<HOF_PokeMon>::value);
static_assert(std::is_trivial<HOF_PokeMon>::value);
static_assert(sizeof(HOF_PokeMon) == HALL_OF_FAME_MON);
static_assert(offsetof(HOF_PokeMon, ID) == 0x00);
static_assert(offsetof(HOF_PokeMon, level) == 0x01);
static_assert(offsetof(HOF_PokeMon, name) == 0x02);

struct HOF_Record {
  HOF_PokeMon team[6];

  template<class Archive>
  void serialize(Archive & archive)
  {
    archive(CEREAL_NVP(team));
  }
};

static_assert(std::is_standard_layout<HOF_Record>::value);
static_assert(std::is_aggregate<HOF_Record>::value);
static_assert(std::is_trivial<HOF_Record>::value);
static_assert(sizeof(HOF_Record) == HALL_OF_FAME_TEAM);
static_assert(offsetof(HOF_Record, team) == 0x00);

struct HallOfFame {
  HOF_Record records[HALL_OF_FAME_TEAM_CAPACITY];

  template<class Archive>
  void serialize(Archive & archive)
  {
    archive(CEREAL_NVP(records));
  }
};

static_assert(std::is_standard_layout<HallOfFame>::value);
static_assert(std::is_aggregate<HallOfFame>::value);
static_assert(std::is_trivial<HallOfFame>::value);
static_assert(sizeof(HallOfFame) == HALL_OF_FAME_TEAM * HALL_OF_FAME_TEAM_CAPACITY);
static_assert(offsetof(HallOfFame, records) == 0x00);

#endif // HALL_OF_FAME_H
