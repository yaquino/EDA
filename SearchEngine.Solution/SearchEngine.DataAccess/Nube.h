#pragma once
#include "../SearchEngine.Core/ICloud.h"
#include <vector>
#include <string>
#include <stdio.h>


struct lista
{
	int id;
	std::vector<int> contenido;
};

class Nube:virtual ICloud
{
private:
	std::vector<lista> nucleo;
	std::string palabra_actual;
	int documento_actual;
	FILE *archivo;
	bool ejecutando;
	void abrir_doc(std::string nombre);
	void cambiar_doc(std::string nombre);

public:
	Nube();
	Nube(std::string nombre);

	int Insertar(int id_doc, int bloque);

	void guardar();
	void cargar();
	void Insertar(std::string nombre, int id_doc, int bloque);
	~Nube();
};

