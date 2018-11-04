// Autor: Alberto Hamilton

#define TITULO "Prueba clase Punto: toString()"


#include "Punto.hpp"
#include <iostream>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;


  {
    pruebas++;
    Punto p1(1.3,5.5);
    std::string tsP1_teorico = "p(1.3, 5.5)";

    std::cout << "Probando " << tsP1_teorico << std::endl;

    std::string tsP1 = p1.toString();

    if ( tsP1 != tsP1_teorico )
      std::cout << "FALLO: " << ++fallos << " toString ha devuelto '"
          << tsP1 <<"' cuando se esperaba '" << tsP1_teorico << "'"
          << std::endl;
  }

  {
    pruebas++;
    Punto p1(-2.81, 1.35);
    std::string tsP1_teorico = "p(-2.8, 1.4)";

    std::cout << "Probando " << tsP1_teorico << std::endl;

    std::string tsP1 = p1.toString();

    if ( tsP1 != tsP1_teorico )
      std::cout << "FALLO: " << ++fallos << " toString ha devuelto '"
          << tsP1 <<"' cuando se esperaba '" << tsP1_teorico << "'"
          << std::endl;
  }

  {
    pruebas++;
    Punto p1(-115.21, -88.87);
    std::string tsP1_teorico = "p(-115.2, -88.9)";

    std::cout << "Probando " << tsP1_teorico << std::endl;

    std::string tsP1 = p1.toString();

    if ( tsP1 != tsP1_teorico )
      std::cout << "FALLO: " << ++fallos << " toString ha devuelto '"
          << tsP1 <<"' cuando se esperaba '" << tsP1_teorico << "'"
          << std::endl;
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
