#include <iostream>
#include <filesystem>
#include <fstream>
#include <cinttypes>
#include <map>
#include <array>
#include <cassert>

#include <cereal/archives/json.hpp>
#include <cereal/types/map.hpp>

namespace fs = std::filesystem;

#include "src/types.hpp"




#include <cassert>
void uniton_test()
{
    bits_uint8_t bui;
    bui.ui = 0b00000001;
    assert(bui.b.b0);
    bui.ui = 0b00000010;
    assert(bui.b.b1);
    bui.ui = 0b00000100;
    assert(bui.b.b2);
    bui.ui = 0b00001000;
    assert(bui.b.b3);
    bui.ui = 0b00010000;
    assert(bui.b.b4);
    bui.ui = 0b00100000;
    assert(bui.b.b5);
    bui.ui = 0b01000000;
    assert(bui.b.b6);
    bui.ui = 0b10000000;
    assert(bui.b.b7);
}

int main(int argc, char* argv[]) {
   uniton_test();
    assert(argc == 2);




    //cereal::JSONOutputArchive archive( std::cout );
    //archive(CEREAL_NVP(char_map));
    //archive(CEREAL_NVP(char_map_inverse));

    char sram_raw[sizeof(SRAM_SaveFile)];

    //fs::path sram_rel = fs::u8path(u8"../sram-images/Pokemon Rot (D)-02.srm");
    fs::path sram_rel = fs::u8path(argv[1]);
    fs::path sram_abs = fs::absolute(sram_rel);

    std::ifstream file(sram_abs, std::ios::in | std::ios::binary);

    if (file.read(sram_raw, sizeof(SRAM_SaveFile))) {
        /* worked! */
        /*for (unsigned i = 0; i < sizeof(SRAM_SaveFile); ++i) {
            printf("%02" PRIX8 " ", (uint8_t) sram_raw[i & 0xFF]);
            if (i % 16 == 15) {
                printf("\n");
            }
        }*/

        SRAM_SaveFile* sram = reinterpret_cast<SRAM_SaveFile*>(sram_raw);
        cereal::JSONOutputArchive archive( std::cout );
        archive(*sram);
    }

    return 0;
}
