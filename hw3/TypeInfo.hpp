#ifndef HW3_TYPEINFO_HPP
#define HW3_TYPEINFO_HPP

#include <string>
#include <type_traits>
#include <vector>

template<typename T>
struct NameOf {
    static constexpr auto value = std::is_same_v<int, T> ? "int" : (std::is_same_v<char, T> ? "char"
                                                                                            : (std::is_same_v<short int, T>
                                                                                               ? "short int"
                                                                                               : "long int"));
};

template<typename T>
class TypeInfo {

public:
    std::string to_string() {
        if (std::is_array_v<T>)
            return TypeInfo<std::remove_all_extents_t<T>>().to_string() + get_array();
        else if (std::is_const_v<T>)
            return TypeInfo<std::remove_const_t<T>>().to_string() + " const";
        else if (std::is_volatile_v<T>)
            return TypeInfo<std::remove_volatile_t<T>>().to_string() + " volatile";
        else if (std::is_pointer_v<T>)
            return TypeInfo<std::remove_pointer_t<T>>().to_string() + " *";
        else if (std::is_integral_v<T>)
            return NameOf<T>::value;
        else if (std::is_lvalue_reference_v<T>)
            return TypeInfo<std::remove_reference_t<T>>().to_string() + " &";
        else if (std::is_rvalue_reference_v<T>)
            return TypeInfo<std::remove_reference_t<T>>().to_string() + " &&";
        else
            return "";
    }

public:
    std::string get_array() {
        if (std::is_array_v<T>)
            return "[" + std::to_string(std::extent_v<T, 0>) + "]" + TypeInfo<std::remove_extent_t<T>>().get_array();
        return "";
    }
};

#endif
