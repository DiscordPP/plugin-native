//
// Created by Aidan on 8/27/2021.
//


#ifndef OBJECT_BREAKOUTS
#error This header should only be included in plugin-native.hh
#endif

using GatewayPayload = json;
using Identify = json;
using IdentifyConnectionProperties = json;
using Resume = json;
using GuildRequestMembers = json;
using GatewayVoiceStateUpdate = json;
using GatewayPresenceUpdate = json;
using Hello = json;
class Ready/*Event*/;
using ChannelCreate/*Event*/ = Channel;
using ChannelUpdate/*Event*/ = Channel;
using ChannelDelete/*Event*/ = Channel;
using ThreadCreate/*Event*/ = Channel;
using ThreadUpdate/*Event*/ = Channel;
using ThreadDelete/*Event*/ = Channel;
using ThreadListSync/*Event*/ = json;
using ThreadMemberUpdate/*Event*/ = ThreadMember;
using ThreadMembersUpdate/*Event*/ = json;
using ChannelPinsUpdate/*Event*/ = json;
using GuildCreate/*Event*/ = Guild;
using GuildUpdate/*Event*/ = Guild;
using GuildDelete/*Event*/ = UnavailableGuild;
using GuildBanAdd/*Event*/ = json;
using GuildBanRemove/*Event*/ = json;
using GuildEmojisUpdate/*Event*/ = json;
using GuildStickersUpdate/*Event*/ = json;
using GuildIntegrationsUpdate/*Event*/ = json;
using GuildMemberAdd/*Event*/ = json;
using GuildMemberRemove/*Event*/ = json;
using GuildMemberUpdate/*Event*/ = json;
using GuildMembersChunk/*Event*/ = json;
using GuildRoleCreate/*Event*/ = json;
using GuildRoleUpdate/*Event*/ = json;
using GuildRoleDelete/*Event*/ = json;
using IntegrationCreate/*Event*/ = json;
using IntegrationUpdate/*Event*/ = json;
using IntegrationDelete/*Event*/ = json;
using InviteCreate/*Event*/ = json;
using InviteDelete/*Event*/ = json;
using MessageCreate/*Event*/ = Message;
using MessageUpdate/*Event*/ = Message;
using MessageDelete/*Event*/ = json;
using MessageDeleteBulk/*Event*/ = json;
using MessageReactionAdd/*Event*/ = json;
using MessageReactionRemove/*Event*/ = json;
using MessageReactionRemoveAll/*Event*/ = json;
using MessageReactionRemoveEmoji/*Event*/ = json;
using PresenceUpdate/*Event*/ = json;
using ClientStatus = json;
using Activity = json;
using ActivityTimestamps = json;
using ActivityEmoji = json;
using ActivityParty = json;
using ActivityAssets = json;
using ActivitySecrets = json;
using ActivityButtons = json;
using TypingStart/*Event*/ = json;
using UserUpdate/*Event*/ = User;
using VoiceStateUpdate/*Event*/ = VoiceState;
using VoiceServerUpdate/*Event*/ = json;
using WebhookUpdate/*Event*/ = json;
using InteractionCreate/*Event*/ = Interaction;
using StageInstanceCreate/*Event*/ = StageInstance;
using StageInstanceUpdate/*Event*/ = StageInstance;
using StageInstanceDelete/*Event*/ = StageInstance;
using GetGatewayBotResponse = json;
using SessionStartLimit = json;
