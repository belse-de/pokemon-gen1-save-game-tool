//
// Created by belse on 25.05.18.
//

#ifndef POKESAVEGAMETOOL_UINT_BE_HPP
#define POKESAVEGAMETOOL_UINT_BE_HPP

#include <cstdint>
#include <cstddef>
#include <type_traits>
#include <cereal/cereal.hpp>

template <typename T>
struct be_uint{
    uint8_t raw[sizeof(T)];
    static constexpr T value_type{0};

    be_uint& set(T val){
        for(size_t i=0; i < sizeof(T); ++i){
            raw[i] = val & (0xFFu << ((sizeof(T) - 1 - i) * 8u));
        }
        return *this;
    }

    //TODO: check trait unsigned; operator<< is not well defined for signed
    //TODO: replace 8u with char/byte width

    T get() const {
        return *this;
    }

    operator T() const{
        T res = 0;
        for(size_t i=0; i < sizeof(T); ++i){
            res += raw[i] << ((sizeof(T) - 1 - i) * 8u);
        }
        return res;
    }

    template<class Archive>
      decltype(value_type) save_minimal(Archive const&) const
      {
        return *this;
      }

      template<class Archive>
      void load_minimal(Archive const&, decltype(value_type) val)
      {
        set(val);
      }
};

struct be_uint24_t{
    uint8_t raw[3];
    static constexpr uint32_t value_type{0};

    be_uint24_t& set(uint32_t val){
        for(size_t i=0; i < sizeof(raw); ++i){
            raw[i] = val & (0xFFu << ((sizeof(raw) - 1u - i) * 8u));
        }
        return *this;
    }

    //TODO: check trait unsigned; operator<< is not well defined for signed
    //TODO: replace 8u with char/byte width

    uint32_t get() const{
        return *this;
    }

    operator uint32_t() const{
        uint32_t res = 0;
        for(size_t i=0; i < sizeof(raw); ++i){
            res += raw[i] << ((sizeof(raw) - 1u - i) * 8u);
        }
        return res;
    }

    template<class Archive>
      uint32_t save_minimal(Archive const&) const
      {
        return *this;
      }

      template<class Archive>
      void load_minimal(Archive const&, uint32_t val)
      {
        set(val);
      }
};

using be_uint8_t  = be_uint<uint8_t>;
using be_uint16_t = be_uint<uint16_t>;
using be_uint32_t = be_uint<uint32_t>;
using be_uint64_t = be_uint<uint64_t>;

static_assert(std::is_standard_layout<be_uint8_t>::value);
static_assert(std::is_aggregate<be_uint8_t>::value);
static_assert(std::is_trivial<be_uint8_t>::value);

static_assert(std::is_standard_layout<be_uint16_t>::value);
static_assert(std::is_aggregate<be_uint16_t>::value);
static_assert(std::is_trivial<be_uint16_t>::value);

static_assert(std::is_standard_layout<be_uint24_t>::value);
static_assert(std::is_aggregate<be_uint24_t>::value);
static_assert(std::is_trivial<be_uint24_t>::value);

static_assert(std::is_standard_layout<be_uint32_t>::value);
static_assert(std::is_aggregate<be_uint32_t>::value);
static_assert(std::is_trivial<be_uint32_t>::value);

static_assert(std::is_standard_layout<be_uint64_t>::value);
static_assert(std::is_aggregate<be_uint64_t>::value);
static_assert(std::is_trivial<be_uint64_t>::value);

static_assert(sizeof(be_uint8_t) == 1);
static_assert(sizeof(be_uint16_t) == 2);
static_assert(sizeof(be_uint24_t) == 3);
static_assert(sizeof(be_uint32_t) == 4);
static_assert(sizeof(be_uint64_t) == 8);

#endif //POKESAVEGAMETOOL_UINT_BE_HPP
