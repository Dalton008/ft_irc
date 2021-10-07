#include "CmdPart.hpp"

CmdPart::CmdPart()
{
    _cmdName = "PART";
    _syntax = "PART <channelname>";
    _cmdDescription = "Removes the client from the channel";
}

CmdPart::~CmdPart()
{}

void CmdPart::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdPart::ERR_RESTRICTED();
    else if (_args.size() < 2)
        throw "461 * PART: Not enough parameters\r\n";
    else
    {
        Channel *channel = _server->getChannel(_args[1]);
        if (!channel)
            throw "403 * #" + _args[1] + ":No such channel\r\n";
        if (!channel->getClient(_client->getNick()))
            throw "442 * " + _args[1] + ":You're not on that channel\r\n";
        channel->removeClient(_client->getNick());
        channel->sendMessageToChannel(
            ":" + _client->getNick() +
            " " + "PART" + " #" +
            channel->getChannelName()
        );
    }
}

const char* CmdPart::NoSuchChannelException::what() const throw()
{
    return "No such channel!\n";
}