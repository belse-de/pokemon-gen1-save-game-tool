cmake_minimum_required(VERSION 3.9)
project(pokeSaveGameTool)

set(CMAKE_CXX_STANDARD 17)

add_library(stdc++fs UNKNOWN IMPORTED)
set_property(TARGET stdc++fs PROPERTY IMPORTED_LOCATION "/usr/lib/libstdc++fs.a")

add_executable(pokeSaveGameTool main.cpp
        src/constans.hpp
        src/check_size.hpp
        src/mem_manipulation.hpp
        src/types/item.hpp
        src/types/pokemon.hpp
        src/types/name.hpp
        ../BinaryCodedDecimal/src/scrap_bcd.hpp
        src/types/uint_BE.hpp
        src/types/string.cpp src/types/string.hpp
        src/types/uint_LE.hpp
        src/types/hall_of_fame.hpp
        src/types/bitarray.hpp
        src/types/coordinate.hpp
        src/types/pokedex.hpp
        src/types/movement.hpp

        src/traits.hpp
        src/memory/sram.hpp
        src/memory/sram_bank0.hpp
        src/memory/sram_bank1.hpp
        src/memory/sram_bank1_main_data.hpp
        src/memory/sram_bank34.hpp

        )

target_link_libraries(pokeSaveGameTool stdc++fs)
target_include_directories(pokeSaveGameTool PRIVATE cereal-1.2.2/include)
