// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#include "Fijo.hpp"
#include <sstream>


Fijo::Fijo(std::string nom) : Puerta(nom){
  
  _nombre = nom;
  
}

int Fijo::salida(){

  return _salida;

}

void Fijo::pon1(){

  _salida = 1;
  
}

void Fijo::pon0(){

  _salida = 0;
 
}

std::string Fijo::info(int numEspacios){

  std::ostringstream informacion;
  std::string espacios(numEspacios, ' ');
  if(_nombre != ""){
    informacion << espacios << "Puerta FIJO [" << _nombre << "] (id=" << 
        _id_actual << ")\n";
      
  return informacion.str();
    
  }
  informacion << espacios << "Puerta FIJO" << " (id=" << 
      _id_actual << ") salida = " << salida() << "\n";
      
  return informacion.str();

}
