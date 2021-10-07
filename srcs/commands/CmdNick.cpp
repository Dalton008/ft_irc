#include "CmdNick.hpp"

using namespace std;

CmdNick::CmdNick()
{
    _cmdName = "NICK";
    _syntax = "Syntax: NICK <nickname>";
    _cmdDescription = "Allows the user to change his nickname in IRC.";
}

CmdNick::~CmdNick()
{}

void CmdNick::cmdRun()
{
    if (_args.size() < 1)
        throw "461 * NICK: Not enough parameters\r\n";
    else if (_server->checkExistClient(_args[1]))
        throw "433 * " + _args[1] + ":Nickname is already in use\r\n";
    else
    {
        _client->setNick(_args[1]);
        _client->sendMessageToClient(
            ":" + _client->getNick() + " " + "NICK " + _client->getNick() + "\r\n"
        );
        _client->registered();
    }
}