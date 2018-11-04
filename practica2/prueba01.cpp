// Autor: Alberto Hamilton

#define TITULO "Prueba clase Punto: getX() y getY()"


#include "Punto.hpp"
#include <iostream>
#include <vector>
#include <iomanip>


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<double> valPrueba { 
      1.3, 5.5,  -2.8, 1.35,  115.2, -88.9,  -25.8, -33.5 
  };

  int nPruebas = valPrueba.size()/2;
  for( int i = 0; i<nPruebas; i++) {
    double x1 = valPrueba[i * 2];
    double y1 = valPrueba[i * 2 + 1];

    Punto p1(x1,y1);

    std::cout << "Considerando punto (" << x1 << "," << y1 << ")" << std::endl;

    pruebas++;
    double x1g = p1.getX();
    if( x1 != x1g )
      std::cout << "FALLO " << ++fallos << ": Coordenada X de p1 es "
          << x1g <<" cuando se esperaba " << x1 << std::endl;

    pruebas++;
    double y1g = p1.getY();
    if( y1 != y1g )
      std::cout << "FALLO " << ++fallos << ": Coordenada Y de p1 es "
          << y1g <<" cuando se esperaba " << y1 << std::endl;

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
