// Autor: Alberto Hamilton Castro

#define TITULO "Probando tabla de verdad de And precediada 2 Or"

#include "And.hpp"
#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"

#include <iostream>
#include <iomanip>

int fallos = 0;
int pruebas = 0;

And a0;
Or o1;
Or o2;
Uno uno;
Cero cero;

void comprueba(int A, int B, int C, int D, int espera) {

  //conectamos la entrada según A, B, C y D
  o1.conecta1( A ? (Puerta*)&uno : (Puerta*)&cero );
  o1.conecta2( B ? (Puerta*)&uno : (Puerta*)&cero );
  o2.conecta1( C ? (Puerta*)&uno : (Puerta*)&cero );
  o2.conecta2( D ? (Puerta*)&uno : (Puerta*)&cero );

  pruebas++;
  int salida = a0.salida();
  std::cout << "Caso " << A << B << C << D << " = " << salida;
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

  a0.conecta1(&o1);
  a0.conecta2(&o2);

  //especificamos tabla de verdad
  comprueba(0,0,0,0,0);
  comprueba(0,0,0,1,0);
  comprueba(0,0,1,0,0);
  comprueba(0,0,1,1,0);
  comprueba(0,1,0,0,0);
  comprueba(0,1,0,1,1);
  comprueba(0,1,1,0,1);
  comprueba(0,1,1,1,1);
  comprueba(1,0,0,0,0);
  comprueba(1,0,0,1,1);
  comprueba(1,0,1,0,1);
  comprueba(1,0,1,1,1);
  comprueba(1,1,0,0,0);
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
