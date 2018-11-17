// Autor: Alberto Hamilton Castro

#define TITULO "Probando circuito con Fijo"

#include "Or.hpp"
#include "And.hpp"
#include "Not.hpp"
#include "Fijo.hpp"

#include <iostream>
#include <iomanip>

int fallos = 0;
int pruebas = 0;

Or o0;
And a1;
Not n2;

Fijo f3, f4, f5;

void comprueba(int A, int B, int C, int espera) {

  if (A) f3.pon1(); else f3.pon0();
  if (B) f4.pon1(); else f4.pon0();
  if (C) f5.pon1(); else f5.pon0();

  pruebas++;
  int salida = o0.salida();
  std::cout << "Caso " << A << B << C << " = " << salida;
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
  o0.conecta2(&n2);

  a1.conecta1(&f3);
  a1.conecta2(&f4);

  n2.conecta1(&f5);

  //especificamos tabla de verdad
  comprueba(0,0,0,1);
  comprueba(0,1,0,1);
  comprueba(0,1,1,0);
  comprueba(1,0,0,1);
  comprueba(1,1,0,1);
  comprueba(1,1,1,1);

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
