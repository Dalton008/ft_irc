#pragma once

// class Command;
// class Client;

// #include <vector>
// #include <string>
// #include <iostream>
#include <sstream>
#include "Command.hpp"
#include "Client.hpp"

#include "../srcs/commands/CmdHelp.hpp"
#include "../srcs/commands/CmdPass.hpp"


class Commander
{
	private:
		std::vector<Command*>	commands;
		// Client					*_client;

	public:
		Commander();
		~Commander();

		void parse(/*Client *client,*/ std::string msg);
		std::vector<std::string> splitMsg(std::string msg);
		void addCommands();
};
