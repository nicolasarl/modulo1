// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 2018-10-07

#include <iostream>// Permite usar cerr, cout, cin, endl
#include <string>// Permite usar tipo string

// Esta función halla la representación en binario del numero introducido
// y determina el número de bits a '1' que tiene
int bitsUno(int numero){
  // Comprobamos que el numero sea positivo, ya que el algoritmo no está
  // diseñado para número negativos
  if(numero < 0){
    std::cout << "Este programa no puede tratar con numeros negativos"
        << std::endl;
    exit(EXIT_FAILURE);
  }
  //Convertimos el número a binario
  int dividendo = numero;
  int resto = 0;
  int cuantosUno = 0;
  while(dividendo >= 2){
    resto = dividendo%2;
    std::cerr << "Cuando el dividendo es: " << dividendo << "el resto es: "
      << resto << std::endl;
    if(resto){
      cuantosUno++;
      std::cerr << "La cuenta se actualiza a: " << cuantosUno << std::endl;
    }
    dividendo = dividendo/2;
    std::cerr << "El nuevo dividendo es: " << dividendo << std::endl;
  }
  if(dividendo != 0){
    cuantosUno++;
  }
  return cuantosUno;
}

std::string hexadecimal(int dividendo){
  std::string numeroHexadecimal = "";
  if(dividendo == 0){
    numeroHexadecimal = "0";
  }
  int resto = 1;
  while(1){
    resto = (dividendo%16);
    switch(resto){
      case 10:
        numeroHexadecimal = 'a' + numeroHexadecimal;
        break;
      case 11:
        numeroHexadecimal = 'b' + numeroHexadecimal;
        break;
      case 12:
        numeroHexadecimal = 'c' + numeroHexadecimal;
        break;
      case 13:
        numeroHexadecimal = 'd' + numeroHexadecimal;
        break;
      case 14:
        numeroHexadecimal = 'e' + numeroHexadecimal;
        break;
      case 15:
        numeroHexadecimal = 'f' + numeroHexadecimal;
        break;
      default:
        if(resto != 0){
          numeroHexadecimal = std::to_string(resto) + numeroHexadecimal;
        }else if((resto == 0) && (dividendo >= 16)){
          numeroHexadecimal = std::to_string(resto) + numeroHexadecimal;
        }
        break;
    }
    if(dividendo < 16){
      break;
    }
    dividendo /= 16;
  }
  return numeroHexadecimal;
}

int main(int argc, char* argv[]){

  while(1){
    std::string numeroIntroducido = "";
    std::cin >> numeroIntroducido;
    std::cerr << "El numero introducido es: " << numeroIntroducido 
        << std::endl;
    // obtenemos el numero de bits de su representacion en binario que 
    //estan a 1
    int numeroIntr = 0;
    try{
      numeroIntr = std::stoi(numeroIntroducido);
    }catch(std::invalid_argument e1){
      std::cerr << "Error de conversión, tipo no admitido" << std::endl;
      exit(EXIT_FAILURE);
    }catch(std::out_of_range e2){
      std::cerr << "Número demasiado grande" << std::endl;
      exit(EXIT_FAILURE);
    }
    
    int numeroBitsUno = bitsUno(numeroIntr);
  
    //Calculamos su representación en hexadecimal

    std::string numeroHexadecimal = hexadecimal(numeroIntr);
    numeroHexadecimal = "0x" + numeroHexadecimal;
    
    std::cerr << "El numero en hexadecimal queda como: " << numeroHexadecimal
        << std::endl;
    //Mostramos los resultados al usuario
  
    std::cout << numeroBitsUno << " " << numeroHexadecimal << std::endl;

    if(numeroIntr == 0){
      std::cerr << "Salida indicada por el usuario" << std::endl;
      exit(EXIT_SUCCESS);
    }
  }
}
