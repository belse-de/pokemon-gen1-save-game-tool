//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_CONSTANS_HPP
#define POKESAVEGAMETOOL_CONSTANS_HPP

constexpr int PARTY_LENGTH = 6;

constexpr int MONS_PER_BOX = 20;
constexpr int NUM_BOXES    = 12;

constexpr int BAG_ITEM_CAPACITY = 20;
constexpr int PC_ITEM_CAPACITY  = 50;

constexpr int HALL_OF_FAME_MON           = 0x10;
constexpr int HALL_OF_FAME_TEAM          = PARTY_LENGTH * HALL_OF_FAME_MON;
constexpr int HALL_OF_FAME_TEAM_CAPACITY = 50;

constexpr int NAME_LENGTH = 11;
constexpr int ITEM_NAME_LENGTH = 13;

constexpr int SPRITE_BUFFER_SIZE = 7 * 7 * 8; // 7 * 7 (tiles) * 8 (bytes per tile) = 188

#endif //POKESAVEGAMETOOL_CONSTANS_HPP
