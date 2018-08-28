#include "CCloud.h"

template <class T>
CCloud<T>::CCloud()
{
	palabra_actual = ""s;
	documento_actual = -1;
	archivo = NULL;
	existe_arch = false;
}

template <class T>
CCloud<T>::CCloud(T_STRING nombre)
{
	palabra_actual = move(nombre);
	documento_actual = -1;
	archivo = NULL;
	existe_arch = false;
}

template <class T>
T_INT CCloud<T>::Insertar(T_INT id_doc, T_INT bloque)
{
	nucleo[id_doc].push_back(bloque);
	return 2;
	
}


template<class T>
void CCloud<T>::hilo_guardar()
{
	std::string temp;
	fopen_s(&archivo, ("CCloud\\" + palabra_actual + ".txt").data(), "w+");
	if (archivo == NULL)
		return;

	for (auto elem : nucleo)
	{
		temp = std::to_string(elem.first);
		for (T_INT block : elem.second)
		{
			temp = temp + " "s + std::to_string(block);
		}
		temp = temp + "\n"s;
		fwrite(temp.data(), sizeof(char), temp.length(), archivo);
	}
	fclose(archivo);
}

template <class T>
void CCloud<T>::guardar()
{
	std::thread(hilo_guardar).detach();
	existe_arch = true;
}

template<class T>
void CCloud<T>::cargar()
{
	nucleo.clear();
	fopen_s(&archivo, ("CCloud\\"s + palabra_actual + ".txt"s).data(), "r");

}

template <class T>
CCloud<T>::~CCloud()
{
	_fcloseall();
}


