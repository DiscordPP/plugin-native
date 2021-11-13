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

#define OBJECT_BREAKOUTS
//#define Bot PluginObjects
#include "macros/define-objects.hh"
/* This space intentionally left blank */
using Timestamp = std::string;
/* This space intentionally left blank */
#include "discordpp/objects_fwd/application-commands_fwd.hh"
#include "discordpp/objects_fwd/application_fwd.hh"
#include "discordpp/objects_fwd/audit-log_fwd.hh"
#include "discordpp/objects_fwd/certified-devices_fwd.hh"
#include "discordpp/objects_fwd/channel_fwd.hh"
#include "discordpp/objects_fwd/emoji_fwd.hh"
#include "discordpp/objects_fwd/guild-template_fwd.hh"
#include "discordpp/objects_fwd/guild_fwd.hh"
#include "discordpp/objects_fwd/invite_fwd.hh"
#include "discordpp/objects_fwd/message-components_fwd.hh"
#include "discordpp/objects_fwd/oauth2_fwd.hh"
#include "discordpp/objects_fwd/permissions_fwd.hh"
#include "discordpp/objects_fwd/receiving-and-responding_fwd.hh"
#include "discordpp/objects_fwd/stage-instance_fwd.hh"
#include "discordpp/objects_fwd/sticker_fwd.hh"
#include "discordpp/objects_fwd/teams_fwd.hh"
#include "discordpp/objects_fwd/user_fwd.hh"
#include "discordpp/objects_fwd/voice_fwd.hh"
#include "discordpp/objects_fwd/webhook_fwd.hh"
/* This space intentionally left blank */
#include "discordpp/objects_fwd/gateway_fwd.hh"
/* This space intentionally left blank */
#include "objects/application-commands.hh"
#include "objects/application.hh"
#include "objects/audit-log.hh"
#include "objects/certified-devices.hh"
#include "objects/channel.hh"
#include "objects/emoji.hh"
#include "objects/gateway.hh"
#include "objects/guild-template.hh"
#include "objects/guild.hh"
#include "objects/invite.hh"
#include "objects/message-components.hh"
#include "objects/oauth2.hh"
#include "objects/permissions.hh"
#include "objects/stage-instance.hh"
#include "objects/sticker.hh"
#include "objects/teams.hh"
#include "objects/user.hh"
#include "objects/voice.hh"
#include "objects/webhook.hh"
/* This space intentionally left blank */
#include "objects/receiving-and-responding.hh"
/* This space intentionally left blank */
#include "macros/undefine-objects.hh"
//#undef Bot
#undef OBJECT_BREAKOUTS

template <class BASE> class PluginEndpoints : public BASE, virtual BotStruct {
#define ENDPOINT_BREAKOUTS
#define Bot PluginEndpoints

#include "endpoints/application-commands.hh"
#include "endpoints/audit-log.hh"
#include "endpoints/channel.hh"
#include "endpoints/emoji.hh"
#include "endpoints/guild-template.hh"
#include "endpoints/guild.hh"
#include "endpoints/invite.hh"
#include "endpoints/receiving-and-responding.hh"
#include "endpoints/stage-instance.hh"
#include "endpoints/sticker.hh"
#include "endpoints/user.hh"
#include "endpoints/voice.hh"
#include "endpoints/webhook.hh"

#undef Bot
#undef ENDPOINT_BREAKOUTS
};

} // namespace discordpp