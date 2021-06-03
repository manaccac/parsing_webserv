#include "webserv.hpp"
#include "conf.hpp"

int	ft_muted_line(std::string line)
{
	int i = 0;

	while (line[i])
	{
		if (line[i] == '#' || line[i] == ';')
			return (1);
		if (line[i] == '\f' || line[i] == '\t' || line[i] == '\v' || line[i] == '\n' || line[i] == '\r' || line[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (0);
}

//fonction carractere avent a cree qui nous permet de voir directement si la ligne es valide

int ft_methods_check(std::string line)
{
	int i;

	i = line.find("allow_methods") + 13;
	while (line[i])
	{
		if (line[i] == 'G' && line[i + 1] == 'E' && line[i + 2] == 'T') //test avec juste un G pour voir si sa segfault
			i += 3;
		else if (line[i] == 'P' && line[i + 1] == 'O' && line[i + 2] == 'S' && line[i + 3] == 'T')
			i += 4;
		else if (line[i] == 'D' && line[i + 1] == 'E' && line[i + 2] == 'L' && line[i + 3] == 'E' && line[i + 4] == 'T' && line[i + 5] == 'E')
			i += 6;
		else if (line[i] == '\f' || line[i] == '\t' || line[i] == '\v' || line[i] == '\n' || line[i] == '\r' || line[i] == ' ')
			i++;
		else if (line[i] == '#' || line[i] == ';')
			return (0);
		else
			return (-1);
	}
	return (1);
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "ERROR ARG jsut need .conf" << std::endl;
		return (-1);
	}
	
	
	std::string  arg = argv[1];

	int pos_find = 0;
	pos_find = arg.find(".conf");

	if (pos_find == -1)
	{
		std::cout << "ERROR .conf not found" << std::endl;
		return (-2);
	}
	//erreur a check si on ecrit juste .conf sans rien et aussi si le fichier n'existe pas

	//maintenant on passe au parsing

	std::ifstream	Read_file(argv[1]);
	std::string		line;

	int nb_line = 0;
	int on_serve = 0; //variable qui dit si on se trouve dans les acolade de serve
	int on_location = 0;
	while (std::getline(Read_file, line))
	{
		if (check_line(line, on_serve, on_location) == -1)//check ligne si valide ou non
		{
			std::cout << "line = " << nb_line + 1 << " ERROR ON THIS LINE:" << std::endl << line << std::endl;
			//std::cout << on_serve << std::endl;
			return (-1);
		}
		if (check_line(line, on_serve, on_location) == 3)
			on_serve++;
		else if (check_line(line, on_serve, on_location) == 4)
			on_serve--;
		if (check_line(line, on_serve, on_location) == 5)
			on_location++;
		if (check_line(line, on_serve, on_location) == 6)
			on_location--;
		nb_line++;
	}
	if (on_serve >= 1)
	{
		std::cout << "SERVER NOT OK" << std::endl;
		return (-1);
	}
	if (on_location >= 1)
	{
		std::cout << "LOCATION NOT OK" << std::endl;
		return (-1);
	}
	//on commence a ranger tous
	std::ifstream pars_file(argv[1]);
	conf file_conf;

	bool ser_name = false;//pour savoir au'il y a bien 1 server_name par server
	nb_line = 0;
	while (std::getline(pars_file, line))
	{
		nb_line++;
		if ((line.find("server") >= 0 && line.find("server") != ULONG_MAX)
			&& line.find("server") < line.find("#") && line.find("server_name") == ULONG_MAX) // check si le server et valide maintenant si il les partir dnas un autre parsing specliale serve
		{
			ser_name = false;//pour savoir au'il y a bien 1 server_name par server
			// pars serve
			while (std::getline(pars_file, line) && line.find("}"))
			{
				nb_line++;
				if (ft_muted_line(line) == 1)// il faut changer ca et regarder si il y a un truc avent le mute
					;
				else
				{
					if (line.find("server_name ") != ULONG_MAX)
						file_conf.set_name(line);
					if (line.find("location") != ULONG_MAX)
					{
						while (std::getline(pars_file, line) && line.find("}") == ULONG_MAX)
						{
							;
						}
					}
					else if (line.find("allow_methods") != ULONG_MAX)
					{
						if (line.find("GET") != ULONG_MAX)
							file_conf.set_GET(line);
						if (line.find("POST") != ULONG_MAX)
							file_conf.set_POST(line);
						if (line.find("DELETE") != ULONG_MAX)
							file_conf.set_DELETE(line);
						if (ft_methods_check(line) == -1)
						{
							std::cout << "line = " << nb_line << " ALLOW_METHODS ERROR" << std::endl;
							return (-1);
						}
					}
				}
				//a faire SI LA LIGNE N'est pas use ou mute c'est quelle et fausse
			}
		}
	}
	std::cout << file_conf.get_GET() << std::endl;
	std::cout << file_conf.get_POST() << std::endl;
	std::cout << file_conf.get_DELETE() << std::endl;

	std::cout << file_conf.get_name() << std::endl;
	// si pas de name ou de root ou autre return erreur
}
