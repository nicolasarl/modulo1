// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#include "Uno.hpp"
#include <sstream>


Uno::Uno(std::string nom) : Puerta(nom){
}

int Uno::salida(){

  return _salida;
  
}

std::string Uno::info(int numEspacios){

  std::ostringstream informacion;
  std::string espacios(numEspacios, ' ');
  if(_nombre != ""){
    informacion << espacios << "Puerta UNO [" << _nombre << "] (id=" << 
        _id_actual << ")\n";
      
  return informacion.str();

  }
  informacion << espacios << "Puerta UNO (id=" << _id_actual 
      << ")" << "\n";
      
  return informacion.str();
}
