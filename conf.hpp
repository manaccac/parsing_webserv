#ifndef CONF_HPP
#define CONF_HPP

#include <iostream>
#include "webserv.hpp"
#include <map>
#include <vector>

class conf
{
public:
	conf();
	~conf();

	//classe server
	//mettre le resulta en int si -1 return erreur sinon good
	int set_name(std::string s_name);
	std::string get_name(){return (_server_name);};

	int set_listen(std::string s_listen);// good
	std::string get_listen(){return (_listen);};

	int set_root(std::string s_root);
	std::string get_root(){return (_root);};

	int set_index(std::string s_index);
	std::string get_index(){return (_index);};

	int set_GET(std::string s_get);
	bool get_GET(){return (_GET);};

	int set_POST(std::string s_post);
	bool get_POST(){return (_POST);};

	int set_DELETE(std::string s_delete);
	bool get_DELETE(){return (_DELETE);};

	std::map<std::string, std::vector<std::string> > _MAP_server;

private:
//	unsigned int nb_server;
//	unsigned int nb_location;

	std::string _server_name;
	std::string _listen;
	std::string _root;
	std::string _index;
//
	bool _GET;
	bool _POST;
	bool _DELETE;

	//location surment une classe location

	conf(conf const & s_conf);
	conf &operator=(conf const & s_conf);

};

#endif