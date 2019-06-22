//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_TYPES_NAME_HPP
#define POKESAVEGAMETOOL_TYPES_NAME_HPP

#include <cstdint>
#include <type_traits>
#include "../constans.hpp"
#include "../traits.h"
#include "string.hpp"
#include <cereal/cereal.hpp>

/*
struct Name {
    //FIXME: should be a poke_str
    String<NAME_LENGTH> str;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(str) );
    }
};
*/

using Name = PokeString<NAME_LENGTH>;
static_assert(sizeof(Name) == 11);
static_assert(std::is_standard_layout<Name>::value);
static_assert(std::is_trivial<Name>::value);
static_assert(std::is_aggregate<Name>::value);
static_assert(is_standard_layouted_trivial_aggregate<Name>::value);




#endif //POKESAVEGAMETOOL_TYPES_NAME_HPP
