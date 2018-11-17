// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 13/11/2018

#ifndef _PUERTA_
#define _PUERTA_

#include <string>

#define ND (9)

class Puerta{

protected:

 static int _id; // Lleva la cuenta de las id
 int _id_actual; // Almacena la id de cada objeto
 std::string _nombre = "";
 
public:

  Puerta();
  Puerta(std::string nom);
  int virtual salida() = 0;
  std::string virtual info(int numEspacios = 0) = 0;
};
#endif
