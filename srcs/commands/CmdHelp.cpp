#include "CmdHelp.hpp"

using namespace std;

CmdHelp::CmdHelp(vector<Command*> &cmds) : cmds(cmds)
{
	_cmdName = "HELP";
	_cmdDescription = "Output a list of available commands";
}

CmdHelp::~CmdHelp() {}

void CmdHelp::cmdRun()
{
	string message;
	for (vector<Command*>::const_iterator i = cmds.begin(); i != cmds.end(); ++i)
	{
		message = "Name cmd: " + (*i)->getName() + ", decription cmd: " + (*i)->getDescription() + "\n";
		cout << message;
		// this->_client->sendMessageToClient(message);
		// cout << "Name cmd: " << (*i)->getName() << ", decription cmd: " << (*i)->getDescription() << endl;
	}
}
