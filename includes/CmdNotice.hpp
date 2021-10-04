#ifndef CMDNOTICE_HPP
#define CMDNOTICE_HPP

#include "Command.hpp"

class CmdNotice : public Command
{
    public:
        CmdNotice();
        ~CmdNotice();
        void cmdRun();
        class  UserDoesNotExist : public std::exception
		{
			const char* what() const throw();	
		};
};

#endif