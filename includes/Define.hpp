#ifndef DEFINE_HPP
#define DEFINE_HPP

#define ERR_NOSUCHNICK(nickname)				"401 * " + nickname + ":No such nick/channel";
#define ERR_NOSUCHSERVER(servername)			"402 * " + servername + ":No such server";
#define ERR_NOSUCHCHANNEL(channelname)			"403 * #" + channelname + ":No such channel";
#define ERR_CANNOTSENDTOCHAN(channelname)		"404 * #" + channelname + ":Cannot send to channel";
#define ERR_TOOMANYCHANNELS(channelname)		"405 * #" + channelname + ":You have joined too many channels";
#define ERR_WASNOSUCHNICK(nickname)				"406 * " + nickname + ":There was no such nickname";
#define ERR_TOOMANYTARGETS(target)				"407 * " + target + ":Duplicate recipients. No message delivered";
#define ERR_NOORIGIN							"409 * :No origin specified";
#define ERR_NORECIPIENT(command)				"411 * :No recipient given " + command;
#define ERR_NOTEXTTOSEND						"412 * :No text to send";
#define ERR_NOTOPLEVEL(mask)					"413 * " + mask + " :No toplevel domain specified";
#define ERR_WILDTOPLEVEL(mask)					"414 * " + mask + " :Wildcard in toplevel domain";
#define ERR_UNKNOWNCOMMAND(command)				"421 * " + command + " :Unknown command";
#define ERR_NOMOTD								"422 * :MOTD File is missing";
#define ERR_NOADMININFO(server)					"423 * " + server + " :No administrative info available";
#define ERR_FILEERROR(fileop, file)				"424 * :File error doing " + fileop + " on " + file;
#define	ERR_NONICKNAMEGIVEN						"431 * :No nickname given";
#define ERR_ERRONEUSNICKNAME(nickname)			"432 * " + nickname + " :Erroneus nickname";
#define	ERR_NICKNAMEINUSE(nickname)				"433 * " + nickname + " :Nickname is already in use";
#define ERR_NICKCOLLISION(nickname)				"436 * " + nickname + " :Nickname collision KILL";
#define ERR_USERNOTINCHANNEL(nickname, channel)	"441 * " + nickname + " #" + channel + " :They aren't on that channel";
#define ERR_NOTONCHANNEL(channel)				"442 * #" + channel + " :You're not on that channel";
#define ERR_USERONCHANNEL(nickname, channel)	"443 * " + nickname + " #" + channel + " :is already on channel";
#define ERR_NOLOGIN(nickname)					"444 * " + nickname + " :User not logged in";
#define ERR_SUMMONDISABLED						"445 * :SUMMON has been disabled";
#define ERR_USERSDISABLED						"446 * :USERS has been disabled";
#define ERR_NOTREGISTERED						"451 * :You have not registered";
#define ERR_NEEDMOREPARAMS(command)				"461 * " + command + " :Not enough parameters";
#define ERR_ALREADYREGISTRED					"462 * :You may not reregister";
#define ERR_NOPERMFORHOST						"463 * :Your host isn't among the privileged";
#define ERR_PASSWDMISMATCH						"464 * :Password incorrect";
#define ERR_YOUREBANNEDCREEP					"465 * :You are banned from this server";
#define ERR_KEYSET(channel)						"467 * #" + channel + " :Channel key already set";
#define ERR_CHANNELISFULL(channel)				"471 * #" + channel + " :Cannot join channel (+l)";
#define ERR_UNKNOWNMODE(char)					"472 * " + char + " :is unknown mode char to me";
#define ERR_INVITEONLYCHAN(channel)				"473 * #" + channel + " :Cannot join channel (+i)";
#define ERR_BANNEDFROMCHAN(channel)				"474 * #" + channel + " :Cannot join channel (+b)";
#define ERR_BADCHANNELKEY(channel)				"475 * #" + channel + " :Cannot join channel (+k)";
#define ERR_NOPRIVILEGES						"481 * :Permission Denied- You're not an IRC operator";
#define ERR_CHANOPRIVSNEEDED(channel)			"482 * #" + channel + " :You're not channel operator";
#define ERR_CANTKILLSERVER						"483 * :You cant kill a server!";
#define ERR_NOOPERHOST							"491 * :No O-lines for your host";
#define ERR_UMODEUNKNOWNFLAG					"501 * :Unknown MODE flag";
#define ERR_USERSDONTMATCH						"502 * :Cant change mode for other users";

#endif