#include "CmdWho.hpp"

CmdWho::CmdWho()
{
    _cmdName = "WHO";
    _syntax = "WHO <#channel>";
    _cmdDescription = "List of users on the channel.";
}

CmdWho::~CmdWho()
{}

void CmdWho::cmdRun()
{
    if (!_client->getEnterPassword())
        throw CmdWho::NoPasswordEntered();
    else if (!_client->getRegistered())
        throw CmdWho::NoRegistered();
    else if (_args.size() != 2)
        throw CmdWho::InvalidNumOfArgs();
    else
    {
        Channel *channel = _server->getChannel(_args[1]);
        if (!channel)
            throw CmdWho::ChannelDoesNotExist();
        std::vector<Client*> clients = channel->getClients();
        for (std::vector<Client*>::const_iterator i = clients.begin(); i != clients.end(); ++i)
        {
            _client->sendMessageToClient((*i)->getNick() + " ");
        }
         _client->sendMessageToClient("\n");
    }
}