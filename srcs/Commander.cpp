#include "../includes/Commander.hpp"

using namespace std;

Commander::Commander()
{
	commands.push_back(new CmdHelp(commands));
	commands.push_back(new CmdPass());
}

void Commander::parse(Client *client, string msg)
{
	// cout << msg << endl; //del
	vector<string> arg = splitMsg(msg);
	_client = client;
	// for (vector<string>::const_iterator i = arg.begin(); i != arg.end(); ++i)
	// {
	// 	cout << *i << " ";
	// }
	if (!arg.empty())
	{
		for (vector<Command*>::const_iterator i = commands.begin(); i != commands.end(); ++i)
		{
			cout <<  "'" + (*i)->getName() + "'" << " " << "'" + arg[0] + "'" << endl;
			if (arg[0] == (*i)->getName())
			{
				(*i)->setClient(client);
				(*i)->cmdRun();
			}
		}
	}
}

vector<string> Commander::splitMsg(string msg)
{
	vector <string> elems;
	stringstream ss(msg);
	string item;
	while (getline(ss, item, ' '))
	{
		item.erase(std::remove(item.begin(), item.end(), '\n'), item.end());
		elems.push_back(item);
	}
	return elems;
}

void Commander::addCommands()
{
	// commands.push_back(new CmdHelp(this->commands));
}