//Autor: Nicolás Adrián Rodríguez Linares
#ifndef _VECTOR_
#define _VECTOR_
#include "Punto.hpp"

class Vector{
  
private:
  Punto _inicial;
  Punto _final;
  
public:

  Vector(double modulo, double angulo);
  Vector(Punto p0);
  Vector(Punto p1, Punto p2) ;
  double getModulo();
  double getAngulo();
  Punto getPtoFinal();
  std::string toString();
  std::string toStringPt();

};
std::ostream& operator<<(std::ostream &os, Vector &v);
#endif // de ifndef _VECTOR_
