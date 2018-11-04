// Autor: Alberto Hamilton

#define TITULO "Prueba clase Curva: Añadiendo y quitando puntos"

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

  std::vector<double> magXY { 23.8, 29.4, 7.0, 7.9, 7.6, -27.1, -15.8, -13.1,
      -3.1, -17.8, -9.3, -1.2, -22.1, 26.1, 22.0, -22.1, -25.7, -22.0,
      20.5, -25.4};

  std::vector<double> magVec {-16.8, -21.5, 0.6, -35.0, -23.4, 14.0, 12.7, -4.7,
      -6.2, 16.6, -12.8, 27.3, 44.1, -48.2, -47.7, 0.1, 46.2, -3.4};
  std::vector<double> magLargo {
    27.2853440513401,
    62.2904865306959,
    89.5587831404953,
   103.1005703194463,
   120.8206154661156,
   150.9723981663143,
   216.3027127224222,
   264.0028175441099,
   310.3277568317118,
  };

  
  std::vector<std::string> toStringTeo {
    "Creada curva c[ p(23.8, 29.4), ]",
    "1 tramos c[ p(23.8, 29.4), p(7.0, 7.9), ]",
    "2 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), ]",
    "3 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), ]",
    "4 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), ]",
    "5 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), ]",
    "6 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), ]",
    "7 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), p(22.0, -22.1), ]",
    "8 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), p(22.0, -22.1), p(-25.7, -22.0), ]",
    "9 tramos c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), p(22.0, -22.1), p(-25.7, -22.0), p(20.5, -25.4), ]",
  };
  
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
    if( crv.esCerrada() )
      std::cout << "FALLO " << ++fallos
          << ": Dice que la curva es cerrada cuando no lo es " << std::endl;

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

  for(unsigned i = crv.getNumTramos(); i > 0; i--) {
    Punto ptUltimo( magXY[i*2], magXY[i*2+1]);
    Vector v( Punto(magVec[(i-1)*2], magVec[(i-1)*2+1]));
    double largo = magLargo[i-1];

    std::cout << "La curva es ahora: " << toStringTeo[i] << std::endl;

    pruebas++;
    if( crv.getNumTramos() != i )
      std::cout << "FALLO " << ++fallos << ": El número de tramos es "
          << crv.getNumTramos() <<" cuando se esperaba " << i << std::endl;

    pruebas++;
    if( crv.esCerrada() )
      std::cout << "FALLO " << ++fallos
          << ": Dice que la curva es cerrada cuando no lo es " << std::endl;

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
