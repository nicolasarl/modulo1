// Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018


#ifndef _ANDM_
#define _ANDM_

#include "Puerta.hpp"
#include <vector>
#include <string>

class AndM : public Puerta{

private:

  std::vector<Puerta*> _entrada;
  
public:

  AndM() = default;
  AndM(std::string nom);
  void conecta(Puerta* pt);
  void conecta(Puerta* pt, unsigned i);
  virtual int salida();
  virtual std::string info(int numEspacios = 0);
};
#endif
