// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _AND_
#define _AND_

#include "PtaAlMenosDosEntradas.hpp"
#include <string>

class And : public PtaAlMenosDosEntradas{

public:

  And() = default;
  And(std::string nom);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);

};



#endif //Del ifndef _AND_
