// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 14/11/2018

#include "PtaAlMenosDosEntradas.hpp"

PtaAlMenosDosEntradas::PtaAlMenosDosEntradas(std::string nom) 
    : PtaAlMenosUnaEntrada(nom){
}
void PtaAlMenosDosEntradas::conecta2(Puerta* pt){
  
  _ptE2 = pt;
  
}
