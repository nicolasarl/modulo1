// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() de Or no conectada"

#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Or o0;
  Uno u1;
  Cero c2;

  pruebas++;
  {
    std::string espera = "Puerta OR (id=0) salida = 9\n  NO CONECTADA\n  NO CONECTADA\n";
    std::string inf = o0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  o0.conecta1(&u1);
  {
    std::string espera = "   Puerta OR (id=0) salida = 9\n     Puerta UNO (id=1)\n     NO CONECTADA\n";
    std::string inf = o0.info(3);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  Or o3;
  pruebas++;
  {
    std::string espera = "       Puerta OR (id=3) salida = 9\n         NO CONECTADA\n         NO CONECTADA\n";
    std::string inf = o3.info(7);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  o3.conecta2(&u1);
  {
    std::string espera = "   Puerta OR (id=3) salida = 9\n     NO CONECTADA\n     Puerta UNO (id=1)\n";
    std::string inf = o3.info(3);
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
