// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 17/11/2018

#include "AndM.hpp"
#include <sstream>
#include <iostream>


AndM::AndM(std::string nom) : Puerta(nom){  
}

void AndM::conecta(Puerta* pt){
  std::cerr << "Se hace una conexión usando conecta" << std::endl;
  _entrada.push_back(pt);
  
}

void AndM::conecta(Puerta* pt, unsigned i){

  if((i == 0) && (_entrada.size() == 0)){//Creamos primera puerta si no estuviera ya creada
    _entrada.push_back(pt);
    return;
  }
    
  if (i < _entrada.size()){ //Más o igual entradas que índices
    _entrada[i] = pt;
    return;
  }else{
    
    for(unsigned n = _entrada.size(); n < i; n++){//no existen las entradas
      
      _entrada.push_back(nullptr);
      
    }
    
    _entrada.push_back(pt);
    return;
  }
}

int AndM::salida(){
  
  if(_entrada.size() < 2){ // Pocas entradas
    
    return ND;
    
  }
  for(unsigned j = 0; j < _entrada.size(); j++){

    if(_entrada[j] == nullptr){ // Puerta no indicada
      return ND;
    }
  }
  for(unsigned k = 0; k < _entrada.size(); k++){ 
    
    if((_entrada[k] -> salida()) == ND) // Si alguna entrada es 0, la salida debe ser 0
      return ND;
    
  }
  for(unsigned k = 0; k < _entrada.size(); k++){ 
    
    if((_entrada[k] -> salida()) == 0) // Si alguna entrada es 0, la salida debe ser 0
      return 0;
    
  }
  
  return 1;
}

std::string AndM::info(int numEspacios){
  
  std::ostringstream informacion;
  std::string espacios(numEspacios, ' ');
    
  informacion << espacios << "Puerta ANDM ";
  
  if(_nombre != "")
    informacion << "[" << _nombre << "] ";
    
  informacion << "(id=" << _id_actual << ") salida = " << salida();
    
  informacion << "\n";
  
  for(unsigned i = 0; i < _entrada.size(); i++){
    
    if(_entrada[i] == nullptr){
      informacion << espacios << "  NO CONECTADA" << "\n";
    }else{
      informacion << _entrada[i] -> info(numEspacios + 2);
    }
  }
  
  return informacion.str();
  
}
