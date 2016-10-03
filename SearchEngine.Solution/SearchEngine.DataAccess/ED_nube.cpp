// ED_nube.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Nube.h"
#include <vector>
#include <string>
#include <stdio.h>
#include <unordered_map>

int main()
{
	std::unordered_map<std::string, Nube> alpha;

	FILE *archivolectura;
	std::string c,temp;
	int b, a;
	char z[50];


	
	fopen_s(&archivolectura, "out.txt", "r");

	while (fgets(z, 50, archivolectura)!=NULL)
	{
		char *t = strtok(z, "\t\n");
		if (t == NULL)
		{
			continue;
		}
		try {
			a = std::stoi(t);
			t = strtok(NULL, "\t\n");
			b = std::stoi(t);
			t = strtok(NULL, "\t\n");
			c = t;
		}
		catch (...) {
			break;
		}
		alpha[c].Insertar(a, b);
		alpha[c].setNombre(c);
		
	}
	fclose(archivolectura);
	fopen_s(&archivolectura, "Indice.txt", "w+");

	std::unordered_map<std::string, Nube>::iterator it = alpha.begin();
	while (it != alpha.end())
	{
		(*it).second.guardar();
		temp = (*it).first + " " + std::to_string((*it).second.getNumber_doc()) + "\n";
		fwrite(temp.data(), sizeof(char), temp.length(), archivolectura);
		it++;
	}
	
	Nube test;



    return 0;
}

