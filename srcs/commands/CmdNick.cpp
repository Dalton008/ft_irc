#include "CmdNick.hpp"

using namespace std;

CmdNick::CmdNick()
{
    _cmdName = "NICK";
    _cmdDescription = "Allows the user to change his nickname in IRC.";
}

CmdNick::~CmdNick()
{}

void CmdNick::cmdRun()
{
    if (_args.size() == 1)
        throw CmdNick::NeedMoreParamsException();
    else if (!_client->getEnterPassword())
        throw CmdNick::NoPasswordEntered();
    else
    {
        _client->setNick(_args[1]);
    }
}