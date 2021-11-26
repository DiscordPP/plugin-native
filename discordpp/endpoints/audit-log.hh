//
// Created by Aidan on 8/27/2021.
//

// Howdy! This file contains unverified endpoints so they may need touching up.
// Sorry for the mess, I just don't have the time to verify everything by hand,
// especially with the volatile nature of a live service like Discord. If
// something doesn't work come swing by #🔚endpoints on the Discord++ server and
// someone'll help you out! If the endpoints work fine swing by that same
// channel with proof of credit for the @Endpoint Verifier role!

#ifndef ENDPOINT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

// https://discord.com/developers/docs/resources/audit-log#get-guild-audit-log
// TODO unverified
#define Parent Call
#define Class GetGuildAuditLogCall
#define function getGuildAuditLog
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, user_id, USEDBY(target))
NEW_FIELD(AuditLogEvent, action_type, USEDBY(target))
NEW_FIELD(Snowflake, before, USEDBY(target))
NEW_FIELD(int, limit, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/audit-logs", ARR(guild_id),
            QSO(user_id) QSO(action_type) QSO(before) QSO(limit))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
