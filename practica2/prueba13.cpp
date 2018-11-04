// Autor: Alberto Hamilton

#define TITULO "Prueba clase Vector: a partir de dos puntos"

#include "Vector.hpp"
#include "Punto.hpp"
#include <iostream>
#include <cmath>  //necesario para el std::abs
#include <iomanip>
#include <vector>

#define EPS  (1e-6) //error máximo permitido al compara doubles


int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::vector<double> magXY2 { 3.3, 8.6, -8.1, -7.9, 3.9, -1.4, 3.2, -8.9, -1.0,
        -9.0, -7.7, -0.1, -9.1, 1.1, 6.7, 4.8, -9.0, -9.3, -7.1,
        -1.1, 2.8, 2.0, -1.8, -6.1, -10.0, 2.7, 5.9, -9.3};
  std::vector<double> magXY { -11.4, -16.5, -0.7, -7.5, -6.7, 8.9, 15.8,
        3.7, 1.9, 8.2, -4.6, -8.1, 15.9, -12.0};

  std::vector<double> magPol {
    20.05517389602992,  -124.64094751191629,
     7.53259583410659,   -95.33215888165957,
    11.14001795330690,   126.97276248956804,
    16.22744588652201,    13.17986808938100,
     8.41724420460759,    76.95436293705140,
     9.31504159947770,  -119.59229635935799,
    19.92009036124083,   -37.04247477308286,
  };
     
  int nPruebas = magPol.size() / 2;


  std::cout << "\nPruebas de dos ptos a pto final y (magnitud,ángulo) \n" 
      << std::endl;
  for( int i = 0; i<nPruebas; i++) {
    double x1 = magXY2[i*4], y1 = magXY2[i*4+1];
    double x2 = magXY2[i*4+2], y2 = magXY2[i*4+3];
    double x = magXY[i*2], y = magXY[i*2+1];
    double rho = magPol[i*2], tita = magPol[i*2+1];

    Punto p1(x1, y1), p2(x2, y2);
    Vector v(p1, p2);

    std::cout << "Vector creado es x1=" << x1 << " y1=" << y1
        << " x2=" << x2 << " y2=" << y2 << std::endl;

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
