// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 2018-10-08

#include <iostream> // cerr,cout,ifstream
#include <vector> // uso tipo vector
#include <string> // uso tipo string
#include <fstream> // Necesaria para la lectura de un fichero std::ifstream

// Esta funcion analiza un vector de booleanos y crea un entero positivo
// a partir de los resultados del analisis en base  alos criterios
// establecido en el enunciado del ejercicio10

unsigned long analisisBooleano(const std::vector<bool>& booleanos,
    unsigned int inicial, unsigned int iFinal){

  // creamos un string para formar el entero a medida que analizamos
  // el vector de booleanos
    unsigned long formacionEntero = 0;
    for(unsigned int i = inicial; i <= iFinal; i++){
      if(booleanos[i] == true){
        formacionEntero |= (1 << (i - inicial));
      }
    }
  return formacionEntero;
}


//Esta funcion convierte un numero decimal positivo a un numero binario
std::string enteroBinario(unsigned int numero){

  //Convertimos el número a binario
  int dividendo = numero;
  int resto = 0;
  std::string binario = "";
  while(dividendo >= 2){
    resto = dividendo%2;
    std::cerr << "Cuando el dividendo es: " << dividendo << "el resto es: "
      << resto << std::endl;
    if(dividendo == 0){
        binario = '0';
        return binario;
    }
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
      std::cerr << "El numero binario se actualiza a: " << binario 
          << std::endl;
  }
  return binario;
}


//Conversión a hexadecimal
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

  std::cerr << "Los enteros miden: " << sizeof(int) << std::endl;
  // Primero establecemos codigo error en caso de que no se introduzca el
  // nombre del fichero con los datos
  if(argc == 1){
    std::cout << "Debe introducir un nombre de fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::vector<bool> booleanos;
  std::string nombreSinExtension;
  std::string nombre;
  nombre = argv[1];
  std::cerr << "El nombre almacenado es: " << nombre << std::endl;
 
  // Analizamos la extensión para determinar si debemos incluirla
  // o el usuario ya la introdujo junto al nombre
  std::string extension = nombre.substr((nombre.size()-4), nombre.size());
  std::cerr << "Extensión: " << extension << std::endl;
  if(extension != ".dat"){
    nombreSinExtension = nombre; //Almacenamos el nombre para la salida
    nombre = nombre + ".dat";
  }
  //Obtenemos el nombre del fichero sin el .dat
  if(extension == ".dat"){
    nombreSinExtension = nombre.substr(0,(nombre.size()-4));
  }
  std::cerr << "El nombre modificado es: " << nombre << std::endl;
  std::cerr << "El nombre sin extensión es: " << nombreSinExtension
      << std::endl;
  std::ifstream fent(nombre);
  std::string linea = "";
  int i = 0;
  if(!fent.good()){
    std::cout << "Ha habido un error en la apertura del fichero" 
      << std::endl;
    return 1;
  }
  while(fent.good()){
    fent >> linea;
    if(fent.eof()){
      break;
    }
    std::cerr << "El valor de la linea " << i << " es " << linea;
    if(linea == "verdad" || linea == "si" || linea == "true" 
        || linea == "1"){
      std::cerr << " y se almacena como verdadero" << std::endl;
      booleanos.push_back(true);
      i++;
    }else{
      std::cerr << " y se almacena como falso" << std::endl;
      booleanos.push_back(false);
      i++;
    }
  }

  // Ahora comprobaremos el estado de los argumentos que deben indicar
  // los índices de comienzo y final
  unsigned int inicio = 0;
  unsigned int iFinal = booleanos.size() -1;
  
  if(argc >= 3){
    try{// Para obtener los indices debemos convertir de str a int
      inicio = std::stoi(argv[2]);
      std::cerr << "El valor de inicio es: " << inicio << std::endl;
      // Aseguramos que sea un entero positivo y si no lanzamos un error
      // también contemplamos el caso de que sea mayor al num de lineas
      if ((inicio < 0) || (inicio > booleanos.size())){
        std::cout << "No se puede introducir un indice negativo "  
            << "o que supere el numero de lineas" << std::endl;
        exit(EXIT_FAILURE);
      }
      // Comprobamos que se indica el indice final
      if(argc == 4){
        iFinal = std::stoi(argv[3]);
        std::cerr << "El valor de iFinal es: " << iFinal << std::endl;
        // Aseguramos que sea positivo y que no supere el numero de lineas
        if((iFinal > booleanos.size()) || (iFinal < 0)){
          std::cout << "El indice final es mayor a las lineas del fichero"
              << " o se introdujo un numero negativo" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
    // Usamos la documentacion de std::stoi para el manejo de errores
    }catch(std::invalid_argument e1){
      std::cout << "Se ha producido un error en la conversión de un indice"
          << std::endl;
      exit(EXIT_FAILURE);
    }catch(std::out_of_range e2){
      std::cout << "El entero introducido es demasiado grande" << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  std::cerr << "Inicio vale: " << inicio << " y Final vale: " << iFinal
    << std::endl;  
  
  unsigned long enteroGenerado = analisisBooleano(booleanos, inicio, iFinal);
  std::cerr << "El entero generado es: " << enteroGenerado << std::endl;
  
  //Ahora convertiremos el entero a hexadecimal
  std::string numeroHexadecimal = hexadecimal(enteroGenerado);
  std::cerr << "El numero en hexadecimal queda como: " << numeroHexadecimal
      << std::endl;
  // Terminamos de formatear el numero en base hexadecimal
  numeroHexadecimal = "0x" + numeroHexadecimal;
  std::cerr << "El numero en hexadecimal queda como: " << numeroHexadecimal
      << std::endl;
    
  // Por último, emplearemos la función del ejercicio08 para obtener 
  // la representación en base 2
    
  std::string binario = enteroBinario(enteroGenerado);
    
  // Formateamos la representación en binario
    
  binario = "0b" + binario;
    
  // Mostramos los resultados al usuario
    
  std::cout << enteroGenerado << " " << numeroHexadecimal << " " 
      << binario << std::endl;
}
