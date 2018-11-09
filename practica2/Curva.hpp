// Autor: Nicolás Adrián Rodríguez Linares

#ifndef _CURVA_
#define _CURVA_
#include "Vector.hpp"
#include "Punto.hpp"
#include <vector>

class Curva {
	
private:
  std::vector<Punto> _punto;
public:

  Curva(Punto pto);
  void aniade(Punto pto);
  void aniade(Vector vec);
  unsigned getNumTramos();
  Punto getPtoInicial();
  Punto getPtoI(unsigned int i);
  Vector getVector(unsigned int i);
  void quitaUltimo();
  bool esCerrada();
  double largo();
  std::string toStringPt();
  std::string toStringVec();
	
	
};
std::ostream& operator<<(std::ostream &os, Curva &c);

#endif // de ifdef _CURVA_
