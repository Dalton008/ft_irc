#include "CmdPrivmsg.hpp"

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
    // else if (_args.size() < 3)
    //     throw CmdPrivmsg::InvalidNumOfArgs();
    else
    {
        std::string msg = createMsg();
        if (_args[1][0] == '#' || _args[1][0] == '&')
        {
            Channel *toChannel = _server->getChannel(_args[1]);
            if (!toChannel)
                throw CmdPrivmsg::ChannelDoesNotExist();
            toChannel->sendMessageToChannel(":" + _client->getNick() + " PRIVMSG " + toChannel->getChannelName() + " : " + msg);
        }
        else
        {
            Client *toClient = _server->getClient(_args[1]);
            if (!toClient)
                throw CmdPrivmsg::UserDoesNotExist();
            std::string toClientStr = toClient->getNick();
            toClient->sendMessageToClient(":" + toClientStr + " PRIVMSG " + toClientStr +  msg);
        }
    }
}
//: PRIVSMG #<channelname> : <message> 
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