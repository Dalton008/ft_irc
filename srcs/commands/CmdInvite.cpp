#include "CmdInvite.hpp"

CmdInvite::CmdInvite()
{
    _cmdName = "INVITE";
    _syntax = "INVITE <nickname> <channel>";
    _cmdDescription = "Invites the user to the channel";
}

CmdInvite::~CmdInvite()
{}

void CmdInvite::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdInvite::ERR_RESTRICTED();
    else if (_args.size() != 3)
        throw "461 * JOIN: Not enough parameters\r\n";
    else if (!_client->getIsOperator())
        throw "482 * #" + _args[2] + ":You're not channel operator\r\n";
    else
    {
        Client *toClient = _server->getClient(_args[1]);
        if (!toClient)
            throw CmdInvite::NickOrChannelNameError();
        // Channel *toChannel = _server->getChannel(_args[2]);
        // if (!toChannel)
        //     throw CmdInvite::ChannelDoesNotExist();
        toClient->sendMessageToClient(
            ":" + _client->getNick() +
            " INVITE " + _args[1] +
            " " + _args[2] + "\r\n"
        );
    }
}