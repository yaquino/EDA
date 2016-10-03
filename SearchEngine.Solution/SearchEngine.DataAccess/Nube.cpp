#include "Nube.h"



Nube::Nube()
{
	palabra_actual = "";
	documento_actual = -1;
	archivo = NULL;
	ejecutando = false;
}

Nube::Nube(std::string nombre)
{
	palabra_actual = nombre;
}

int Nube::Insertar(int id_doc, int bloque)
{
	std::vector<lista>::iterator it = nucleo.begin();
	while (it != nucleo.end())
	{
		if ((*it).id != id_doc)
			it++;
		else
		{
			(*it).contenido.push_back(bloque);
			return 1;
		}
	}
	lista nueva;
	nueva.id = id_doc;
	nueva.contenido.push_back(bloque);
	nucleo.push_back(nueva);
	return 2;
}

void Nube::guardar()
{
	int m;
	int n = nucleo.capacity();
	for (int i = 0;i < n;i++)
	{
		m = nucleo[i].contenido.capacity();
		for (int j = 0;j < m;j++)
			Insertar(palabra_actual, nucleo[i].id, nucleo[i].contenido[j]);
	}
}

void Nube::Insertar(std::string nombre, int id_doc, int bloque)
{
	if (!ejecutando)
		abrir_doc(nombre);
	if (nombre.compare(palabra_actual) != 0)
		cambiar_doc(nombre);
	 
	std::string temp;
	if (documento_actual == -1)
	{
		temp = std::to_string(id_doc);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
		documento_actual = id_doc;
		
		temp = " "+std::to_string(bloque);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	else if (documento_actual == id_doc)
	{
		temp = " " + std::to_string(bloque);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	else
	{
		temp = "\n" + std::to_string(id_doc);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);

		temp = " " + std::to_string(bloque);
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
		documento_actual = id_doc;
	}

}

void Nube::abrir_doc(std::string nombre)
{
	fopen_s(&archivo, (nombre + ".txt").data(), "w+");
	palabra_actual = nombre;
	ejecutando = true;
}

void Nube::cambiar_doc(std::string nombre)
{
	fclose(archivo);
	fopen_s(&archivo, (nombre + ".txt").data(), "w+");
	palabra_actual = nombre;
	documento_actual = -1;
}


Nube::~Nube()
{
	_fcloseall();
}
