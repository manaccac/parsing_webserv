#include "webserv.hpp"

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
	std::cout << on_serve << std::endl;
	std::cout << on_location << std::endl;
}