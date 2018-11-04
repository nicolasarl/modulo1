// Autor: Alberto Hamilton

#define TITULO "prueba los contructores de copia en todas las clases"

#include "Curva.hpp"
#include "Vector.hpp"
#include "Punto.hpp"
#include <iostream>
#include <cmath>  //necesario para el std::abs
#include <iomanip>

#define EPS  (1e-6) //error máximo permitido al compara doubles



int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  std::cout << "Comenzamos las pruebas" << std::endl;

  Punto p1(-3,1.5), p2(5.18, 9.10);

  Punto p3(p1);
  Punto p4(p2);

  std::cout << "El punto p1 es " << p1 << std::endl;
  std::cout << "El punto p3 es " << p3 << std::endl;

  pruebas++;
  if( (p1.getX() != p3.getX()) || (p1.getY() != p3.getY()))
    std::cout << "FALLO " << ++fallos << ":"
      << " punto p1 es distinto de su copia" << std::endl;


  std::cout << "\nEl punto p2 es " << p2 << std::endl;
  std::cout << "El punto p4 es " << p4 << std::endl;

  pruebas++;
  if( (p2.getX() != p4.getX()) || (p2.getY() != p4.getY()))
    std::cout << "FALLO " << ++fallos << ":"
      << " punto p2 es distinto de su copia" << std::endl;


  std::vector<double> magXY { 2.1, -4.5, -3.0,  0.5, -1.6, -2.5, -1.1, -0.0,
      3.9, -1.7, -1.7,  0.4, -0.9, -4.2};
  int nPruebas = magXY.size() / 2;

  for( int i = 0; i<nPruebas; i++) {
    double x = magXY[i*2], y = magXY[i*2+1];

    Vector v( Punto(x,y) );
    Vector vCopia( v );

    std::cout << "Vector creado es " << v
        << " y su copia " << vCopia << std::endl;

    pruebas++;
    if( (v.getModulo() != vCopia.getModulo())
        || (v.getAngulo() != vCopia.getAngulo()))
      std::cout << "FALLO " << ++fallos << ":"
          << " vector es distinto de su copia" << std::endl;
  }

  std::vector<double> XY1 { -12.3, -18.6, -38., -33.5, 15.4, 31.5, -30.7, 16.7,
      -0.3, -22.0 };
  int nPtos = XY1.size() / 2;
  Curva c1( Punto(XY1[0],XY1[1]) );
  for( int i=1; i<nPtos; i++)
    c1.aniade( Punto( XY1[i*2], XY1[i*2+1]) );

  Curva cCopia(c1);
  std::cout << "Curva 1 es: " << c1
      << "\n  y su copia " <<  cCopia
      << std::endl;

  int ntramosC1 = c1.getNumTramos();
  double largoC1 = c1.largo();

  pruebas++;
  if ( ntramosC1 != cCopia.getNumTramos() )
      std::cout << "FALLO " << ++fallos << ":"
          << " número tramos curva c1 distinto de su copia" << std::endl;

  pruebas++;
  if ( largoC1 != cCopia.largo() )
      std::cout << "FALLO " << ++fallos << ":"
          << " largo curva c1 distinto de su copia" << std::endl;

  for( int i = 0; i < c1.getNumTramos(); i++) {
    Punto ptoc1 = c1.getPtoI(i);
    Punto ptoc2 = cCopia.getPtoI(i);
    pruebas++;
    if ( (ptoc1.getX() != ptoc2.getX()) || (ptoc1.getY() != ptoc2.getY()))
      std::cout << "FALLO " << ++fallos << ":"
          << " punto " << i << " de la  curva c1 distinto de su copia"
          << std::endl;
  }


  //Los cambios en cCopia no deben afectar a c1
  for( int i = 0; i < cCopia.getNumTramos(); i++) {
    cCopia.quitaUltimo();
    pruebas++;
    if ( (ntramosC1 != c1.getNumTramos()) || (largoC1 != c1.largo())) {
      std::cout << "FALLO " << ++fallos << ":"
          << " la curva c1 afectada al cambiar su copia" << std::endl;
    }
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
