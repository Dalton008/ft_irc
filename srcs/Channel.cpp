#include "Channel.hpp"

Channel::Channel(std::string name)
{
    _channelName = name;
}

Channel::~Channel()
{}

void    Channel::setClient(Client *client)
{
    _clients.push_back(client);
}

void    Channel::sendMessageToChannel(std::string message)
{
    for (std::vector<Client*>::const_iterator i = _clients.begin(); i != _clients.end(); ++i)
    {
        (*i)->sendMessageToClient(message);
    }
}