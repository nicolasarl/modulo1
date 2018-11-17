// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _CERO_
#define _CERO_

#include "Puerta.hpp"
#include <string>

class Cero : public Puerta{
	
private:

  const unsigned _salida = 0;

public:

  Cero() = default;
  Cero(std::string nom);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);

};



#endif //Del ifndef _CERO_
