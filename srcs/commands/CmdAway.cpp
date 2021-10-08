#include "CmdAway.hpp"
#include "Define.hpp"

CmdAway::CmdAway()
{
    _cmdName = "AWAY";
    _syntax = "AWAY [<message>]";
    _cmdDescription = "Sets the autoresponder";
}

CmdAway::~CmdAway()
{}

void CmdAway::cmdRun()
{
    if (!_client->getRegistered())
        throw ERR_RESTRICTED;
    else
    {
        if (_args.size() > 2)
        {
            string awayMessage = createMsg();
            _client->setAwayMessage(_args[1]);
            _client->sendMessageToClient(RPL_NOWAWAY);
        }
        else
        {
            if (_client->getAwayMessage().size() != 0)
            {
                _client->setAwayMessage("");
                _client->sendMessageToClient(RPL_UNAWAY);
            }
        }
    }
}

