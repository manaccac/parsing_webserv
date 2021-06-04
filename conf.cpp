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

int conf::set_listen(std::string s_name)
{
	int i;
	i = s_name.find("listen") + 6;
	char listen[100]; //malloc ?

	while ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i] && s_name[i] != '#')
		i++;
	// si le 4 eme cara et un point on va dans un truc special ip
	//si il y a un max de 4 chiffre et pas de point c un port
	if (s_name[i + 3] == '.') //test segfault
		std::cout << "slt\n";
	else
	{
		int port_max = 0;
		while (s_name[i] && port_max != 4)
		{
			if (s_name[i] >= '0' && s_name[i] <= '9')
				listen[port_max] = s_name[i];
			else
				return (-1);
			i++;
			port_max++;
		}
		if (port_max == 4 && (isprint(s_name[i]) == 1 || isspace(s_name[i] == 1)))
			return (-1);
		_listen = listen;
	}
	return (0);
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
