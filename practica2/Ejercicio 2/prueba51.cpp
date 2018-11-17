// Autor: Alberto Hamilton Castro

#define TITULO "Probamndo método Fijo.pon1()"

#include "Fijo.hpp"
#include <iostream>
#include <iomanip>

int main() {
  int pruebas = 0;
  int fallos = 0;

  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  pruebas++;
  Fijo f1;
  f1.pon1();
  int salida = f1.salida();

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
