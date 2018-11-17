// Autor: Alberto Hamilton Castro
// Fichero de prueba AndM

#define TITULO "Probando AndM: info() conexiones con índice existente"

#include "AndM.hpp"
#include "Uno.hpp"
#include "Cero.hpp"
#include <iostream>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  AndM am0;
  Uno u1;
  Cero c2;
  
  pruebas++;
  am0.conecta(&u1);
  am0.conecta(&u1);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 1\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&c2,0);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 0\n  Puerta CERO (id=2)\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&c2,1);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 0\n  Puerta CERO (id=2)\n  Puerta CERO (id=2)\n";
    std::string inf = am0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  am0.conecta(&u1, 0);
  am0.conecta(&u1, 1);
  {
    std::string espera = "Puerta ANDM (id=0) salida = 1\n  Puerta UNO (id=1)\n  Puerta UNO (id=1)\n";
    std::string inf = am0.info();
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
