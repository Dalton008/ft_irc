#include "CmdQuit.hpp"

using namespace std;

CmdQuit::CmdQuit()
{
	_cmdName = "QUIT";
	_syntax = "QUIT [<quit message>]";
	_cmdDescription = "Disconnects the user from the server.";
}

CmdQuit::~CmdQuit()
{}

void CmdQuit::cmdRun()
{
	// int index = 0;
	// // _server->getAllChannels()
    // for (std::vector<Client*>::const_iterator i = _server->getAllClients().begin(); i != _server->getAllClients().end(); ++i)
    // {
    //     if ((*i)->getNick() == _client->getNick())
    //         break;
    //     index++;
    // }
    // _server->getAllClients().erase(_server->getAllClients().begin() + index);
	_server->deleteClient(_client->getId());
}
