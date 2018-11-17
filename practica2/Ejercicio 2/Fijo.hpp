// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _FIJO_
#define _FIJO_

#include "Puerta.hpp"

class Fijo : public Puerta{

private:

  unsigned _salida = 9;
  
public:

  Fijo() = default;
  Fijo(std::string nom);
  void pon1();
  void pon0();
  virtual int salida();
  virtual std::string info(int numEspacios = 0);
};
#endif
