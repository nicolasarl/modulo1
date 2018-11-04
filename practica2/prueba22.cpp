// Autor: Alberto Hamilton

#define TITULO "Prueba clase Curva: Añadiendo y quitando vectores"

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

  std::vector<double> magXY {  -19.6 ,-15.0 ,-2.2 ,23.8 ,-9.2 ,-20.7 ,-19.6 ,
      -15.0 ,23.9 ,6.3 ,4.9 ,19.2 ,-19.6 ,-15.0 ,-22.2 ,-10.0 ,-6.4 ,
      -4.6 ,12.9 ,19.1 ,-19.6 ,-15.0};

  std::vector<double> magPol {
    42.52293498807438,    65.84597856953324,
    45.04719747109691,   -98.93956500315153,
    11.85959527134042,   151.27386933469566,
    48.43490476918480,    26.08891992543614,
    22.96540877058364,   145.82555940408014,
    42.07006061321994,  -125.61683742593063,
     5.63560112144215,   117.47443162627711,
    16.69730517179344,    18.86899945506142,
    30.56435832796102,    50.84248926619163,
    47.10689970694315,  -133.62378953743340,
  };

  std::vector<double> magLargo {
    42.5229349880744,
    87.5701324591713,
    99.4297277305117,
   147.8646324996965,
   170.8300412702802,
   212.9001018835001,
   218.5357030049422,
   235.2330081767357,
   265.7973665046967,
   312.9042662116398,
  };
      
  std::vector<std::string> toStringTeo {
    "c[ p(-19.6, -15.0), ]",
    "1 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), ]",
    "2 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), ]",
    "3 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), ]",
    "4 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), ]",
    "5 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), vp(-19.0, 12.9), ]",
    "6 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), vp(-19.0, 12.9), vp(-24.5, -34.2), ]",
    "7 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), vp(-19.0, 12.9), vp(-24.5, -34.2), vp(-2.6, 5.0), ]",
    "8 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), vp(-19.0, 12.9), vp(-24.5, -34.2), vp(-2.6, 5.0), vp(15.8, 5.4), ]",
    "9 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), vp(-19.0, 12.9), vp(-24.5, -34.2), vp(-2.6, 5.0), vp(15.8, 5.4), vp(19.3, 23.7), ]",
    "10 tramos c[ p(-19.6, -15.0), vp(17.4, 38.8), vp(-7.0, -44.5), vp(-10.4, 5.7), vp(43.5, 21.3), vp(-19.0, 12.9), vp(-24.5, -34.2), vp(-2.6, 5.0), vp(15.8, 5.4), vp(19.3, 23.7), vp(-32.5, -34.1), ]",
  };

  unsigned nPruebas = magXY.size() / 2 -1;

  std::cout << "\nPruebas de construcción de curva:\n" << std::endl;

  Curva crv( Punto( magXY[0], magXY[1]) );
  std::cout << "Creada curva " << toStringTeo[0] << std::endl;

  for(unsigned i = 0; i<nPruebas; i++) {

    Vector nuevoV( magPol[i*2], magPol[i*2+1] );
    Punto pt( magXY[(i+1)*2], magXY[(i+1)*2+1]);
    double largo = magLargo[i];

    std::cout << "Añadimos vector " << nuevoV.toString() << std::endl;
    crv.aniade( nuevoV );
    std::cout << "La curva es ahora: " << toStringTeo[i + 1] << std::endl;

    pruebas++;
    if( crv.getNumTramos() != (i+1) )
      std::cout << "FALLO " << ++fallos << ": El número de tramos es "
          << crv.getNumTramos() <<" cuando se esperaba " << (i+1) << std::endl;

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
    if( std::abs(ptI.getX() - pt.getX())>EPS
        || std::abs(ptI.getY() - pt.getY())>EPS ) {
      std::cout << "FALLO " << ++fallos << ": El punto " << i+1
          << " es " << ptI.toString() <<" cuando se esperaba "
          << pt.toString() << std::endl;
    }

    pruebas++;
    Vector vecI = crv.getVector(i);
    if( std::abs(vecI.getPtoFinal().getX() - nuevoV.getPtoFinal().getX())>EPS
        || std::abs(vecI.getPtoFinal().getY() - nuevoV.getPtoFinal().getY())>EPS
        ) {
      std::cout << "FALLO " << ++fallos << ": El vector " << i+1
        << " es " << vecI.toStringPt() <<" cuando se esperaba "
        << nuevoV.toStringPt() << std::endl;
    }
  }

  std::cout << "\nComenzamos a quitar puntos de la curva\n" << std::endl;

  for(unsigned i = crv.getNumTramos(); i>0; i--) {
    Punto ptUltimo( magXY[i*2], magXY[i*2+1]);
    Vector v( magPol[(i-1)*2], magPol[(i-1)*2+1] );
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
          << " es " << vecI.toStringPt() <<" cuando se esperaba "
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
