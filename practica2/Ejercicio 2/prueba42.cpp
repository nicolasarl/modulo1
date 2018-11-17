// Autor: Alberto Hamilton Castro

#define TITULO "Probando tabla de verdad de Or precediada 2 And"

#include "And.hpp"
#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int fallos = 0;
int pruebas = 0;

Or o0;
And a1;
And a2;
Uno uno;
Cero cero;

void comprueba(int A, int B, int C, int D, int espera) {

  //conectamos la entrada según A, B, C y D
  a1.conecta1( A ? (Puerta*)&uno : (Puerta*)&cero );
  a1.conecta2( B ? (Puerta*)&uno : (Puerta*)&cero );
  a2.conecta1( C ? (Puerta*)&uno : (Puerta*)&cero );
  a2.conecta2( D ? (Puerta*)&uno : (Puerta*)&cero );

  pruebas++;
  int salida = o0.salida();
  std::cout << "Caso " << A << B << C << D << " = " << salida;
  std::cout << " salida correcta " << espera;
  if ( salida == espera)
    std::cout << " CORRECTO " << std::endl;
  else {
    std::cout << " FALLO" << std::endl;
    std::cout << o0.info();
    fallos++;
  }

}

int main() {

  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  o0.conecta1(&a1);
  o0.conecta2(&a2);

  //especificamos tabla de verdad
  comprueba(0,0,0,0,0);
  comprueba(0,0,0,1,0);
  comprueba(0,0,1,0,0);
  comprueba(0,0,1,1,1);
  comprueba(0,1,0,0,0);
  comprueba(0,1,0,1,0);
  comprueba(0,1,1,0,0);
  comprueba(0,1,1,1,1);
  comprueba(1,0,0,0,0);
  comprueba(1,0,0,1,0);
  comprueba(1,0,1,0,0);
  comprueba(1,0,1,1,1);
  comprueba(1,1,0,0,1);
  comprueba(1,1,0,1,1);
  comprueba(1,1,1,0,1);
  comprueba(1,1,1,1,1);

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
