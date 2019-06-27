#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

#include <cstdint>

#include "../traits.hpp"

enum struct MovementType : std::uint8_t{
    Walking = 0,
    Biking = 1,
    Surfing = 2
};
static_assert (is_standard_layouted_trivial<MovementType>::value);
static_assert (sizeof (MovementType) == 0x01);

template<class Archive>
void serialize(Archive & archive,
               MovementType & m)
{
  archive( m );
}

#endif // MOVEMENT_HPP
