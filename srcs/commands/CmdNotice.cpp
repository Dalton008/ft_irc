#include "CmdNotice.hpp"

CmdNotice::CmdNotice()
{
    _cmdName = "NOTICE";
    _syntax = "NOTICE <nickname> <message>";
    _cmdDescription = "Sends a message";
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
        throw CmdNotice::NeedMoreParamsException();
    else
    {
        Client *toClient = _server->getClient(_args[1]);
        if (!toClient)
            throw CmdNotice::UserDoesNotExist();
        toClient->sendMessageToClient(_args[2]);
    }
}

const char* CmdNotice::UserDoesNotExist::what() const throw()
{
    return "The user does not exist!\n";
}