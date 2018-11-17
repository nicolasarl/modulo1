// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#include "Or.hpp"
#include <sstream>


Or::Or(std::string nom) : PtaAlMenosDosEntradas(nom){
}

int Or::salida(){

  if((_ptE1 == nullptr) || (_ptE2 == nullptr))
    return ND;
  if (((_ptE1->salida()) == 9) || ((_ptE2->salida()) == 9))
    return ND;
  int ve = ((_ptE1->salida()) || (_ptE2->salida()));
    
  return ve;
  
}

std::string Or::info(int numEspacios){

  std::ostringstream informacion;
  std::string espacios(numEspacios, ' ');
  
  //En caso de que tenga nombre
  
  if(_nombre != ""){
    informacion << espacios << "Puerta OR [" << _nombre << "] (id=" << 
        _id_actual << ") salida = " << salida() << "\n";
  
    if(_ptE1 == nullptr){
      if (numEspacios != 0){
        informacion << espacios << "  NO CONECTADA\n";
      }else{
        informacion << "  NO CONECTADA\n";
      }
    }else{
      informacion << _ptE1->info(numEspacios + 2);
    }

    if(_ptE2 == nullptr){
      if (numEspacios != 0){
        informacion << espacios << "  NO CONECTADA\n";
      }else{
        informacion << "  NO CONECTADA\n";
      }
    }else{
      informacion << _ptE2->info(numEspacios + 2);
    }
    
    return informacion.str();
    
  }
  
  // En caso de que NO tenga nombre
  
  informacion << espacios << "Puerta OR (id=" << _id_actual 
      << ") salida = " << salida() << "\n";

  if(_ptE1 == nullptr){
    if (numEspacios != 0){
      informacion << espacios << "  NO CONECTADA\n";
    }else{
      informacion << "  NO CONECTADA\n";
    }
  }else{
    informacion << _ptE1->info(numEspacios + 2);
  }

  if(_ptE2 == nullptr){
    if (numEspacios != 0){
      informacion << espacios << "  NO CONECTADA\n";
    }else{
      informacion << "  NO CONECTADA\n";
    }
  }else{
    informacion << _ptE2->info(numEspacios + 2);
  }
       
  return informacion.str();
}
