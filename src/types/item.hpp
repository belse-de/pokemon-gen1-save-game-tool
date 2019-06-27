//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_TYPES_ITEM_HPP
#define POKESAVEGAMETOOL_TYPES_ITEM_HPP

#include <cstddef> // offsetof, std::size_t
#include <cstdint>

#include <cereal/cereal.hpp>
#include <cereal/types/polymorphic.hpp>

#include "../traits.hpp"
#include "../constans.hpp"


struct Item {
    std::uint8_t idx;
    std::uint8_t count;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(idx), CEREAL_NVP(count));
    }
};
static_assert(is_standard_layouted_trivial_aggregate<Item>::value);
static_assert(sizeof(Item) == 2);
static_assert(offsetof(Item, idx) == 0x00);
static_assert(offsetof(Item, count) == 0x01);


template <int size>
struct ItemList {
    std::uint8_t count;
    Item items[size];
    std::uint8_t terminator;

    template<class Archive>
    void serialize(Archive & archive)
    {
      archive( CEREAL_NVP(count), CEREAL_NVP(items), CEREAL_NVP(terminator) );
    }

};

using ItemList_Bag = ItemList<BAG_ITEM_CAPACITY>;
using ItemList_PC = ItemList<PC_ITEM_CAPACITY>;


static_assert(is_standard_layouted_trivial_aggregate<ItemList_Bag>::value);
static_assert(sizeof(ItemList_Bag) == 42);
static_assert(offsetof(ItemList_Bag, count) == 0x00);
static_assert(offsetof(ItemList_Bag, items) == 0x01);
static_assert(offsetof(ItemList_Bag, terminator) == 0x01 + sizeof(Item) * BAG_ITEM_CAPACITY);

static_assert(is_standard_layouted_trivial_aggregate<ItemList_PC>::value);
static_assert(sizeof(ItemList_PC) == 102);
static_assert(offsetof(ItemList_PC, count) == 0x00);
static_assert(offsetof(ItemList_PC, items) == 0x01);
static_assert(offsetof(ItemList_PC, terminator) == 0x01 + sizeof(Item) * PC_ITEM_CAPACITY);

#endif //POKESAVEGAMETOOL_TYPES_ITEM_HPP
