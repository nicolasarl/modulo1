// Autor: Alberto Hamilton Castro

#define TITULO "Probando And transmite ND"

#include "And.hpp"
#include "Uno.hpp"
#include "Cero.hpp"
#include "Not.hpp"

#include <iostream>
#include <iomanip>

int fallos = 0;
int pruebas = 0;

And a0;
Uno uno;
Cero cero;
Not n3;
Not n4;

void comprueba(int A, int B, int espera) {

  //conectamos la entrada según A y B
  if (A != 9)
    n3.conecta1( A ? (Puerta*)&uno : (Puerta*)&cero );
  if (B != 9)
    n4.conecta1( B ? (Puerta*)&uno : (Puerta*)&cero );

  pruebas++;
  int salida = a0.salida();
  std::cout << "Caso " << A << B << " = " << salida;
  std::cout << " salida correcta " << espera;
  if ( salida == espera)
    std::cout << " CORRECTO " << std::endl;
  else {
    std::cout << " FALLO" << std::endl;
    std::cout << a0.info();
    fallos++;
  }

}

int main() {

  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;


  //especificamos tabla de verdad
  a0.conecta1(&n3);
  a0.conecta2(&n4);
  comprueba(9,9,9);

  comprueba(9,0,9);

  a0 = And();
  n3 = Not();
  n4 = Not();

  a0.conecta1(&n3);
  a0.conecta2(&n4);
  comprueba(9,9,9);

  comprueba(0,9,9);

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
