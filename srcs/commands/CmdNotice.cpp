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
        throw CmdNotice::NeedMoreParamsNotice();
    else
    {
        Client *toClient = _server->getClient(_args[1]);
        if (!toClient)
            throw CmdNotice::UserDoesNotExist();
        std::string msgToClient = _args[2] + "\n";
        toClient->sendMessageToClient(msgToClient);
    }
}

const char* CmdNotice::UserDoesNotExist::what() const throw()
{
    return "The user does not exist!\n";
}

const char* CmdNotice::NeedMoreParamsNotice::what() const throw()
{
    return "Need more params <nickname> <message>\n";
}