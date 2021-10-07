#include "CmdWho.hpp"

CmdWho::CmdWho()
{
    _cmdName = "WHO";
    _syntax = "WHO <#channel>";
    _cmdDescription = "List users on channel";
}

CmdWho::~CmdWho()
{}

void CmdWho::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdWho::ERR_RESTRICTED();
    else if (_args.size() < 2)
        throw "461 * WHO: Not enough parameters\r\n";
    else
    {
        Channel *toChannel = _server->getChannel(_args[1]);
        if (!toChannel)
            throw "403 * " + _args[1] + ":No such channel\r\n";
        std::vector<Client*> clients = toChannel->getClients();
        _client->sendMessageToClient("Channel " + toChannel->getChannelName() + " has " + std::to_string(clients.size()) + " users\r\n");
        for (std::vector<Client*>::const_iterator i = clients.begin(); i != clients.end(); i++)
        {
            if ((*i)->getIsOperator())
                _client->sendMessageToClient("@" + (*i)->getNick() + "\r\n");
        }
    }
}