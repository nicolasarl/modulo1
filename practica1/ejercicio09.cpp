// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 2018-10-08

#include <iostream>// Permite usar cerr, cout, cin, endl
#include <string>// Permite usar tipo string

// Esta función halla la representación en binario del numero introducido
std::string enteroBinario(unsigned int numero){

  //Convertimos el número a binario
  int dividendo = numero;
  int resto = 0;
  std::string binario = "";
  while(dividendo >= 2){
    resto = dividendo%2;
    std::cerr << "Cuando el dividendo es: " << dividendo << "el resto es: "
      << resto << std::endl;
    if(resto){
	  binario = '1' + binario;
	  std::cerr << "EL numero binario se actualiza a: " << binario 
	      << std::endl;
	}else{
	  binario = '0' + binario;
	  std::cerr << "EL numero binario se actualiza a: " << binario 
	      << std::endl;
    }
	dividendo = dividendo/2;
	std::cerr << "El nuevo dividendo es: " << dividendo << std::endl;
  }
  if(dividendo != 0){
    binario = '1' + binario;
	  std::cerr << "EL numero binario se actualiza a: " << binario 
	      << std::endl;
  }
  return binario;
}

int main(int argc, char* argv[]){

  while(1){
    int numeroIntroducido = 0;
    std::cout << "Introduzca un numero entero: ";
    std::cin >> numeroIntroducido;
    if(numeroIntroducido == 0){
	  std::cerr << "Salida indicada por el usuario" << std::endl;
	  exit(EXIT_SUCCESS);
	}
	// Comprobamos que el numero sea positivo, ya que el algoritmo no está
    // diseñado para número negativos
    if(numeroIntroducido < 0){
	  std::cout << "Este programa no puede tratar con numeros negativos"
	      << std::endl;
      exit(EXIT_FAILURE);
    }
    std::cerr << "El numero introducido es: " << numeroIntroducido 
        << std::endl;
    // Obtenemos la representacion en binario del numero introducido
    std::string binario = enteroBinario(numeroIntroducido);
  
    //Calculamos su representación en hexadecimal
  
    int dividendo = numeroIntroducido;
    int resto = 0;
    std::string numeroHexadecimal = "";
  
    while(dividendo >= 16){
      resto = dividendo%16;
      std::cerr << "El resto es: " << resto << std::endl;
      switch(resto){
	    case 10:
	      numeroHexadecimal = 'A' + numeroHexadecimal;
	      break;
	    case 11:
	      numeroHexadecimal = 'B' + numeroHexadecimal;
	      break;
	    case 12:
	      numeroHexadecimal = 'C' + numeroHexadecimal;
	      break;
	    case 13:
	      numeroHexadecimal = 'D' + numeroHexadecimal;
	      break;
	    case 14:
	      numeroHexadecimal = 'E' + numeroHexadecimal;
	      break;
	    case 15:
	      numeroHexadecimal = 'F' + numeroHexadecimal;
	      break;
	    default:
	      numeroHexadecimal = std::to_string(resto) + numeroHexadecimal;
	      break;
      }
      std::cerr << "El numero en hexadecimal actual es: " << numeroHexadecimal
           << std::endl;
      dividendo = dividendo/16;
      std::cerr << "El nuevo dividendo es: " << dividendo << std::endl;

    }
    if(dividendo != 0){
	  std::cerr << "El dividendo final es: " << dividendo << std::endl;
      switch(dividendo){
	    case 10:
	      numeroHexadecimal = 'A' + numeroHexadecimal;
	      break;
	    case 11:
	      numeroHexadecimal = 'B' + numeroHexadecimal;
	      break;
	    case 12:
	      numeroHexadecimal = 'C' + numeroHexadecimal;
	      break;
	    case 13:
	      numeroHexadecimal = 'D' + numeroHexadecimal;
	      break;
	    case 14:
	      numeroHexadecimal = 'E' + numeroHexadecimal;
	      break;
	    case 15:
	      numeroHexadecimal = 'F' + numeroHexadecimal;
	      break;
	    default:
	      numeroHexadecimal = std::to_string(dividendo) + numeroHexadecimal;
	      break;
      }
    }
    // Terminamos de formatear el numero en base hexadecimal
    numeroHexadecimal = "0x" + numeroHexadecimal;
    std::cerr << "El numero en hexadecimal queda como: " << numeroHexadecimal
        << std::endl;
    //Mostramos los resultados al usuario
  
    std::cout << binario << " " << numeroHexadecimal << std::endl;
    std::cout << "Si desea salir del programa introduzca un 0" 
        << std::endl;
  }
}
