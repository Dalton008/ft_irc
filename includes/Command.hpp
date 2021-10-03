#pragma once

#include <string>
// class Command;

// #include "Client.hpp"

// class Client;

class Command
{
	protected:
		std::string		_cmdName;
		std::string		_cmdDescription;
		// Client			*_client;
	
	public:
		Command();
		virtual ~Command();


		std::string getName() {return _cmdName;}
		std::string getDescription() {return _cmdDescription;}
		// void		setClient(Client *client);
		virtual void cmdRun() = 0;
};
