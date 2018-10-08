// Autor: Nicolás Adrián Rodríguez Linares
// Fecha: 2018-10-08

#include <iostream> // cerr,cout,ifstream
#include <vector> // uso tipo vector
#include <string> // uso tipo string
#include <fstream> // Necesaria para la lectura de un fichero std::ifstream

// Esta funcion analiza un vector de booleanos y crea un entero positivo
// a partir de los resultados del analisis en base  alos criterios
// establecido en el enunciado del ejercicio10

unsigned int analisisBooleano(const std::vector<bool>& booleanos,
    unsigned int inicial, unsigned int iFinal){
  
  unsigned int enteroResultado = 0;
  // creamos un string para formar el entero a medida que analizamos
  // el vector de booleanos
  std::string formacionEntero = "";
  for(unsigned int i = inicial; i <= iFinal; i++){
    if(booleanos[i] == true){
	  formacionEntero = '1' + formacionEntero;
    }else{
	  formacionEntero = '0' + formacionEntero;
	}
  }
  try{
    enteroResultado = std::stoi(formacionEntero);
  }catch(std::invalid_argument e1){
	std::cout << "Se ha producido un error en la conversión de un indice"
	    << std::endl;
	exit(EXIT_FAILURE);
  }catch(std::out_of_range e2){
	std::cout << "Los indices estan muy distanciados y generan un " 
	    << "entero demasiado grande" << std::endl;
	exit(EXIT_FAILURE);
  }catch(std::exception e){
    std::cout <<"Se ha producido un error desconocido" << std::endl;
    exit(EXIT_FAILURE);
  }
  return enteroResultado;
}
//Esta funcion convierte un numero decimal positivo a un numero binario
std::string enteroBinario(unsigned int numero){

  //Convertimos el número a binario
  int dividendo = numero;
  int resto = 0;
  std::string binario = "";
  while(dividendo >= 2){
    resto = dividendo%2;
    std::cerr << "Cuando el dividendo es: " << dividendo << " el resto es: "
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

  // Primero establecemos codigo erro en caso de que no se introduzca el
  // nombre del fichero con los datos
  if(argc == 1){
    std::cout << "Debe introducir un nombre de fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::vector<bool> booleanos;
  std::string nombreSinExtension;
  try{
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
    while(fent.good()){
      fent >> linea;
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
  }catch(std::ifstream::failure e1){ // Gestión de errores básica
    std::cout << "Error al abrir/leer/cerrar el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
  
  // Ahora comprobaremos el estado de los argumentos que deben indicar
  // los índices de comienzo y final
  unsigned int inicio = 0;
  unsigned int iFinal = booleanos.size();
  
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
	}catch(std::exception e){
	  std::cout <<"Se ha producido un error desconocido" << std::endl;
	  exit(EXIT_FAILURE);
	}
  }
  std::cerr << "Inicio vale: " << inicio << " y Final vale: " << iFinal
    << std::endl;  
  
  unsigned int enteroGenerado = analisisBooleano(booleanos, inicio, iFinal);
  std::cerr << "El entero generado es: " << enteroGenerado << std::endl;
  
  //Ahora convertiremos el entero a hexadecimal
  
    int dividendo = enteroGenerado;
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
    
    // Por último, emplearemos la función del ejercicio08 para obtener 
    // la representación en base 2
    
    std::string binario = enteroBinario(enteroGenerado);
    
    // Formateamos la representación en binario
    
    binario = "0b" + binario;
    
    // Mostramos los resultados al usuario
    
    std::cout << "Número generado: " << enteroGenerado << std::endl;
    std::cout << "En Hexadecimal: " << numeroHexadecimal << std::endl;
    std::cout << "En binario: " << binario << std::endl;
}
