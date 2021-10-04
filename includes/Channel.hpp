#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"

class Channel
{
    private:
        std::vector<Client*> _clients;
        std::string			_channelName;
	
	public:
		Channel(std::string name);
		~Channel();
		std::string	getChannelName() {return _channelName;}
		bool		checkExistClient(std::string clientName);
		void		setClient(Client *client);
		void		sendMessageToChannel(std::string message);
		void		removeClient(std::string clientName);
};

#endif