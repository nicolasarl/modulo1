// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018


#ifndef _ORM_
#define _ORM_

#include "Puerta.hpp"
#include <vector>
#include <string>

class OrM : public Puerta{

private:

  std::vector<Puerta*> _entrada;
  
public:

  OrM() = default;
  OrM(std::string nom);
  void conecta(Puerta* pt);
  void conecta(Puerta* pt, unsigned i);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);
};
#endif
