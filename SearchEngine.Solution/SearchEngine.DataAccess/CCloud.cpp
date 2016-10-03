#include "CCloud.h"
template <class T>
CCloud<T>::CCloud()
{
	palabra_actual = "";
	documento_actual = -1;
	archivo = NULL;
	ejecutando = false;
}
template <class T>
CCloud<T>::CCloud(T_STRING nombre)
{
	palabra_actual = nombre;
}
template <class T>
T_INT CCloud<T>::Insertar(T_INT id_doc, T_INT bloque)
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
template <class T>
void CCloud<T>::setNombre(T_STRING nombre)
{
	palabra_actual = nombre;
}
template <class T>
T_INT CCloud<T>::getNumber_doc()
{
	return nucleo.size();
}
template <class T>
void CCloud<T>::guardar()
{
	int m;
	int n = nucleo.size();
	std::string temp;
	fopen_s(&archivo, ("CCloud\\" + palabra_actual + ".txt").data(), "w+");
	if (archivo == NULL)
		return;
	for (int i = 0;i < n;i++)
	{
		temp = std::to_string(nucleo[i].id);
		m = nucleo[i].contenido.size();
		for (int j = 0;j < m;j++)
		{
			temp = temp + " " + std::to_string(nucleo[i].contenido[j]);
		}
		temp = temp + "\n";
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	fclose(archivo);
}
template <class T>
void CCloud<T>::Insertar(T_STRING nombre, T_INT id_doc, T_INT bloque)
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
template <class T>
void CCloud<T>::abrir_doc(T_STRING nombre)
{
	fopen_s(&archivo, (nombre + ".txt").data(), "w+");
	palabra_actual = nombre;
	ejecutando = true;
}
template <class T>
void CCloud<T>::cambiar_doc(T_STRING nombre)
{
	fclose(archivo);
	fopen_s(&archivo, (nombre + ".txt").data(), "w+");
	palabra_actual = nombre;
	documento_actual = -1;
}

template <class T>
CCloud<T>::~CCloud()
{
	_fcloseall();
}
