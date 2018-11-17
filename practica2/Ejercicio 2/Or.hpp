// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _OR_
#define _OR_

#include "PtaAlMenosDosEntradas.hpp"
#include <string>

class Or : public PtaAlMenosDosEntradas{

public:

  Or() = default;
  Or(std::string nom);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);

};



#endif //Del ifndef _OR_
