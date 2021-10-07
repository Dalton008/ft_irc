#include "CmdJoin.hpp"

#include <stdexcept>

CmdJoin::CmdJoin()
{
    _cmdName = "JOIN";
    _syntax = "JOIN <#channelname>";
    _cmdDescription = "Enters the channel. If there is no such channel, it creates one.";
}

CmdJoin::~CmdJoin()
{}

void CmdJoin::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdJoin::ERR_RESTRICTED();
    else if (_args.size() < 1)
        throw "461 * JOIN: Not enough parameters\r\n";
    else
    {
        if (!checkNameChannel(_args[1]))
            throw "476 * " + _args[1] + ":Bad Channel Mask\r\n";
        Channel *channel = _server->getChannel(_args[1]);
        if (!channel)
        {
            _args[1].erase(_args[1].begin());
            _server->createChannel(_args[1]);
            channel = _server->getChannel(_args[1]);
            _client->setIsOperator(true);
        }
        if (channel->getClient(_client->getNick()))
            throw "405 * #" + channel->getChannelName() + ":You have joined too many channels\r\n";
        channel->setClient(_client);
        channel->sendMessageToChannel(
            ":" + _client->getNick() + " JOIN #" + 
            channel->getChannelName() + "\r\n"
        );
    }
}

bool CmdJoin::checkNameChannel(std::string name)
{
    if (name[0] != '#' && name[0] != '&')
        return false;
    return true;
}


