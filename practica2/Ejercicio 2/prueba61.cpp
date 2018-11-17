// Autor: Alberto Hamilton Castro

#define TITULO "Probando info() de puertas con nombre"

#include "And.hpp"
#include "Or.hpp"
#include "Uno.hpp"
#include "Cero.hpp"
#include "Not.hpp"

#include <iostream>
#include <iomanip>

int main() {

  int fallos = 0;
  int pruebas = 0;
  std::cout << "\n***  " << TITULO << "  ***\n" << std::endl;

  And a0(std::string("A0"));
  Uno u1(std::string("U1"));
  Cero c2("C2");
  Or o3("O3");
  Not n4("N 4");

  pruebas++;
  {
    std::string espera = "Puerta AND [A0] (id=0) salida = 9\n  NO CONECTADA\n  NO CONECTADA\n";
    std::string inf = a0.info();
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  a0.conecta1(&u1);
  {
    std::string espera = "   Puerta AND [A0] (id=0) salida = 9\n     Puerta UNO [U1] (id=1)\n     NO CONECTADA\n";
    std::string inf = a0.info(3);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  a0.conecta2(&o3);
  {
    std::string espera = " Puerta AND [A0] (id=0) salida = 9\n   Puerta UNO [U1] (id=1)\n   Puerta OR [O3] (id=3) salida = 9\n     NO CONECTADA\n     NO CONECTADA\n";
    std::string inf = a0.info(1);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  o3.conecta2(&c2);
  {
    std::string espera = "     Puerta AND [A0] (id=0) salida = 9\n       Puerta UNO [U1] (id=1)\n       Puerta OR [O3] (id=3) salida = 9\n         NO CONECTADA\n         Puerta CERO [C2] (id=2)\n";
    std::string inf = a0.info(5);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  o3.conecta1(&n4);
  {
    std::string espera = "  Puerta AND [A0] (id=0) salida = 9\n    Puerta UNO [U1] (id=1)\n    Puerta OR [O3] (id=3) salida = 9\n      Puerta NOT [N 4] (id=4) salida = 9\n        NO CONECTADA\n      Puerta CERO [C2] (id=2)\n";
    std::string inf = a0.info(2);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  n4.conecta1(&u1);
  {
    std::string espera = "         Puerta AND [A0] (id=0) salida = 0\n           Puerta UNO [U1] (id=1)\n           Puerta OR [O3] (id=3) salida = 0\n             Puerta NOT [N 4] (id=4) salida = 0\n               Puerta UNO [U1] (id=1)\n             Puerta CERO [C2] (id=2)\n";
    std::string inf = a0.info(9);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
  }

  pruebas++;
  n4.conecta1(&u1);
  {
    std::string espera = "       Puerta AND [A0] (id=0) salida = 0\n         Puerta UNO [U1] (id=1)\n         Puerta OR [O3] (id=3) salida = 0\n           Puerta NOT [N 4] (id=4) salida = 0\n             Puerta UNO [U1] (id=1)\n           Puerta CERO [C2] (id=2)\n";
    std::string inf = a0.info(7);
    if ( inf == espera )
      std::cout << "CORRECTO la respuesta de info \n'" << inf << "'" << std::endl;
    else
      std::cout << "FALLO " << ++fallos << ": se esparaba respuesta \n'"
          << espera << "' pero devolvió \n'" << inf << "'" << std::endl;
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
