#pragma once

#include <iomanip>
#include <fmt/format.h>

namespace discordpp {

namespace util {
// https://stackoverflow.com/a/17708801
inline std::string url_encode(const std::string &value) {
    std::ostringstream escaped;
    escaped.fill('0');
    escaped << std::hex;

    for (std::string::const_iterator i = value.begin(), n = value.end(); i != n;
         ++i) {
        std::string::value_type c = (*i);

        // Keep alphanumeric and other accepted characters intact
        if (std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == '~') {
            escaped << c;
            continue;
        }

        // Any other characters are percent-encoded
        escaped << std::uppercase;
        escaped << '%' << std::setw(2) << int((unsigned char)c);
        escaped << std::nouppercase;
    }

    return escaped.str();
}
} // namespace util

template <class BASE> class PluginEndpoints : public BASE, virtual BotStruct {
#define ENDPOINT_BREAKOUTS
#include "categories/channel.hh"
#include "categories/emoji.hh"
#include "categories/guild.hh"
#include "categories/user.hh"
#undef ENDPOINT_BREAKOUTS
};

} // namespace discordpp