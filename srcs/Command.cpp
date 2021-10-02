#include "../includes/Command.hpp"

using namespace std;

Command::Command() {}

Command::~Command() {}

void Command::setClient(Client *client)
{
	this->_client = client;
}