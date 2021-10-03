#include "CmdPass.hpp"

using namespace std;

CmdPass::CmdPass()
{
	_cmdName = "PASS";
	_cmdDescription = "PASS <password>. Sets the connection password. This command must be used before registering a username.";
}

CmdPass::~CmdPass()
{}

void CmdPass::cmdRun()
{
	if (_args.size() == 1)
		throw CmdPass::NeedMoreParamsException();
	if (!_server->checkClientPass(_args[1]))
		throw CmdPass::IncorrectPasswordException();
	else
	{
		_client->setEnterPassword(1);
		_client->sendMessageToClient("Correct password!\n");
	}
}

// const char* CmdPass::NeedMoreParamsException::what() const throw()
// {
// 	return "Need more params. PASS <password>\n";
// }

const char *CmdPass::IncorrectPasswordException::what() const throw()
{
	return "Incorrect password!\n";
}