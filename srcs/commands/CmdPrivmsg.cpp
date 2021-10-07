#include "CmdPrivmsg.hpp"
#include "Define.hpp"

CmdPrivmsg::CmdPrivmsg()
{
    _cmdName = "PRIVMSG";
    _syntax = "PRIVMSG <receiver> <message>";
    _cmdDescription = "Sends a message.";
}

CmdPrivmsg::~CmdPrivmsg()
{}

void CmdPrivmsg::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdPrivmsg::ERR_RESTRICTED();
    else if (_args.size() < 3)
        throw "461 * PROVMSG: Not enough parameters\r\n";
    else
    {
        std::string msg = createMsg();
        Channel *toChannel = _server->getChannel(_args[1]);
        if (toChannel != nullptr)
        {
            toChannel->sendMessageToChannel(":" + _client->getNick() + " PRIVMSG " + toChannel->getChannelName() + " : " + msg);
        }
        else
        {
            Client *toClient = _server->getClient(_args[1]);
            if (!toClient)
                throw ERR_NOSUCHNICK(_args[1]);
            std::string toClientStr = toClient->getNick();
            toClient->sendMessageToClient(":" + _client->getNick() + " PRIVMSG " + toClientStr + ": " + msg + "\r\n");
            if (toClient->getAwayMessage().size() != 0)
            {
                _client->sendMessageToClient(":" + toClient->getNick() + " PRIVMSG " + _client->getNick() + ": " + toClient->getAwayMessage() + "\r\n");
            }
        }
    }
}

std::string CmdPrivmsg::createMsg()
{
    std::string msg;
    for (size_t i = 2; i < _args.size(); i++)
    {
        msg = msg + _args[i];
        if (i + 1 != _args.size())
            msg += " ";
    }
    msg += "\n";
    return msg;
}