// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 14/11/2018

#include "PtaAlMenosUnaEntrada.hpp"

PtaAlMenosUnaEntrada::PtaAlMenosUnaEntrada(std::string nom) : Puerta(nom){
}
void PtaAlMenosUnaEntrada::conecta1(Puerta* pt){
  
  _ptE1 = pt;
  
}
