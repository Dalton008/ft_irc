#pragma once

#include "includes/Command.hpp"

#include <vector>

class CmdHelp : public Command
{
	private:
		std::vector<Command*> &cmds;
	
	public:
		CmdHelp(std::vector<Command*> &cmds);
		~CmdHelp();
		void cmdRun();
};
