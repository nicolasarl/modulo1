// Autor: Alberto Hamilton

#define TITULO "Prueba clase Curva: prueba si es cerrada"

#include "Curva.hpp"
#include "Vector.hpp"
#include "Punto.hpp"
#include <iostream>
#include <cmath>  //necesario para el std::abs
#include <vector>
#include <iomanip>

#define EPS  (1e-6) //error máximo permitido al compara doubles

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<double> magXY { 10.9, 21.5, -21.0, -0.9, 9.2, 16.2, 10.9, 21.5,
      -7.9, -22.7, 26.9, 4.8, 10.9, 21.5, -30.0, -21.0, 1.8, -30.1,
      -3.3, -14.7, 10.9, 21.5};

  std::vector<double> magVec {-31.9, -22.4, 30.2, 17.1, 1.7, 5.3, -18.8, -44.2,
      34.8, 27.5, -16.0, 16.7, -40.9, -42.5, 31.8, -9.1, -5.1, 15.4,
      14.2, 36.2};
  std::vector<double> magLargo {
    38.9790969623464,
    73.6842838945616,
    79.2502519145919,
   127.2823245327915,
   171.6364675185374,
   194.7641565513829,
   253.7477135821351,
   286.8241402331505,
   303.0466554512047,
   341.9321283170449,
  };

  std::vector<std::string> toStringTeo {
    "Creada curva c[ p(10.9, 21.5), ]",
    "1 c[ p(10.9, 21.5), p(-21.0, -0.9), ]",
    "2 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), ]",
    "3 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), ]",
    "4 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), ]",
    "5 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), p(26.9, 4.8), ]",
    "6 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), p(26.9, 4.8), p(10.9, 21.5), ]",
    "7 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), p(26.9, 4.8), p(10.9, 21.5), p(-30.0, -21.0), ]",
    "8 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), p(26.9, 4.8), p(10.9, 21.5), p(-30.0, -21.0), p(1.8, -30.1), ]",
    "9 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), p(26.9, 4.8), p(10.9, 21.5), p(-30.0, -21.0), p(1.8, -30.1), p(-3.3, -14.7), ]",
    "10 c[ p(10.9, 21.5), p(-21.0, -0.9), p(9.2, 16.2), p(10.9, 21.5), p(-7.9, -22.7), p(26.9, 4.8), p(10.9, 21.5), p(-30.0, -21.0), p(1.8, -30.1), p(-3.3, -14.7), p(10.9, 21.5), ]",    
  };

  std::vector<bool> cerrada {false, false, true, false, false, true, false, false,
      false, true};

  unsigned nPruebas = magXY.size() / 2 -1;

  std::cout << "\nPruebas de construcción de curva:\n" << std::endl;

  Curva crv( Punto( magXY[0], magXY[1]) );
  std::cout << "Creada curva " << toStringTeo[0] << std::endl;

  for(unsigned i = 0; i<nPruebas; i++) {
    Punto nuevoPt( magXY[(i+1)*2], magXY[(i+1)*2+1]);
    Vector v( Punto(magVec[i*2], magVec[i*2+1]));
    double largo = magLargo[i];

    std::cout << "Añadimos punto " << nuevoPt.toString() << std::endl;
    crv.aniade( nuevoPt );
    std::cout << "La curva es ahora: " << toStringTeo[i + 1] << std::endl;

    pruebas++;
    if( crv.getNumTramos() != (i+1) )
      std::cout << "FALLO " << ++fallos << ": El número de tramos es "
          << crv.getNumTramos()
          <<" cuando se esperaba " << (i+1) << std::endl;

    pruebas++;
    if( crv.esCerrada()  != cerrada[i])
      std::cout << "FALLO " << ++fallos
          << ": Dice que la curva es cerrada " << crv.esCerrada()
          << " cuando se esperaba " << cerrada[i] << std::endl;

    pruebas++;
    double largoCal = crv.largo();
    if( std::abs(largoCal - largo)>EPS )
      std::cout << "FALLO " << ++fallos << ": El largo es "
          << largoCal <<" cuando se esperaba " << largo << std::endl;

    pruebas++;
    Punto ptI = crv.getPtoI(i+1);
    if( std::abs(ptI.getX() - nuevoPt.getX())>EPS
        || std::abs(ptI.getY() - nuevoPt.getY())>EPS ) {
      std::cout << "FALLO " << ++fallos << ": El punto " << i+1
        << " es " << ptI.toString() <<" cuando se esperaba "
        << nuevoPt.toString() << std::endl;
    }

    pruebas++;
    Vector vecI = crv.getVector(i);
    if( std::abs(vecI.getPtoFinal().getX() - v.getPtoFinal().getX())>EPS
        || std::abs(vecI.getPtoFinal().getY() - v.getPtoFinal().getY())>EPS
        ) {
      std::cout << "FALLO " << ++fallos << ": El vector " << i+1
          << " es " << vecI.toStringPt() <<" cuando se esperaba "
          << v.toStringPt() << std::endl;
    }
  }

  std::cout << "\nComenzamos a quitar puntos de la curva\n" << std::endl;

  for(unsigned i = crv.getNumTramos(); i>0; i--) {
    Punto ptUltimo( magXY[i*2], magXY[i*2+1]);
    Vector v( Punto(magVec[(i-1)*2], magVec[(i-1)*2+1]));
    double largo = magLargo[i-1];

    std::cout << "La curva es ahora: " << toStringTeo[i] << std::endl;

    pruebas++;
    if( crv.getNumTramos() != i )
      std::cout << "FALLO " << ++fallos << ": El número de tramos es "
          << crv.getNumTramos() <<" cuando se esperaba " << i << std::endl;

    pruebas++;
    if( crv.esCerrada()  != cerrada[i-1])
      std::cout << "FALLO " << ++fallos
          << ": Dice que la curva es cerrada " << crv.esCerrada()
          << " cuando se esperaba " << cerrada[i] << std::endl;

    pruebas++;
    double largoCal = crv.largo();
    if( std::abs(largoCal - largo)>EPS )
      std::cout << "FALLO " << ++fallos << ": El largo es "
          << largoCal <<" cuando se esperaba " << largo << std::endl;

    pruebas++;
    Punto ptI = crv.getPtoI(i);
    if( std::abs(ptI.getX() - ptUltimo.getX())>EPS
        || std::abs(ptI.getY() - ptUltimo.getY())>EPS ) {
      std::cout << "FALLO " << ++fallos << ": El punto " << i+1
          << " es " << ptI.toString() <<" cuando se esperaba "
          << ptUltimo.toString() << std::endl;
    }

    pruebas++;
    Vector vecI = crv.getVector(i-1);
    if( std::abs(vecI.getPtoFinal().getX() - v.getPtoFinal().getX())>EPS
        || std::abs(vecI.getPtoFinal().getY() - v.getPtoFinal().getY())>EPS
          ) {
      std::cout << "FALLO " << ++fallos << ": El vector " << i
        << " es " << vecI.toStringPt() << " cuando se esperaba "
        << v.toStringPt() << std::endl;
    }

    std::cout << "Quitamos ultimo tramo " << std::endl;
    crv.quitaUltimo();

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
