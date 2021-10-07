#include "CmdPass.hpp"

using namespace std;

CmdPass::CmdPass()
{
	_cmdName = "PASS";
	_syntax = "PASS <password>";
	_cmdDescription = "PASS <password>. Sets the connection password. This command must be used before registering a username.";
}

CmdPass::~CmdPass()
{}

void CmdPass::cmdRun()
{
	if (_client->getEnterPassword())
		throw "462 * :Unauthorized command (already registered)\r\n";
	if (_args.size() < 2)
		throw "461 * PASS: Not enough parameters\r\n";
	if (!_server->checkClientPass(_args[1]))
		throw CmdPass::IncorrectPasswordException();
	else
	{
		_client->setEnterPassword(true);
		string nick = _client->getNick();
		_client->sendMessageToClient(":" + nick + " PASS Correct password\r\n");
		_client->registered();
	}
}

const char *CmdPass::IncorrectPasswordException::what() const throw()
{
	return "464 * :Password incorrect\r\n";
}