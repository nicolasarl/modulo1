// Autor: Alberto Hamilton Castro

#define TITULO "Probando salida() de Cero"

#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Cero c1;

  pruebas++;
  int salida = c1.salida();
  if ( salida == 0 )
    std::cout << "CORRECTO el estado es 0" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba 0 para la salida "
        << "pero devolvió " << salida << std::endl;

  Cero c2;

  pruebas++;
  salida = c2.salida();
  if ( salida == 0 )
    std::cout << "CORRECTO el estado es 1" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba 0 para la salida "
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
