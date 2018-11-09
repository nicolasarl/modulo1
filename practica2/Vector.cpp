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

Vector::Vector(Punto p1, Punto p2) : _inicial(0,0),
  _final(p2.getX() - p1.getX(),p2.getY() - p1.getY())
{
}

double Vector::getModulo(){
   
  return std::sqrt(std::pow(_final.getX() - _inicial.getX(),2) + 
      std::pow(_final.getY() - _inicial.getY(),2));
  
}

double Vector::getAngulo(){
  
  return (180*std::atan2(_final.getY() - _inicial.getY(),
      _final.getX() - _inicial.getX()))/pi;
}

Punto Vector::getPtoFinal(){
  
  return _final;
}

std::string Vector::toString(){
      
  std::ostringstream oss;
  oss << "v(" << std::fixed << std::setprecision(1) <<getModulo() << ", " 
      << getAngulo() << ")";
      
  return oss.str();
  
}

std::string Vector::toStringPt(){
  
  std::ostringstream oss;
  oss << "vp(" << std::fixed << std::setprecision(1) <<_final.getX() 
      << ", " << _final.getY() << ")";
  return oss.str();
  
}

std::ostream& operator<<(std::ostream &os, Vector &v){
    os << v.toString();
    return os;
}
