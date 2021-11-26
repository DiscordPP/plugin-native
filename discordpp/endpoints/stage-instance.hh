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

// https://discord.com/developers/docs/resources/stage-instance#create-stage-instance
// TODO unverified
#define Parent JsonCall
#define Class CreateStageInstanceLogCall
#define function createStageInstance
#include <discordpp/macros/defineCallOpen.hh>
STATIC_FIELD(std::string, method, "POST")
STATIC_FIELD(std::string, target, "/stage-instances")
NEW_FIELD(Snowflake, channel_id, USEDBY(payload))
NEW_FIELD(std::string, topic, USEDBY(payload))
NEW_FIELD(int, privacy_level, USEDBY(payload))
AUTO_PAYLOAD(PFR(channel_id) PFR(topic) PFO(privacy_level))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/stage-instance#get-stage-instance
//  TODO unverified
#define Parent Call
#define Class GetStageInstanceLogCall
#define function getStageInstance
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/stage-instances/{}", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/stage-instance#modify-stage-instance
//  TODO unverified
#define Parent JsonCall
#define Class ModifyStageInstanceLogCall
#define function modifyStageInstance
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "PATCH")
AUTO_TARGET("/stage-instances/{}", ARR(channel_id), )
NEW_FIELD(std::string, topic, USEDBY(payload))
NEW_FIELD(int, privacy_level, USEDBY(payload))
AUTO_PAYLOAD(PFO(topic) PFO(privacy_level))
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/stage-instance#delete-stage-instance
//  TODO unverified
#define Parent Call
#define Class DeleteStageInstanceLogCall
#define function deleteStageInstance
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(Snowflake, channel_id, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/stage-instances/{}", ARR(channel_id), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
