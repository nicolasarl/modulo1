// Autor: Nicolás Adrián Rodríguez Linares

#include "Curva.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Curva::Curva(Punto pto){
 _punto.push_back(pto);
}

void Curva::aniade(Punto pto){
  _punto.push_back(pto);	
}

void Curva::aniade(Vector vec){
  Punto p1 = _punto[_punto.size()-1]; //punto final de la curva
  Punto p2 = vec.getPtoFinal();//punto final nuevo vector
  Punto p3(p2.getX() + p1.getX(), p2.getY() + p1.getY());
  _punto.push_back(p3);//añadimos nuevo punto final
}

unsigned int Curva::getNumTramos(){
  return (_punto.size() - 1);
}

Punto Curva::getPtoInicial(){
  return _punto[0];
}

Punto Curva::getPtoI(unsigned int i){
  if (i < 0){
    std::cout << "Error: No puede introducirse un indice negativo" 
        << std::endl;
    exit(EXIT_FAILURE);
  }    
  if (i > (_punto.size() - 1)){
    std::cout << "Error: No se han introducido tantos puntos" 
        << std::endl;
    exit(EXIT_FAILURE);
  }
  return _punto[i];
}

Vector Curva::getVector(unsigned int i){
  if (i < 0){
    std::cout << "Error: No puede introducirse un indice negativo" 
        << std::endl;
    exit(EXIT_FAILURE);
  }    
  if (i > (_punto.size() - 2)){
    std::cout << "Error: No se han introducido tantos tramos" 
        << std::endl;
    exit(EXIT_FAILURE);
  }
  return Vector(_punto[i], _punto[i + 1]);
}

void Curva::quitaUltimo(){
  _punto.pop_back();
}

bool Curva::esCerrada(){
  Punto p0 = _punto[0];
  Punto pf = _punto[_punto.size() - 1];
  if((p0.getX() == pf.getX()) && (p0.getY() == pf.getY())){
    std::cerr << "La curva es cerrada" << std::endl;
    return 1;
  }
  return 0;
}

double Curva::largo(){
  double longitud = 0;
  for(unsigned int i = 0; i < (_punto.size() - 1); i++){
    longitud += getVector(i).getModulo();
  }
  return longitud;
}

std::string Curva::toStringPt(){
  std::ostringstream oss;
  oss << "c[ " << std::fixed << std::setprecision(1);
  for(unsigned int i = 0; i < _punto.size(); i++){
    oss << _punto[i].toString();
    if((i + 1) != _punto.size()){
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}

std::string Curva::toStringVec(){
  std::ostringstream oss;
  oss << "c[ " << std::fixed << std::setprecision(1) 
    << _punto[0].toString() << ", ";
  for(unsigned int i = 0; i < (_punto.size() - 1); i++){
    oss << getVector(i).toStringPt();
    if((i + 1) != _punto.size()){
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}
std::ostream& operator<<(std::ostream &os, Curva &c){
    os << c.toStringPt();
    return os;
}
