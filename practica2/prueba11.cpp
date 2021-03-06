// Autor: Alberto Hamilton

#define TITULO "Prueba clase Vector: rectangulares <-> polares simples"

#include "Vector.hpp"
#include "Punto.hpp"
#include <iostream>
#include <vector>
#include <cmath>  //necesario para el std::abs
#include <iomanip>

#define EPS  (1e-6) //error máximo permitido al compara doubles

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;


  std::vector<double> magPol { 1, 0, 1, 90, 1, -90, 1, 180, 1, 180 };
  std::vector<double> magXY { 1, 0, 0, 1, 0, -1, -1, 0, -1, 0 };

  int nPruebas = magPol.size() / 2;

  std::cout << "\nPruebas de (magnitud,ángulo) a punto final" << std::endl;
  for( int i = 0; i<nPruebas; i++) {
    double x = magXY[i*2], y = magXY[i*2+1];
    double rho = magPol[i*2], tita = magPol[i*2+1];

    Vector v(rho, tita);
    std::cout << "Vector creado es rho=" << rho << " tita=" << tita << std::endl;

    pruebas++;
    double rhoGet = v.getModulo();
    if( std::abs(rho - rhoGet)>EPS )
      std::cout << "FALLO " << ++fallos << ": Magnitud de v es "
          << rhoGet <<" cuando se esperaba " << rho << std::endl;

    pruebas++;
    double titaGet = v.getAngulo();
    if( std::abs(tita - titaGet)>EPS && std::abs(tita - titaGet + 360)>EPS && 
        std::abs(tita - titaGet - 360)>EPS )
      std::cout << "FALLO " << ++fallos << ": Ángulo de v es "
          << titaGet <<" cuando se esperaba " << tita << std::endl;

    pruebas++;
    double xGet = v.getPtoFinal().getX();
    if( std::abs(x - xGet)>EPS )
      std::cout << "FALLO " << ++fallos << ": Magnitud de X es "
          << xGet <<" cuando se esperaba " << x << std::endl;

    pruebas++;
    double yGet = v.getPtoFinal().getY();
    if( std::abs(y - yGet)>EPS )
      std::cout << "FALLO " << ++fallos << ": Magnitud de Y es "
          << yGet <<" cuando se esperaba " << y << std::endl;

  }


  std::cout << "\nPruebas de pto final a (magnitud,ángulo) " << std::endl;
  for( int i = 0; i<nPruebas; i++) {
    double x = magXY[i*2], y = magXY[i*2+1];
    double rho = magPol[i*2], tita = magPol[i*2+1];

    Punto ptoFinal(x, y);

    Vector v(ptoFinal);
    std::cout << "Vector creado es x = " << x << " y=" << y << std::endl;


    pruebas++;
    double xGet = v.getPtoFinal().getX();
    if( std::abs(x - xGet)>EPS )
      std::cout << "FALLO " << ++fallos << ": Magnitud de X es "
          << xGet <<" cuando se esperaba " << x << std::endl;

    pruebas++;
    double yGet = v.getPtoFinal().getY();
    if( std::abs(y - yGet)>EPS )
      std::cout << "FALLO " << ++fallos << ": Magnitud de Y es "
          << yGet <<" cuando se esperaba " << y << std::endl;


    pruebas++;
    double rhoGet = v.getModulo();
    if( std::abs(rho - rhoGet)>EPS )
      std::cout << "FALLO " << ++fallos << ": Magnitud de v es "
          << rhoGet <<" cuando se esperaba " << rho << std::endl;

    pruebas++;
    double titaGet = v.getAngulo();
    if( std::abs(tita - titaGet)>EPS && std::abs(tita - titaGet + 360)>EPS && 
        std::abs(tita - titaGet - 360)>EPS )
      std::cout << "FALLO " << ++fallos << ": Ángulo de v es "
          << titaGet <<" cuando se esperaba " << tita << std::endl;
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
