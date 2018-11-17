// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() de Or"

#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Or a0;
  Uno u1;
  Cero c2;

  pruebas++;
  a0.conecta1(&u1);
  a0.conecta2(&u1);
  {
    std::string espera = "Puerta OR (id=0) salida = 1\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n";
    std::string inf = a0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  a0.conecta1(&c2);
  {
    std::string espera = "   Puerta OR (id=0) salida = 1\n     Puerta CERO (id=2)\n     Puerta UNO (id=1)\n";
    std::string inf = a0.info(3);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  a0.conecta1(&u1);
  a0.conecta2(&c2);
  {
    std::string espera = " Puerta OR (id=0) salida = 1\n   Puerta UNO (id=1)\n   Puerta CERO (id=2)\n";
    std::string inf = a0.info(1);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  a0.conecta1(&c2);
  {
    std::string espera = "     Puerta OR (id=0) salida = 0\n       Puerta CERO (id=2)\n       Puerta CERO (id=2)\n";
    std::string inf = a0.info(5);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }



  // Resumen final
  if (fallos == 0)
    std::cout << "\n :-) Todas las " << pruebas << " pruebas correctas\n"
        << std::endl;
  else
    std::cout << "\n :-( Se han producido " << fallos << " FALLOs de "
        << pruebas << " pruebas (" << std::fixed <<  std::setprecision(2)
        << fallos*100.0/pruebas << "%)\n"
        << std::endl;
  return fallos;
}
