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
	
}
