#pragma once
#include <string>
typedef std::string FILE_NAME;
typedef	unsigned int NUMBER_LINES;
class Pagina_A //:	public IPage
{
private:
	FILE_NAME nombre;
public:
	Pagina_A();
	Pagina_A(FILE_NAME nombre);
	~Pagina_A();
	// Devuelve el nombre de la pagina (archivo)
	FILE_NAME GetName();
	// devolucion de numero de filas por pagina
	NUMBER_LINES GetNumberLines();
};

