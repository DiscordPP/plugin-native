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

// https://discord.com/developers/docs/resources/invite#get-invite
// TODO unverified
#define Parent Call
#define Class GetInviteCall
#define function getInvite
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, invite_code, USEDBY(target))
NEW_FIELD(bool, with_counts, USEDBY(target))
NEW_FIELD(bool, with_expiration, USEDBY(target))
STATIC_FIELD(std::string, method, "GET")
AUTO_TARGET("/invites/{}", ARR(invite_code),
            QSO(with_counts) QSO(with_expiration))
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>

// https://discord.com/developers/docs/resources/invite#delete-invite
// TODO unverified
#define Parent Call
#define Class DeleteInviteCall
#define function deleteInvite
#include <discordpp/macros/defineCallOpen.hh>
NEW_FIELD(std::string, invite_code, USEDBY(target))
STATIC_FIELD(std::string, method, "DELETE")
AUTO_TARGET("/invites/{}", ARR(invite_code), )
HIDE_FIELD(type)
HIDE_FIELD(body)
FORWARD_FIELD(handleWrite, onWrite, )
FORWARD_FIELD(handleRead, onRead, )
#include <discordpp/macros/defineCallClose.hh>
