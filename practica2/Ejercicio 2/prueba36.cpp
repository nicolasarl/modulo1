// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() Or transmite ND"

#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"
#include "Not.hpp"

#include <string>
#include <iostream>
#include <iomanip>

int fallos = 0;
int pruebas = 0;

Or o0;
Uno uno;
Cero cero;
Not n3;
Not n4;

void comprueba(int A, int B, std::string esperado) {

  //conectamos la entrada según A y B
  if (A != 9)
    n3.conecta1( A ? (Puerta*)&uno : (Puerta*)&cero );
  if (B != 9)
    n4.conecta1( B ? (Puerta*)&uno : (Puerta*)&cero );

  pruebas++;
  std::string inf = o0.info();
  if (inf == esperado)
    std::cout << "\nCORRECTO info() devuelve \n'" << inf << "'" << std::endl;
  else
    std::cout << "\nFALLO " << ++fallos << ": se esperaba \n'"<< esperado
        << "' pero info() devolvió \n'" << inf << "'" << std::endl;

}

int main() {

  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::string esperado;


  //especificamos tabla de verdad
  o0.conecta1(&n3);
  o0.conecta2(&n4);
  esperado = "Puerta OR (id=0) salida = 9\n  Puerta NOT (id=3) salida = 9\n    NO CONECTADA\n  Puerta NOT (id=4) salida = 9\n    NO CONECTADA\n";
  comprueba(9,9,esperado);

  esperado = "Puerta OR (id=0) salida = 9\n  Puerta NOT (id=3) salida = 9\n    NO CONECTADA\n  Puerta NOT (id=4) salida = 1\n    Puerta CERO (id=2)\n";
  comprueba(9,0,esperado);

  o0 = Or();
  n3 = Not();
  n4 = Not();

  o0.conecta1(&n3);
  o0.conecta2(&n4);
  esperado = "Puerta OR (id=5) salida = 9\n  Puerta NOT (id=6) salida = 9\n    NO CONECTADA\n  Puerta NOT (id=7) salida = 9\n    NO CONECTADA\n";
  comprueba(9,9,esperado);

  esperado = "Puerta OR (id=5) salida = 9\n  Puerta NOT (id=6) salida = 1\n    Puerta CERO (id=2)\n  Puerta NOT (id=7) salida = 9\n    NO CONECTADA\n";
  comprueba(0,9,esperado);

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
