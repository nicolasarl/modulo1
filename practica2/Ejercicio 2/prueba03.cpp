// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() de Uno"

#include "Uno.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  {
    Uno u1;

    pruebas++;
    std::string espera = "Puerta UNO (id=0)\n";
    std::string inf = u1.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info '" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta '"
          << espera << "' pero devolvió '" << inf << "'" << std::endl;
  }

  {
    Uno u1;

    pruebas++;
    std::string espera = " Puerta UNO (id=1)\n";
    std::string inf = u1.info(1);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info '" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta '"
          << espera << "' pero devolvió '" << inf << "'" << std::endl;
  }

  {
    Uno u1;

    pruebas++;
    std::string espera = "    Puerta UNO (id=2)\n";
    std::string inf = u1.info(4);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info '" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta '"
          << espera << "' pero devolvió '" << inf << "'" << std::endl;
  }

  {
    Uno u1;

    pruebas++;
    std::string espera = "          Puerta UNO (id=3)\n";
    std::string inf = u1.info(10);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info '" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta '"
          << espera << "' pero devolvió '" << inf << "'" << std::endl;
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
