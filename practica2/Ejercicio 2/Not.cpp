// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#include "Not.hpp"
#include <sstream>


Not::Not(std::string nom) : PtaAlMenosUnaEntrada(nom){
}


int Not::salida(){

  if(_ptE1 == nullptr)
    return ND;
  int ve = _ptE1->salida();
  
  if (ve == ND)
    return ND;
    
  return ! ve;
  
}

std::string Not::info(int numEspacios){

  std::ostringstream informacion;
  std::string espacios(numEspacios, ' ');
  if(_nombre != ""){
    informacion << espacios << "Puerta NOT [" << _nombre << "] (id=" << 
        _id_actual << ") salida = " << salida() << "\n";
    if(_ptE1 == nullptr){
      informacion << espacios << "  NO CONECTADA\n";
      return informacion.str();
    }
    informacion << _ptE1->info(numEspacios + 2);
      
    return informacion.str();
    
  }
  informacion << espacios << "Puerta NOT (id=" << _id_actual 
      << ") salida = " << salida() << "\n";
  
  if(_ptE1 == nullptr){
    informacion << espacios << "  NO CONECTADA\n";
    return informacion.str();
  }
  informacion << _ptE1->info(numEspacios + 2);
    
  return informacion.str();
}
