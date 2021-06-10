#include "conf.hpp"

conf::conf()
{
	_GET = false;
	_POST = false;
	_DELETE = false;
}

conf::~conf()
{
}

//set

int conf::set_name(std::string s_name)
{
	int i = 0;
	while (s_name[i] && isspace(s_name[i]) == 1)
		i++;
	if (isspace(s_name[i]) == 0 && i != (int)s_name.find("server_name"))
		return (-1);
	i = s_name.find("server_name") + 11;
	int j = 0;

	char *server; // malloc ?
	while (s_name[i] != '#' && s_name[i] != ';' && s_name[i])
	{
		server = (char *)malloc(sizeof(char *) * 100);
		j = 0;
		while ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i] && s_name[i] != '#')
			i++;
		while (s_name[i] != '\f' && s_name[i] != '\t' && s_name[i] != '\v' && s_name[i] != '\n' && s_name[i] != '\r' && s_name[i] != '#' && s_name[i] != ';' && s_name[i] != ' ' && s_name[i])
			server[j++] = s_name[i++];
		_MAP_server["server_name"].push_back(server);
		free(server);
	}

	return (0);
}

int conf::set_listen(std::string s_name) // voir si le res et pas plus grand que 255.255.255.255:?
{
	int i = 0;
	while (s_name[i] && isspace(s_name[i]) == 1)
		i++;
	if (isspace(s_name[i]) == 0 && i != (int)s_name.find("listen"))
		return (-1);
	i = s_name.find("listen") + 6;
	char *listen; //malloc ?

	while (s_name[i] != '#' && s_name[i] != ';' && s_name[i])
	{
		listen = (char *)malloc(sizeof(char *) * s_name.length()); //malloc mieux
		while ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i] && s_name[i] != '#')
			i++;
		if (s_name[i] == '#' || s_name[i] == ';')
		{
			free(listen);
			break ;
		}
		if (isnumber(s_name[i]) == 0)
		{
			free(listen);
			return (-1);
		}
		if (s_name[i + 3] == '.' || s_name[i + 2] == '.' || s_name[i + 1] == '.') //test segfault
		{
			int ip = 0;
			for (int x = 0; x != 4; x++)
			{
				for (int j = 0; j != 3; j++)
				{
					if (s_name[i] == '.' || s_name[i] == ':')
						break;
					if (s_name[i] >= '0' && s_name[i] <= '9')
						listen[ip] = s_name[i];
					i++;
					ip++;
				}
				listen[ip] = s_name[i];
				ip++;
				i++;
			}
			if (s_name[i - 1] == ':')
			{
				for (int w = 0; w != 4; w++)
				{
					if (s_name[i])
					{
						if (s_name[i] >= '0' && s_name[i] <= '9')
						{
							listen[ip] = s_name[i];
						}
						else
						{
							free(listen);
							return (-1);
						}
					}
					else
						break;
					i++;
					ip++;
				}
			}
			_listen = listen;
		}
		else
		{
			int port_max = 0;
			while (s_name[i] && port_max != 4)
			{
				if (s_name[i] >= '0' && s_name[i] <= '9')
					listen[port_max] = s_name[i];
				else
					break;
				i++;
				port_max++;
			}
			_listen = listen;
		}
		_MAP_server["listen"].push_back(listen);
		free(listen);
	}
	return (0);
}

int		conf::set_root(std::string s_name)
{
	int i = 0;
	while (s_name[i] && isspace(s_name[i]) == 1)
		i++;
	if (isspace(s_name[i]) == 0 && i != (int)s_name.find("root"))
		return (-1);

	i = s_name.find("root") + 4;
	char *root; //malloc ?

	root = (char *)malloc(sizeof(char *) * s_name.length());
	while ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i] && s_name[i] != '#')
		i++;
	int iroot = 0;
	while (isprint(s_name[i]) && isspace(s_name[i]) == 0 && s_name[i] != '#' && s_name[i] != ';' && s_name[i])
	{
		root[iroot] = s_name[i];
		iroot++;
		i++;
	}
	while (s_name[i])
	{
		if ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i])
			i++;
		else if (s_name[i] == '#' ||  s_name[i] == ';')
			break;
		else
		{
			free(root);
			return (-1);
		}
	}
	_MAP_server["root"].push_back(root);
	free(root);
	return (0);
}

int		conf::set_index(std::string s_name) // il faut accepter les ;ultiple index
{
	int i = 0;
	while (s_name[i] && isspace(s_name[i]) == 1)
		i++;
	if (isspace(s_name[i]) == 0 && i != (int)s_name.find("index"))
		return (-1);
	i = s_name.find("index") + 5;
	char *index; //malloc ?

	while (s_name[i] != '#' && s_name[i] != ';' && s_name[i])
	{
		index = (char *)malloc(sizeof(char *) * s_name.length());
		while ((s_name[i] == '\f' || s_name[i] == '\t' || s_name[i] == '\v' || s_name[i] == '\n' || s_name[i] == '\r' || s_name[i] == ' ') && s_name[i] && s_name[i] != '#')
			i++;
		int iindex = 0;
		while (isprint(s_name[i]) && isspace(s_name[i]) == 0 && s_name[i] != '#' && s_name[i] != ';' && s_name[i])
		{
			index[iindex] = s_name[i];
			iindex++;
			i++;
		}
		_MAP_server["index"].push_back(index);
		free(index);
	}
	return (0);
}

//IL FAUDRAIT UN TCHECK D'ERREUR EN MODE SI ON TE METT GETBLEU faut pas que ca marche
int conf::set_GET(std::string s_get)
{
	int i = 0;
	while (s_get[i] && isspace(s_get[i]) == 1)
		i++;
	if (isspace(s_get[i]) == 0 && i != (int)s_get.find("allow_methods"))
		return (-1);
	i = s_get.find("GET") + 3;
	while (s_get[i])
	{
		if ((s_get[i] == '\f' || s_get[i] == '\t' || s_get[i] == '\v' || s_get[i] == '\n' || s_get[i] == '\r' || s_get[i] == ' ') && s_get[i])
			i++;
		else if (s_get[i] == '#' ||  s_get[i] == ';')
			break;
		else
			return (-1);
	}
	if (s_get.find(" GET") != ULONG_MAX && _GET != true)
	{
		_GET = true;
		_MAP_server["allow methods"].push_back("GET");
	}
	else
		std::cout << "ERREUR GET\n";
	return (0);
}

int conf::set_POST(std::string s_get)
{
	int i = 0;
	while (s_get[i] && isspace(s_get[i]) == 1)
		i++;
	if (isspace(s_get[i]) == 0 && i != (int)s_get.find("allow_methods"))
		return (-1);
	i = s_get.find("POST") + 4;
	while (s_get[i])
	{
		if ((s_get[i] == '\f' || s_get[i] == '\t' || s_get[i] == '\v' || s_get[i] == '\n' || s_get[i] == '\r' || s_get[i] == ' ') && s_get[i])
			i++;
		else if (s_get[i] == '#' ||  s_get[i] == ';')
			break;
		else
			return (-1);
	}
	if (s_get.find(" POST") != ULONG_MAX && _POST != true)
	{
		_POST = true;
		_MAP_server["allow methods"].push_back("POST");
	}
	else
		std::cout << "ERREUR POST\n";
	return (0);
}

int conf::set_DELETE(std::string s_get)
{
	int i = 0;
	while (s_get[i] && isspace(s_get[i]) == 1)
		i++;
	if (isspace(s_get[i]) == 0 && i != (int)s_get.find("allow_methods"))
		return (-1);
	i = s_get.find("DELETE") + 7;
	while (s_get[i])
	{
		if ((s_get[i] == '\f' || s_get[i] == '\t' || s_get[i] == '\v' || s_get[i] == '\n' || s_get[i] == '\r' || s_get[i] == ' ') && s_get[i])
			i++;
		else if (s_get[i] == '#' ||  s_get[i] == ';')
			break;
		else
			return (-1);
	}
	if (s_get.find(" DELETE") != ULONG_MAX && _DELETE != true)
	{
		_DELETE = true;
		_MAP_server["allow methods"].push_back("DELETE");
	}
	else
		std::cout << "ERREUR DELETE\n";
	return (0);
}
