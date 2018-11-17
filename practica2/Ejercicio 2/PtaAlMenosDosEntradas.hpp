// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 14/11/2018

#ifndef _PTAALMENOSDOSENTRADAS_
#define _PTAALMENOSDOSENTRADAS_

#include "PtaAlMenosUnaEntrada.hpp"


class PtaAlMenosDosEntradas : public PtaAlMenosUnaEntrada{

protected:

  Puerta* _ptE2 = nullptr;
  
public:

  PtaAlMenosDosEntradas() = default;
  PtaAlMenosDosEntradas(std::string nom);
  void conecta2(Puerta* pt);

};
#endif
