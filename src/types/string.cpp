//
// Created by belse on 27.05.18.
//

#include "string.hpp"

const std::map<uint8_t, std::string> char_map = []() {
    std::map<uint8_t, std::string> char_map;
    for (unsigned i = 0; i < 256; ++i) {
        if (i == 0x00) { char_map[0x00] = "\0"; } // TODO: create string containing 0
        else if (i >= 0x01 and i <= 0x47) {} // junk / kanji
        else if (i >= 0x48 and i <= 0x5F) {} // controll chars
        else if (i >= 0x60 and i <= 0x6C) {} // junk / latin
        else if (i == 0x6D) { char_map.insert({i, ":"}); }
        else if (i >= 0x6E and i <= 0x78) {} // junk / latin
        else if (i >= 0x79 and i <= 0x7E) {} // text box borders

        else if (i == 0x7F) { char_map[i & 0xFF] = " "; }
        else if (i >= 0x80 and i <= 0x99) { char_map[i & 0xFF] = i - 0x80u + 'A'; }
        else if (i == 0x9A) { char_map[i & 0xFF] = "("; }
        else if (i == 0x9B) { char_map[i & 0xFF] = ")"; }
        else if (i == 0x9C) { char_map[i & 0xFF] = ":"; }
        else if (i == 0x9D) { char_map[i & 0xFF] = ";"; }
        else if (i == 0x9E) { char_map[i & 0xFF] = "["; }
        else if (i == 0x9F) { char_map[i & 0xFF] = "]"; }
        else if (i >= 0xA0 and i <= 0xB9) { char_map[i & 0xFF] = i - 0xA0u + 'a'; }
        else if (i == 0xBA) { char_map[i & 0xFF] = "é"; }
        else if (i == 0xBB) { char_map[i & 0xFF] = "'d"; }
        else if (i == 0xBC) { char_map[i & 0xFF] = "'l"; }
        else if (i == 0xBD) { char_map[i & 0xFF] = "'s"; }
        else if (i == 0xBE) { char_map[i & 0xFF] = "'t"; }
        else if (i == 0xBF) { char_map[i & 0xFF] = "'v"; }
        else if (i >= 0xC0 and i <= 0xDF) {} // junk / kanji
        else if (i == 0xE0) { char_map[i & 0xFF] = "'"; }
        else if (i == 0xE1) { char_map[i & 0xFF] = ""; }
        else if (i == 0xE2) { char_map[i & 0xFF] = "MN"; }
        else if (i == 0xE3) { char_map[i & 0xFF] = "-"; }
        else if (i == 0xE4) { char_map[i & 0xFF] = "'r"; }
        else if (i == 0xE5) { char_map[i & 0xFF] = "'m"; }
        else if (i == 0xE6) { char_map[i & 0xFF] = "?"; }
        else if (i == 0xE7) { char_map[i & 0xFF] = "!"; }
        else if (i == 0xE8) { char_map[i & 0xFF] = "."; }
        else if (i >= 0xE9 and i <= 0xEB) {} // junk / kanji
        else if (i == 0xEC) { char_map[i & 0xFF] = "▷"; }
        else if (i == 0xED) { char_map[i & 0xFF] = "▶"; }
        else if (i == 0xEE) { char_map[i & 0xFF] = "▼"; }
        else if (i == 0xEF) { char_map[i & 0xFF] = "♂"; }
        else if (i == 0xF0) { char_map[i & 0xFF] = "$"; }
        else if (i == 0xF1) { char_map[i & 0xFF] = "×"; }
        else if (i == 0xF2) { char_map[i & 0xFF] = "."; }
        else if (i == 0xF3) { char_map[i & 0xFF] = "/"; }
        else if (i == 0xF4) { char_map[i & 0xFF] = ","; }
        else if (i == 0xF5) { char_map[i & 0xFF] = "♀"; }
        else if (i >= 0xF6 and i <= 0xFF) { char_map[i & 0xFF] = i - 0xF6u + '0'; }
    }
    return char_map;
}();

const std::map<std::string, uint8_t> char_map_inverse = [](std::map<uint8_t, std::string> const& char_map) {
    std::map<std::string, uint8_t> char_map_inverse;

    for(auto const& pair : char_map){
        char_map_inverse.insert({pair.second, pair.first});
    }

    return char_map_inverse;
}(char_map);
