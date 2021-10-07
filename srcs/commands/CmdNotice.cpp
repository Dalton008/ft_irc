#include "CmdNotice.hpp"

CmdNotice::CmdNotice()
{
    _cmdName = "NOTICE";
    _syntax = "NOTICE <receiver> <message>";
    _cmdDescription = "Sends a message.";
}

CmdNotice::~CmdNotice()
{}

void CmdNotice::cmdRun()
{
    if (!_client->getRegistered())
        throw CmdNotice::ERR_RESTRICTED();
    else
    {
        std::string msg = createMsg();
        if (_args[1][0] == '#' || _args[1][0] == '&')
        {
            Client *toClient = _server->getClient(_args[1]);
            Channel *toChannel = _server->getChannel(_args[1]);
            if (!toChannel)
                throw CmdNotice::ChannelDoesNotExist();
            std::string toClientStr = toClient->getNick();
            toChannel->sendMessageToChannel(":" + toClientStr + " NOTICE #" + toChannel->getChannelName() + msg + "\r\n");
        }
        else
        {
            Client *toClient = _server->getClient(_args[1]);
            if (!toClient)
                throw CmdNotice::NickOrChannelNameError();
            std::string toClientStr = toClient->getNick(); 
            toClient->sendMessageToClient(":" + toClientStr + " NOTICE " + toClientStr + msg + "\r\n");
        }
    }
}

std::string CmdNotice::createMsg()
{
    std::string msg = _client->getNick() + ": ";
    for (size_t i = 2; i < _args.size(); i++)
    {
        msg = msg + _args[i];
        if (i + 1 != _args.size())
            msg += " ";
    }
    return msg;
}