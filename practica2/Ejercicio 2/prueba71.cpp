// Autor: Alberto Hamilton Castro
// Fichero de prueba AndM

#define TITULO "Probando AndM: conexiones sucesivas"

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
  {
    int espera = 9;
    int salida = am0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
  }

  pruebas++;
  am0.conecta(&u1);
  {
    int espera = 9;
    int salida = am0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
  }

  pruebas++;
  am0.conecta(&u1);
  {
    int espera = 1;
    int salida = am0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
  }

  pruebas++;
  am0.conecta(&c2);
  {
    int espera = 0;
    int salida = am0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
  }

  pruebas++;
  am0.conecta(&u1);
  {
    int espera = 0;
    int salida = am0.salida();
    if ( salida == espera )
      std::cout << "CORRECTO la salida es " << espera << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba "<< espera << " para la salida "
          << "pero devolvió " << salida << std::endl;
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
