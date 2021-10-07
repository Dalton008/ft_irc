#include "CmdList.hpp"

CmdList::CmdList()
{
    _cmdName = "LIST";
    _syntax = "LIST";
    _cmdDescription = "shows a list of available channels on the server";
}

CmdList::~CmdList()
{}

void CmdList::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdList::ERR_RESTRICTED();
    else
    {
        std::vector<Channel*> channel = _server->getAllChannels();
        for (std::vector<Channel*>::const_iterator i = channel.begin(); i != channel.end(); i++)
        {
            _client->sendMessageToClient("322 * #" + (*i)->getChannelName() + " " + std::to_string((*i)->getClients().size()) + "\r\n");
        }
        _client->sendMessageToClient("323 * :End of LIST\r\n");
    }
}