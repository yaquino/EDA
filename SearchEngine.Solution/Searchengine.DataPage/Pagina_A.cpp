#include "Pagina_A.h"



Pagina_A::Pagina_A()
{
	Pagina_A("Luis.txt");
}

Pagina_A::Pagina_A(FILE_NAME nombre)
{
}


Pagina_A::~Pagina_A()
{
}


// Devuelve el nombre de la pagina (archivo)
FILE_NAME Pagina_A::GetName()
{
	return FILE_NAME();
}


// devolucion de numero de filas por pagina
NUMBER_LINES Pagina_A::GetNumberLines()
{
	return NUMBER_LINES();
}
