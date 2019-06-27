//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_TYPES_NAME_HPP
#define POKESAVEGAMETOOL_TYPES_NAME_HPP

#include "../traits.hpp"
#include "../constans.hpp"

#include "string.hpp"

using Name = PokeString<NAME_LENGTH>;
static_assert(sizeof(Name) == 11);
static_assert(is_standard_layouted_trivial<Name>::value);

#endif //POKESAVEGAMETOOL_TYPES_NAME_HPP
