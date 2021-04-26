#ifndef HW3_FORMAT_HPP
#define HW3_FORMAT_HPP

#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>

class format_error : public std::logic_error
{
  public:
    format_error() : logic_error{"Invalid format."}
    {

    }
};

template <typename... Args> std::string safe_format(std::string_view format_str, const Args &... args)
{
}

#endif
