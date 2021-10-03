#pragma once

#include "../../includes/Command.hpp"

#include <vector>
#include <iostream>

class Command;

class CmdHelp : public Command
{
	private:
		std::vector<Command*> &cmds;
	
	public:
		CmdHelp(std::vector<Command*> &cmds);
		~CmdHelp();
		void cmdRun();
};
