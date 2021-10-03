#ifndef COMMANDER_HPP
#define COMMANDER_HPP

#include <sstream>
#include "Command.hpp"

class Command;
class Client;

class Commander
{
	private:
		std::vector<Command*>	commands;
		Client					*_client;

	public:
		Commander();
		~Commander();

		void parse(Client *client, std::string msg);
		std::vector<std::string> splitMsg(std::string msg);
		void addCommands();
};

#endif