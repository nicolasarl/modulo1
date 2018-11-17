// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _UNO_
#define _UNO_

#include "Puerta.hpp"
#include <string>

class Uno : public Puerta{

private:

  const unsigned _salida = 1;

public:

  Uno() = default;
  Uno(std::string nom);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);

};



#endif //Del ifndef _UNO_
