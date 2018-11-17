// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#include "Cero.hpp"
#include <sstream>

Cero::Cero(std::string nom) : Puerta(nom){  
}
int Cero::salida(){

  return _salida;
  
}

std::string Cero::info(int numEspacios){

  std::ostringstream informacion;
  std::string espacios(numEspacios, ' ');
  if(_nombre != ""){
      informacion << espacios << "Puerta CERO [" << _nombre << "] (id=" << 
          _id_actual << ")\n";
      
  return informacion.str();
    
  }
  informacion << espacios << "Puerta CERO (id=" << _id_actual 
      << ")" << "\n";
      
  return informacion.str();
}
