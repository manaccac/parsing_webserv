#include <iostream>
#include <string>

#include <fstream> // pour le read

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
	while (std::getline(Read_file, line))
	{
		if (line.find("#")) // a un endroit dans la ligne il y a un commentaire
		{
		}
		if ((line.find("server") >= 0 && line.find("server") != ULONG_MAX)
			&& line.find("server") < line.find("#")) // check si le server et valide maintenant si il les partir dnas un autre parsing specliale serve
		{
			//il faut verifier si le server et bien valide avec { ... }
			std::cout << line << std::endl;
			//std::cout << nb_line << std::endl;
		}
		nb_line++;
	}
}