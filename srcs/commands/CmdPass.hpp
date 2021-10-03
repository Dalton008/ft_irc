#pragma once

#include "../../includes/Command.hpp"

class Command;

class CmdPass : public Command
{
	public:
		CmdPass();
		~CmdPass();
		void cmdRun();
};