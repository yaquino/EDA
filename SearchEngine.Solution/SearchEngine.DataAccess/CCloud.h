#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/ICloud.h"


template <class T>
class CCloud : virtual public ICloud<T> {
private:
	map<int,vector<int>> nucleo;
	T_STRING palabra_actual;
	T_INT documento_actual;
	FILE *archivo;
	T_BOOL ejecutando;
	T_BOOL existe_arch;
	void hilo_guardar();
public:
	CCloud();
	CCloud(T_STRING nombre);
	~CCloud();
	inline T_STRING GetName() { return palabra_actual; }
	inline NUMBER_LINES GetNumberLines() { return nucleo.size(); }
	T_INT Insertar(T_INT id_doc, T_INT bloque);
	inline void setName(T_STRING nombre){ palabra_actual = move(nombre); }
	inline T_INT getNumber_doc(){ return nucleo.size(); }
	inline T_BOOL existe_archivo(){ return existe_arch; }
	void guardar();
	void cargar();
};