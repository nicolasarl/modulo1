// Autor: Nicolás Adrián ROdríguez Linares
// Fecha: 2018-10-07

#include <vector> // Necesaria para emplear tipo vector
#include <string> // Necesaria para emplear tipo string
#include <iostream> // Necesaria para poder emplear cout, cerr y endl
#include <fstream> // Necesaria para la lectura de un fichero std::ifstream

/* Esta función devuelve el numero de elementos iguales al pivote,
 * los elementos mayores al pivote y los elementos menores al pivote
 */
int clasificacionNumeros(const std::vector<int>& datos, std::vector<int>& mayores, std::vector<int>& menores, int pivote){
  
  int iguales = 0;
  for(std::size_t i = 0; i < datos.size(); i++){
    std::cerr <<"Considerando el dato " << datos[i] << std::endl;
    if(datos[i] > pivote){
	  std::cerr <<"El dato " << datos[i] << " es mayor que el pivote"
          << std::endl;
      mayores.push_back(datos[i]);
    }else if(datos[i] < pivote){
	  std::cerr <<"El dato " << datos[i] << " es menor que el pivote"
          << std::endl;
      menores.push_back(datos[i]);  
    }else{
	  std::cerr <<"El dato " << datos[i] << " es igual que el pivote"
          << std::endl;
	  iguales++;
	}
  }
  return iguales;
}

int main(int argc, char* argv[]){

  std::cerr <<"El programa tiene " << argc << " parámetros de entrada" 
      << std::endl;
  for(int i = 0; i < argc; i++){
    std::cerr << "El argumento " << i << " contiene '" << argv[i] << "'"
        << std::endl;
  }
  int pivote = 10; // valor predeterminado del pivote
  
// Realizamos una comprobación de los argumentos del programa para
// decidir el curso de acción y detectar posibles errores

  if (argc == 1){
    std::cout <<"Se ha olvidado de introducir el nombre del fichero" 
        << std::endl;
    exit(EXIT_FAILURE);
  }else if(argc == 2){
    std::cerr <<"El nombre del fichero es: " << argv[1] << std::endl;
  }else{
	std::cerr << "Se han introducido todos los parámetros" << std::endl;
	std::cerr << "El pivote vale: " << argv[2] << std::endl;
	try{// Para obtener el valor del pivote debemos convertir de str a int
	  pivote = std::stoi(argv[2]);
	// Usamos la documentacion de std::stoi para el manejo de errores
	}catch(std::invalid_argument e1){
	  std::cout << "Se ha producido un error en la conversión del pivote"
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
// Ahora ejecutamos el código relacionado con la lectura del fichero

  int linea; // entero temporal para almacenar las lineas del fichero
  std::vector<int> datos;
  try{// Abrimos, leemos y cerramos el fichero
    std::ifstream fent(argv[1]);
    int i = 0;
    while(fent.good()){
      fent >> linea;
      datos.push_back(linea);
      std::cerr << "El contenido del vector en la posicion " << i << " es "
          << datos[i] << std::endl;
      i++;
    }
    fent.close();
  }catch(std::ifstream::failure e1){ // Gestión de errores básica
    std::cout << "Error al abrir/leer/cerrar el fichero" << std::endl;
    exit(EXIT_FAILURE);
  }
// Ahora ejecutamos la función que compara el vector de datos con el pivote
// y mostramos los resultados al usuario
  std::vector<int> mayores, menores;
  int iguales = clasificacionNumeros(datos,mayores,menores,pivote);
  std::cout << "Pivote: " << pivote << std::endl;
  std::cout << "Mayores: " << std::endl;
  for(std::size_t i = 0; i < mayores.size(); i++){
    std::cout << mayores[i] << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Menores: "<< std::endl;
  for(std::size_t i = 0; i < menores.size(); i++){
    std::cout << menores[i] << std::endl;
  }
  std::cout << std::endl;
  std::cout << "Iguales: " << iguales << std::endl;
}
	
