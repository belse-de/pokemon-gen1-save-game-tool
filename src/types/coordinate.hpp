#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <cstdint>
#include <cereal/cereal.hpp>

#include "../traits.hpp"

struct Coordinate{
    std::uint8_t y;
    std::uint8_t x;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(y), CEREAL_NVP(x) );
    }
};
static_assert (is_standard_layouted_trivial_aggregate<Coordinate>::value);
static_assert (sizeof (Coordinate) == 0x02);

#endif // COORDINATE_HPP
