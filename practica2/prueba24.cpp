// Autor: Alberto Hamilton

#define TITULO "Prueba clase Curva: salida de toStringPt y toStringVec"

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

  const std::vector<std::string> ts_teo {
    "c[ p(23.8, 29.4), p(7.0, 7.9)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0), vp(12.7, -4.7)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0), vp(12.7, -4.7), vp(-6.2, 16.6)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0), vp(12.7, -4.7), vp(-6.2, 16.6), vp(-12.8, 27.3)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), p(22.0, -22.1)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0), vp(12.7, -4.7), vp(-6.2, 16.6), vp(-12.8, 27.3), vp(44.1, -48.2)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), p(22.0, -22.1), p(-25.7, -22.0)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0), vp(12.7, -4.7), vp(-6.2, 16.6), vp(-12.8, 27.3), vp(44.1, -48.2), vp(-47.7, 0.1)",
    "c[ p(23.8, 29.4), p(7.0, 7.9), p(7.6, -27.1), p(-15.8, -13.1), p(-3.1, -17.8), p(-9.3, -1.2), p(-22.1, 26.1), p(22.0, -22.1), p(-25.7, -22.0), p(20.5, -25.4)",
    "c[ p(23.8, 29.4), vp(-16.8, -21.5), vp(0.6, -35.0), vp(-23.4, 14.0), vp(12.7, -4.7), vp(-6.2, 16.6), vp(-12.8, 27.3), vp(44.1, -48.2), vp(-47.7, 0.1), vp(46.2, -3.4)",
  };

  int nPruebas = magXY.size() / 2 - 1;

  std::cout << "\nPruebas de construcción de curva:\n" << std::endl;

  Curva crv( Punto( magXY[0], magXY[1]) );
  std::cout << "Creada curva " << crv.toStringPt() << std::endl;

  for( int i = 0; i<nPruebas; i++) {
    Punto nuevoPt( magXY[(i+1)*2], magXY[(i+1)*2+1]);
    std::string tspt_teo(ts_teo[i*2]);
    std::string tsve_teo(ts_teo[i*2+1]);

    crv.aniade( nuevoPt );

    std::cout << "Considerada curva " << tspt_teo << std::endl;

    pruebas++;
    std::string tspt = crv.toStringPt();
    if (tspt.substr(0, tspt_teo.length()) != tspt_teo)
      std::cout << "FALLO " << ++fallos << ": toStringPt ha devuelto '"
          << tspt <<"' cuando se esperaba '" << tspt_teo << "'"
          << std::endl;

    pruebas++;
    if (tspt[tspt.length()-1] != ']')
      std::cout << "FALLO " << ++fallos << ": toStringPt ha devuelto '"
          << tspt <<"' no tiene corchete al final."
          << std::endl;

    pruebas++;
    std::string tsve = crv.toStringVec();
    if (tsve.substr(0, tsve_teo.length()) != tsve_teo)
      std::cout << "FALLO " << ++fallos << ": toStringVec ha devuelto '"
          << tsve <<"' cuando se esperaba '" << tsve_teo << "'"
          << std::endl;

    pruebas++;
    if (tsve[tsve.length()-1] != ']')
      std::cout << "FALLO " << ++fallos << ": toStringVec ha devuelto '"
          << tsve <<"' no tiene corchete al final "
          << std::endl;
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
