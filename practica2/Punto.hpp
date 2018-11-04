//Autor: Nicolás Adrián Rodríguez Linares
#ifndef _PUNTO_
#define _PUNTO_
#include <string>
#include <iostream>
class Punto {

private:

  double _x;
  double _y;
  
public:

  Punto(double x, double y);
  
  double getX() const;
  double getY() const;
  
  std::string toString() const;
  
};
std::ostream& operator<<(std::ostream &os,const Punto &p);

#endif // de ifndef _PUNTO_
