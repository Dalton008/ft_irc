#include "CmdJoin.hpp"

CmdJoin::CmdJoin()
{
    _cmdName = "JOIN";
    _syntax = "JOIN <channelname>";
    _cmdDescription = "Enters the channel. If there is no such channel, it creates one.";
}

CmdJoin::~CmdJoin()
{}

void CmdJoin::cmdRun()
{
    // if (!_client->getEnterPassword())
    //     throw CmdJoin::NoPasswordEntered();
    // else if (!_client->getRegistered())
    //     throw CmdJoin::NoRegistered();
    // else if (_args.size() != 2)
    //     throw CmdJoin::NeedMoreParamsNotice();
    // else
    // {

    // }
}