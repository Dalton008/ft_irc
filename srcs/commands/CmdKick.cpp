#include "CmdKick.hpp"

CmdKick::CmdKick()
{
    _cmdName = "KICK";
    _syntax = "KICK <channel> <nickname>";
    _cmdDescription = "Kick client";
}

CmdKick::~CmdKick()
{}

void CmdKick::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdKick::ERR_RESTRICTED();
    else if (_args.size() <  2)
        throw "461 * KICK: Not enough parameters\r\n";
    else
    {
        Channel *toChannel = _server->getChannel(_args[1]);
        if (!toChannel)
            throw "403 * #" + _args[1] + ":No such channel\r\n";
        if (!_client->getIsOperator())
            throw "482 * #" + _args[1] + ":You're not channel operator\r\n";
        if (toChannel->getClient(_client->getNick()))
            throw "442 * " + _args[1] + ":You're not on that channel\r\n";
        
        Client *toClient = _server->getClient(_args[2]);
        if (!toClient)
            throw "441 * " + _args[2] + " #" + _args[1] + ":They aren't on that channel\r\n";
        toChannel->sendMessageToChannel(
            ":" + toClient->getNick() + " " + "KICK #" + toChannel->getChannelName() + " : kicked " + toClient->getNick() + "\r\n"
        );
        toChannel->removeClient(toClient->getNick());
    }
}