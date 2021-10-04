#include "CmdUser.hpp"

using namespace std;

CmdUser::CmdUser()
{
    _cmdName = "USER";
    _syntax = "USER <nickname> <flags> <unused> <realname>";
    _cmdDescription = "Sets the user name, host, real name, and connection flag.";
}

CmdUser::~CmdUser()
{}

void CmdUser::cmdRun()
{
    if (!_client->getEnterPassword())
        throw CmdUser::NoPasswordEntered();
    else if (_args.size() < 5)
        throw CmdUser::InvalidNumOfArgs();
    else
    {
        _client->setNick(_args[1]);
        _client->setRealname(_args[4]);
        _client->setRegistered(1);
        string msgToClient = "User " + _client->getNick() + " is registered.\n";
        _client->sendMessageToClient(msgToClient);
    }
}