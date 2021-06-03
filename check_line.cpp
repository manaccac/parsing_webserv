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
			if (line.find("server") == 0) // prochaine etape autoriser les tab et tous avent server
			{	// besoin d'une autre verif si il y a des truc entre server et {
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
							if (line[pos] == '#')
								return (3);
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
		while (line[i]) //verif si il y a du text avent le mute
		{
			if (line[i] == '#') // il faut une autre fonction qui regarde si il y a des truc avent le mute
				return (0);
			if (line[i] != '\f' && line[i] != '\t' && line[i] != '\v' && line[i] != '\n' && line[i] != '\r' && line[i] != ' ')
				break;
			i++;
		}
		if ((on_location == 0 && line.find("{") != ULONG_MAX && line.find("location") == ULONG_MAX)
			|| line.find("location") > line.find("{")) // verif si il y a exemple {location
				return (-1);
		if (on_location == 0 && line.find("}") != ULONG_MAX)
			return (4);

		//location tchek
		if (line.find("location") != ULONG_MAX)
		{
			if (line.find("{") == ULONG_MAX)
				return (-1);
			int pos = line.find("{") + 1;
			while (line[pos])
			{
				if (line[pos] == '#')
					return (5);
				if (line[pos] != '\t' && line[pos] != ' ' && line[pos] != '\n' && line[pos] != '\v')
					return (-1);
				pos++;
			}
			return (5);
		}
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
