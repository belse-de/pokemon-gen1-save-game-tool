//
// Created by belse on 27.05.18.
//

#ifndef POKESAVEGAMETOOL_STRING_HPP
#define POKESAVEGAMETOOL_STRING_HPP

#include <map>
#include <string>
#include <algorithm>



extern const std::map<uint8_t, std::string> char_map;
extern const std::map<std::string, uint8_t> char_map_inverse;

template<size_t S>
class PokeString {
    static constexpr size_t capacity = S;
    std::array<uint8_t, S> data;

    size_t size() const{
        auto res = std::find(data.cbegin(), data.cend(), 0x80);
        return std::distance(data.cbegin(), res);
    }

    std::string to_string() const{
        std::string res;

        for(std::size_t i = 0u; i < capacity and data[i] != 0x80; ++i){
            res += char_map.at(data[i]);
        }
        return res;
    }

    PokeString& from_string(std::string const&) {
        return *this;
    }

    template<class Archive>
    std::string save_minimal(Archive const&) const
    {
        return to_string();
    }

    template<class Archive>
    void load_minimal(Archive const&, std::string const& val)
    {
        from_string(val);
    }
};

//TODO: implement


#endif //POKESAVEGAMETOOL_STRING_HPP
