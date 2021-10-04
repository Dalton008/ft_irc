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
		std::string	getChannleName() {return _channelName;}

};

#endif