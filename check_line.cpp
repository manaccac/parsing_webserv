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
			if (line.find("server") == 0) // besoin d'une autre verif si il y a des truc entre server et {
			{
				int pos = line.find("server") + 6;
				while (line[pos])
				{
					if (line[pos] != '\t' && line[pos] != ' ' && line[pos] != '\n' && line[pos] != '\v' && line[pos] != '{')
						return (-1);
					if (line[pos] == '{')
					{
						pos++;
						while (line[pos]) // check si il y a { {
						{
							if (line[pos] != '\t' && line[pos] != ' ' && line[pos] != '\n' && line[pos] != '\v')
								return (-1);
							pos++;
						}
					}
					else
						pos++;
				}
				if (line.find("{") != ULONG_MAX)
					return (3);
			}
			else
				return (-1);
		}
	}
	else
	{
		if (line[i] == '#') // il faut une autre fonction qui regarde si il y a des truc avent le mute
			return (0);
		if ((on_location == 0 && line.find("{") != ULONG_MAX && line.find("location") == ULONG_MAX)
			|| line.find("location") > line.find("{")) // verif si il y a exemple {location
			return (-1);
		if (on_location == 0 && line.find("}") != ULONG_MAX)
			return (4);

		//location tchek

		if (line.find("location") != ULONG_MAX)
			return (5);

		//
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
