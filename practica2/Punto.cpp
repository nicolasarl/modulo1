//Autor: Nicolás Adrián Rodríguez Linares

#include "Punto.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

Punto::Punto(double x, double y){
  _x = x;
  _y = y;
}
  
double Punto::getX() const{
  return _x;
}
double Punto::getY() const{
  return _y;
}
  
std::string Punto::toString() const{
  std::ostringstream oss;
  oss << "p(" << std::fixed << std::setprecision(1) <<_x << ", " << _y 
      << ")";
  return oss.str();
}
std::ostream& operator<<(std::ostream &os,const Punto &p){
    os << "p(" << std::fixed << std::setprecision(1) << p.getX() 
        << ", " << p.getY() << ")";
    return os;
}

