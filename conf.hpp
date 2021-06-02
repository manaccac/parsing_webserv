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
	void set_name(std::string s_name);
	std::string get_name(){return (_server_name);};

	void set_listen(std::string s_listen);
	std::string get_listen(){return (_listen);};

	void set_root(std::string s_root);
	std::string get_root(){return (_root);};

	void set_index(std::string s_index);
	std::string get_index(){return (_index);};

	void set_GET(std::string s_get);
	bool get_GET(){return (_GET);};

	void set_HEAD(std::string s_head);
	bool get_HEAD(){return (_HEAD);};

	void set_POST(std::string s_post);
	bool get_POST(){return (_POST);};

	void set_PUT(std::string s_put);
	bool get_PUT(){return (_PUT);};

	void set_DELETE(std::string s_delete);
	bool get_DELETE(){return (_DELETE);};

	void set_CONNECT(std::string s_connect);
	bool get_CONNECT(){return (_CONNECT);};

	void set_OPTIONS(std::string s_options);
	bool get_OPTIONS(){return (_OPTIONS);};

	void set_TRACE(std::string s_trace);
	bool get_TRACE(){return (_TRACE);};


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
	bool _HEAD;
	bool _POST;
	bool _PUT;
	bool _DELETE;
	bool _CONNECT;
	bool _OPTIONS;
	bool _TRACE;

	//location surment une classe location


};

#endif