#pragma once

#include "includes/Command.hpp"

class CmdPass : public Command
{
	public:
		CmdPass();
		~CmdPass();
		void cmdRun();
};