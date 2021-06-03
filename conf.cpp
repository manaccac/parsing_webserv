#include "conf.hpp"

conf::conf()
{
	_GET = false;
	_POST = false;
	_DELETE = false;
}

conf::conf(conf const & s_conf)
{
	_GET = s_conf._GET;
	_POST = s_conf._POST;
	_DELETE = s_conf._DELETE;
}

conf    &conf::operator=(conf const & s_conf)
{
	_GET = s_conf._GET;
	_POST = s_conf._POST;
	_DELETE = s_conf._DELETE;
	return (*this);
}

conf::~conf()
{
}

//set

void conf::set_name(std::string s_name)
{
	size_t i;
	i = s_name.find("server_name") + 11;
	int j = 0;
	char server[100]; // malloc ?

	while ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i] && s_name[i] != '#')
		i++;
	while (s_name[i] != '\f' && s_name[i] != '\t' && s_name[i] != '\v' && s_name[i] != '\n' && s_name[i] != '\r' && s_name[i] != '#' && s_name[i] != ';' && s_name[i] != ' ' && s_name[i])
		server[j++] = s_name[i++];
	_server_name = server;
}

void conf::set_listen(std::string s_name)
{
	(void)s_name;
}

//IL FAUDRAIT UN TCHECK D'ERREUR EN MODE SI ON TE METT GETBLEU faut pas que ca marche
void conf::set_GET(std::string s_get)
{
	if (s_get.find(" GET") != ULONG_MAX)
		_GET = true;
	else
		std::cout << "ERREUR GET\n";
}

void conf::set_POST(std::string s_set)
{
	if (s_set.find(" POST") != ULONG_MAX)
		_POST = true;
	else
		std::cout << "ERREUR POST\n";
}

void conf::set_DELETE(std::string s_set)
{
	if (s_set.find(" DELETE") != ULONG_MAX)
		_DELETE = true;
	else
		std::cout << "ERREUR DELETE\n";
}
