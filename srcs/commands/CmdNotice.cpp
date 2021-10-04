#include "CmdNotice.hpp"

CmdNotice::CmdNotice()
{
    _cmdName = "NOTICE";
    _syntax = "NOTICE <nickname> <message>";
    _cmdDescription = "Sends a message.";
}

CmdNotice::~CmdNotice()
{}

void CmdNotice::cmdRun()
{
    if (!_client->getEnterPassword())
        throw CmdNotice::NoPasswordEntered();
    else if (!_client->getRegistered())
        throw CmdNotice::NoRegistered();
    else if (_args.size() < 3)
        throw CmdNotice::InvalidNumOfArgs();
    else
    {
        Client *toClient = _server->getClient(_args[1]);
        if (!toClient)
            throw CmdNotice::UserDoesNotExist();
        std::string msgToClient = _client->getNick() + ": ";
        for (size_t i = 2; i < _args.size(); i++)
        {
            msgToClient = msgToClient + _args[i];
            if (i + 1 != _args.size())
                msgToClient += " ";
        }
        msgToClient += "\n";
        _client->sendMessageToClient("Message sending.\n");
        toClient->sendMessageToClient(msgToClient);
        
    }
}

const char* CmdNotice::UserDoesNotExist::what() const throw()
{
    return "The user does not exist!\n";
}
