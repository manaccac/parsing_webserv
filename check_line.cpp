#include "webserv.hpp"

int	check_line(std::string line, int on_serve, int on_location)
{
	int i = 0 ;
	if (on_serve == 0)
	{
		while (line[i])
		{
			if (line[i] == '#')
				return (1);
			if (line[i] != '\t' || line[i] != ' ' || line[i] != '\n' || line[i] != '\v') // quelle sont les autre sorte de tab
				i++;
			if (line.find("server") == 0)
				return (3);
			else
				return (-1);
		}
	}
	else
	{
		if (line[i] == '#') // il faut une autre fonction qui regarde si il y a des truc avent le mute
			return (0);
		if (on_location == 0 && line.find("}") != ULONG_MAX)
			return (4);
		if (line.find("location") != ULONG_MAX)
			return (5);
		if (on_location >= 1 && line.find("}") != ULONG_MAX)
			return (6);
		if ((line.find("server") >= 0 && line.find("server") != ULONG_MAX)
			&& line.find("server") > line.find("#"))
			return (0);
		if ((line.find("server") >= 0 && line.find("server") != ULONG_MAX) && (int)line.find("server_name") == -1)
			return (-1);
		//d'autre probleme ?
	}
	return (0);
}