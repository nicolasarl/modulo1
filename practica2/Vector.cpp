//Autor: Nicolás Adrián Rodríguez Linares

#include "Vector.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>

const double pi = std::acos(-1);//Definimos constante pi

Vector::Vector(double modulo, double angulo) :
_inicial(0,0),_final(modulo*std::cos((angulo*pi)/180),modulo*
      std::sin((angulo*pi)/180))
{
}
Vector::Vector(Punto p0)  : _inicial(0,0), _final(p0.getX(),p0.getY())
{ 
}
Vector::Vector(Punto p1, Punto p2) : _inicial(p1.getX(),p1.getY()),
  _final(p2.getX(),p2.getY())
{
}
double Vector::getModulo(){
  double modulo = 0;
  modulo = std::sqrt(std::pow(_final.getX() - _inicial.getX(),2) + 
      std::pow(_final.getY() - _inicial.getY(),2));
  return modulo;
  
}
double Vector::getAngulo(){
  double angulo = 0;
  angulo = (180*std::atan2(_final.getY() - _inicial.getY(),
      _final.getX() - _inicial.getX()))/pi;
  return angulo;
}
Punto Vector::getPtoFinal(){
  
  return _final;
}
std::string Vector::toString(){
  double angulo = 0;
  double modulo = 0;
  angulo = (180*std::atan2(_final.getY() - _inicial.getY(),
      _final.getX() - _inicial.getX()))/pi;
  modulo = std::sqrt(std::pow(_final.getX() - _inicial.getX(),2) + 
      std::pow(_final.getY() - _inicial.getY(),2));
      
  std::ostringstream oss;
  oss << "v(" << std::fixed << std::setprecision(1) <<modulo << ", " 
      << angulo << ")";
      
  return oss.str();
  
}
std::string Vector::toStringPt(){
  
  std::ostringstream oss;
  oss << "vp(" << std::fixed << std::setprecision(1) <<_final.getX() 
      << ", " << _final.getY() << ")";
  return oss.str();
  
}
//¿Por qué no funciona poniendo const Vector &v y en la sobrecarga con Punto sí?
std::ostream& operator<<(std::ostream &os, Vector &v){
    os << "v(" << std::fixed << std::setprecision(1) << v.getModulo() 
        << ", " << v.getAngulo() << ")";
    return os;
}
