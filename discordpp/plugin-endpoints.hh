#pragma once

namespace discordpp {
template <class BASE> class PluginEndpoints : public BASE, virtual BotStruct {
#define ENDPOINT_BREAKOUTS
#include "categories/channel.hh"
#undef ENDPOINT_BREAKOUTS
};

} // namespace discordpp