#ifndef HW3_FORMAT_HPP
#define HW3_FORMAT_HPP

#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>

class format_error : public std::logic_error {
public:
    format_error() : logic_error{"Invalid format."} {

    }
};

template<typename... Args>
void my_printf(std::stringstream &ss, std::string_view format_str)
{
    if(!format_str.empty()){
        if (format_str.front() == '%'){
            if (format_str.at(1) != '%')
                throw format_error();
            else{
                ss << '%';
                format_str.remove_prefix(2);
                return my_printf(ss, format_str);
            }
        }
        ss << format_str.front();
        format_str.remove_prefix(1);
        return my_printf(ss, format_str);
    }
}

template<typename T, typename... Args>
void my_printf(std::stringstream &ss, std::string_view format_str, T value)
{
    if (!format_str.empty()){
        if (format_str.front() == '%'){
            if (format_str.at(1) != '%'){
                ss << value;
                format_str.remove_prefix(2);
                return my_printf(ss, format_str);
            }
            else{
                ss << '%';
                format_str.remove_prefix(2);
            }
        }
        else{
            ss << format_str.front();
            format_str.remove_prefix(1);
        }
        return my_printf(ss, format_str, value);
    }
    throw format_error();
}

template<typename T, typename... Args>
void my_printf(std::stringstream &ss, std::string_view format_str, T value, Args... args) {
    if (!format_str.empty()) {
        if (format_str.front() != '%') {
            ss << format_str.front();
            format_str.remove_prefix(1);
        }
        else{
            if (format_str.at(1) != '%'){
                ss << value;
                format_str.remove_prefix(2);
            }
            else{
                ss << '%';
                format_str.remove_prefix(2);
            }
        }
        return my_printf(ss, format_str, args...);
    }
    throw format_error();
}

template<typename... Args>
std::string safe_format(std::string_view format_str, const Args &... args) {
    std::stringstream ss;
    my_printf(ss, format_str, args...);
    return ss.str();
}

#endif
