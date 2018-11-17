// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() de la puerta Fijo"

#include "Fijo.hpp"
#include <iostream>
#include <iomanip>


int main() {
  int pruebas = 0;
  int fallos = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::string infoStr;
  std::string esperado;

  Fijo f1;

  f1.pon1();
  infoStr = f1.info();
  esperado = "Puerta FIJO (id=0) salida = 1\n";
  pruebas++;
  if (infoStr == esperado)
    std::cout << "CORRECTO info() devuelve \n'\n" << infoStr << "'" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << " se esparaba \n'\n"<< esperado
        << "' pero info() devolvió \n'\n" << infoStr << "'" << std::endl;

  f1.pon0();
  infoStr = f1.info(5);
  esperado = "     Puerta FIJO (id=0) salida = 0\n";
  pruebas++;
  if (infoStr == esperado)
    std::cout << "CORRECTO info() devuelve \n'\n" << infoStr << "'" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << " se esparaba \n'\n"<< esperado
        << "' pero info() devolvió \n'\n" << infoStr << "'" << std::endl;

  Fijo f2;
  f2.pon0();
  infoStr = f2.info(7);
  esperado = "       Puerta FIJO (id=1) salida = 0\n";
  pruebas++;
  if (infoStr == esperado)
    std::cout << "CORRECTO info() devuelve \n'\n" << infoStr << "'" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << " se esparaba \n'\n"<< esperado
        << "' pero info() devolvió \n'\n" << infoStr << "'" << std::endl;

  Fijo f3;
  f3.pon1();
  infoStr = f3.info(3);
  esperado = "   Puerta FIJO (id=2) salida = 1\n";
  pruebas++;
  if (infoStr == esperado)
    std::cout << "CORRECTO info() devuelve \n'\n" << infoStr << "'" << std::endl;
  else
    std::cout << "FALLO " << ++fallos << " se esparaba \n'\n"<< esperado
        << "' pero info() devolvió \n'\n" << infoStr << "'" << std::endl;


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
