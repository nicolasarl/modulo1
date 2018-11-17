// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#include "Puerta.hpp"

int Puerta::_id = 0;

Puerta::Puerta(){

  _id_actual = _id;
  _id ++;

}

Puerta::Puerta(std::string nom) : Puerta(){

  _nombre = nom;
  
}
