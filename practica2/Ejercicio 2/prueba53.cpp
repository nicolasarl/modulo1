// Autor: Alberto Hamilton Castro

#define TITULO "Probando los métodos Fijo pon0() y pon1()"

#include "Fijo.hpp"
#include <iostream>
#include <iomanip>

int main() {
  int pruebas = 0;
  int fallos = 0;

  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  Fijo f1;
  int salida, estado;

  pruebas++;
  f1.pon1();
  estado = 1;
  salida = f1.salida();
  if ( salida == estado )
    std::cout << "CORRECTO el estado es " << estado << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba " << estado
        <<" para la salida "
        << "pero devolvió " << salida << std::endl;

  pruebas++;
  f1.pon0();
  estado = 0;
  salida = f1.salida();
  if ( salida == estado )
    std::cout << "CORRECTO el estado es " << estado << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba " << estado
        <<" para la salida "
        << "pero devolvió " << salida << std::endl;

  pruebas++;
  f1.pon1();
  estado = 1;
  salida = f1.salida();
  if ( salida == estado )
    std::cout << "CORRECTO el estado es " << estado << std::endl;
  else
    std::cout << "FALLO " << ++fallos << ": se esparaba " << estado
        <<" para la salida "
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
