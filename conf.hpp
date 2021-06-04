#ifndef CONF_HPP
#define CONF_HPP

#include <iostream>
#include "webserv.hpp"

class conf
{
public:
	conf();
	conf(conf const & s_conf);
	conf &operator=(conf const & s_conf);
	~conf();

	//classe server
	//mettre le resulta en int si -1 return erreur sinon good
	void set_name(std::string s_name);
	std::string get_name(){return (_server_name);};

	int set_listen(std::string s_listen);// good
	std::string get_listen(){return (_listen);};

	void set_root(std::string s_root);
	std::string get_root(){return (_root);};

	void set_index(std::string s_index);
	std::string get_index(){return (_index);};

	void set_GET(std::string s_get);
	bool get_GET(){return (_GET);};

	void set_POST(std::string s_post);
	bool get_POST(){return (_POST);};

	void set_DELETE(std::string s_delete);
	bool get_DELETE(){return (_DELETE);};


private:
	unsigned int nb_server;
	unsigned int nb_location;


	// surment tous ca dans une classe serveur
	std::string _server_name;
	std::string _listen;
	std::string _root;
	std::string _index;
	//method GET HEAD POST PUT DELETE CONNECT OPTIONS TRACE
	bool _GET;
	bool _POST;
	bool _DELETE;

	//location surment une classe location


};

#endif