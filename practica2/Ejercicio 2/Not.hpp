// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _NOT_
#define _NOT_

#include "PtaAlMenosUnaEntrada.hpp"
#include <string>

class Not : public PtaAlMenosUnaEntrada{


public:

  Not() = default;
  Not(std::string nom);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);

};



#endif //Del ifndef _Not_
