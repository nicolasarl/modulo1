// Autor: Alberto Hamilton Castro

#define TITULO "Probando salida() de Uno"

#include "Uno.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Uno u1;

  pruebas++;
  int salida = u1.salida();
  if ( salida == 1 )
    std::cout << "CORRECTO el estado es 1" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba 1 para la salida "
        << "pero devolvió " << salida << std::endl;

  Uno u2;

  pruebas++;
  salida = u2.salida();
  if ( salida == 1 )
    std::cout << "CORRECTO el estado es 1" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba 1 para la salida "
        << "pero devolvió " << salida << std::endl;


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
