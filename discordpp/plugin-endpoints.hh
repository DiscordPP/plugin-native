#pragma once

#include <fmt/format.h>
#include <iomanip>

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
#define Bot PluginEndpoints

#include "categories/application-commands.hh"
#include "categories/audit-log.hh"
#include "categories/channel.hh"
#include "categories/emoji.hh"
#include "categories/guild-template.hh"
#include "categories/guild.hh"
#include "categories/invite.hh"
#include "categories/receiving-and-responding.hh"
#include "categories/stage-instance.hh"
#include "categories/sticker.hh"
#include "categories/user.hh"
#include "categories/voice.hh"
#include "categories/webhook.hh"

#undef Bot
#undef ENDPOINT_BREAKOUTS
};

} // namespace discordpp