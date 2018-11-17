// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 14/11/2018

#ifndef _PTAALMENOSUNAENTRADA_
#define _PTAALMENOSUNAENTRADA_

#include "Puerta.hpp"

class PtaAlMenosUnaEntrada : public Puerta{

protected:

  Puerta* _ptE1 = nullptr;
  
public:

  PtaAlMenosUnaEntrada() = default;
  PtaAlMenosUnaEntrada(std::string nom);
  void conecta1(Puerta* pt);

};
#endif
