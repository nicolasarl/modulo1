// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() de And no conectada"

#include "And.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  And a0;
  Uno u1;
  Cero c2;

  pruebas++;
  {
    std::string espera = "Puerta AND (id=0) salida = 9\n  NO CONECTADA\n  NO CONECTADA\n";
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
    std::string espera = "   Puerta AND (id=0) salida = 9\n     Puerta CERO (id=2)\n     NO CONECTADA\n";
    std::string inf = a0.info(3);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  And a3;
  pruebas++;
  {
    std::string espera = "       Puerta AND (id=3) salida = 9\n         NO CONECTADA\n         NO CONECTADA\n";
    std::string inf = a3.info(7);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  a3.conecta2(&c2);
  {
    std::string espera = " Puerta AND (id=3) salida = 9\n   NO CONECTADA\n   Puerta CERO (id=2)\n";
    std::string inf = a3.info(1);
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
