#include "CmdJoin.hpp"

CmdJoin::CmdJoin()
{
    _cmdName = "JOIN";
    _syntax = "JOIN <channelname>";
    _cmdDescription = "Enters the channel. If there is no such channel, it creates one.";
}

CmdJoin::~CmdJoin()
{}

void CmdJoin::cmdRun()
{
    if (!_client->getEnterPassword())
        throw CmdJoin::NoPasswordEntered();
    else if (!_client->getRegistered())
        throw CmdJoin::NoRegistered();
    else if (_args.size() != 2)
        throw CmdJoin::InvalidNumOfArgs();
    else
    {
        if (!_server->checkExistChannel(_args[1]))
            _server->createChannel(_args[1]);
        Channel *channel = _server->getChannel(_args[1]);
        channel->setClient(_client);
        channel->sendMessageToChannel(
            "User " + _client->getNick() +
            " join to " +
            channel->getChannelName() + "\n"
        );
    }
}