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
    
}