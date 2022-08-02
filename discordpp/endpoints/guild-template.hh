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

// https://discord.com/developers/docs/resources/guild-template#get-guild-template
// TODO unverified
#define Parent Call
#define Class GetGuildTemplateCall
#define function getGuildTemplate
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, template_code, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/templates/{}", ARR(template_code), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-template#create-guild-from-guild-template
// TODO unverified
#define Parent JsonCall
#define Class CreateGuildFromTemplateCall
#define function createGuildFromTemplate
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, template_code, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(target))
NEW_FIELD(std::string, icon, USEDBY(target))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/templates/{}", ARR(template_code), )
AUTO_PAYLOAD(PFR(name) PFO(icon))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-template#get-guild-templates
// TODO unverified
#define Parent Call
#define Class GetGuildTemplatesCall
#define function getGuildTemplates
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/guilds/{}/templates", ARR(guild_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-template#create-guild-template
// TODO unverified
#define Parent JsonCall
#define Class CreateGuildTemplateCall
#define function createGuildTemplates
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, template_code, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(target))
NEW_FIELD(std::optional<std::string>, description, USEDBY(target))
STATIC_FIELD(std::string, method, "POST")
AUTO_TARGET("/guilds/templates/{}", ARR(template_code), )
AUTO_PAYLOAD(PFR(name) PFO(description))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-template#sync-guild-template
// TODO unverified
#define Parent Call
#define Class SyncGuildTemplateCall
#define function syncGuildTemplate
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, template_code, USEDBY(target))
STATIC_FIELD(std::string, method, "PUT")
AUTO_TARGET("/guilds/{}/templates/{}", ARR(guild_id, template_code), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
// This line intentionally left blank
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-template#modify-guild-template
// TODO unverified
#define Parent JsonCall
#define Class ModifyGuildTemplateCall
#define function modifyGuildTemplates
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, template_code, USEDBY(target))
NEW_FIELD(std::string, name, USEDBY(target))
NEW_FIELD(std::optional<std::string>, description, USEDBY(target))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/guilds/templates/{}", ARR(template_code), )
AUTO_PAYLOAD(PFO(name) PFO(description))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/guild-template#delete-guild-template
// TODO unverified
#define Parent Call
#define Class DeleteGuildTemplateCall
#define function deleteGuildTemplate
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, guild_id, USEDBY(target))
NEW_FIELD(std::string, template_code, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/guilds/{}/templates/{}", ARR(guild_id, template_code), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
