#ifndef CONF_HPP
#define CONF_HPP

#include <iostream>

class conf
{
public:
	conf();
	conf(conf const & s_conf);
	conf &operator=(conf const & s_conf);
	~conf();
private:
	unsigned int nb_server;
	unsigned int nb_location;


	// surment tous ca dans une classe serveur
	std::string _server_name;
	std::string _listen;
	std::string _root;
	std::string _index;
	std::string _allow_methods;

	//location surment une classe location


};

#endif