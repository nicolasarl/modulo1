#!/bin/bash

# Scritp para la prueba del ejercicio01 de la Práctica 1 de Inf. Ind.
# Curso 18-19

GPP=g++

if [ $# -lt 1 ]
then
  echo "$0: Falta primer argumento con fichero fuente testear"
  exit 1
fi

FICHERO_CPP=$1
EJECUTA=ejecutable$$
TMPF=tempfile$$
TMPOK=tempfileOK$$


rojo() { echo -e "$(tput setaf 1)$@$(tput setaf 9)"; }
verde() { echo -e "$(tput setaf 2)$@$(tput setaf 9)"; }
amarillo()  { echo -e "$(tput setaf 3)$@$(tput setaf 9)"; }
azul()  { echo -e "$(tput setaf 4)$@$(tput setaf 9)"; }
magenta()  { echo -e "$(tput setaf 5)$@$(tput setaf 9)"; }
cian()  { echo -e "$(tput setaf 6)$@$(tput setaf 9)"; }

if [ ! -r $FICHERO_CPP ]
then
    echo "$0: No puedo acceder al fichero $FICHERO_CPP"
    exit 2
fi

CMD="$GPP --std=c++14 -Wall -o $EJECUTA $FICHERO_CPP"
magenta "\nPasamos a compilar en fuente ==============="

echo $CMD

$CMD
if [ $? -ne 0 ]
then
    echo "$0: Falló la compilación"
    exit 2
fi

$GPP --std=c++14 -Wall -Werror  -o $EJECUTA $FICHERO_CPP &>/dev/null
if [ $? -ne 0 ]
then
    amarillo "Compilación con Warnings"
fi

magenta "\nComenzamos las pruebas ==========="
PRUEBAS=0
ERRORES=0

cian "\n* Faltan argumentos"
let PRUEBAS++
./$EJECUTA 2>/dev/null
if [ $? -gt 0 ]
then
    verde "CORRECTO: código distinto de 0"
else
    rojo "Error: Si faltan argumentos debería devolver código != 0"
    let ERRORES++
fi

cian "\n* Fichero no existe"
let PRUEBAS++
./$EJECUTA NoExito.NO 2>/dev/null
if [ $? -gt 0 ]
then
    verde "CORRECTO: código distinto de 0"
else
    rojo "Error: Si fichero no existe debería devolver código != 0"
    let ERRORES++
fi

ejecutaOK() {
    let PRUEBAS++
    ./$EJECUTA $@ >$TMPF 2>/dev/null
    if [ $? -eq 0 ]
    then
        verde "CORRECTO: código devuelto es 0"
    else
        rojo "Error: La ejecución debe ser CORRECTO pero devuelve !=0"
        let ERRORES++
    fi

    let PRUEBAS++

    diff  $TMPOK $TMPF &>/dev/null
    if [ $? -eq 0 ]
    then
        verde "CORRECTO: lo volcado por salida estándar es correcto"
    else
        rojo "ERROR: la salida estándar debería ser"
        cat $TMPOK
        rojo "Pero lo volcado es"
        cat $TMPF
        let ERRORES++
    fi
}


# #########################################
cian "\n* Pivote por defecto datos 1"
cat > $TMPOK <<_EOF_
Pivote: 10
Resultado: 11
_EOF_
ejecutaOK datosEnteros1.dat

cian "\n* Pivote por defecto datos 2"
cat > $TMPOK <<_EOF_
Pivote: 10
Resultado: 18
_EOF_
ejecutaOK datosEnteros2.dat


# #########################################
cian "\n* Pivote 5 datos 1"
cat > $TMPOK <<_EOF_
Pivote: 5
Resultado: 11
_EOF_
ejecutaOK datosEnteros1.dat 5

cian "\n* Pivote 5 datos 2"
cat > $TMPOK <<_EOF_
Pivote: 5
Resultado: 21
_EOF_
ejecutaOK datosEnteros2.dat 5


# #########################################
cian "\n* Pivote 40 datos 1"
cat > $TMPOK <<_EOF_
Pivote: 40
Resultado: 2
_EOF_
ejecutaOK datosEnteros1.dat 40

cian "\n* Pivote 40 datos 2"
cat > $TMPOK <<_EOF_
Pivote: 40
Resultado: 12
_EOF_
ejecutaOK datosEnteros2.dat 40


# #########################################
cian "\n* Pivote 100 datos 1"
cat > $TMPOK <<_EOF_
Pivote: 100
Resultado: 0
_EOF_
ejecutaOK datosEnteros1.dat 100

cian "\n* Pivote 100 datos 2"
cat > $TMPOK <<_EOF_
Pivote: 100
Resultado: 0
_EOF_
ejecutaOK datosEnteros2.dat 100

# #########################################
cian "\n* Pivote -10 datos 1"
cat > $TMPOK <<_EOF_
Pivote: -10
Resultado: 12
_EOF_
ejecutaOK datosEnteros1.dat -10

cian "\n* Pivote -10 datos 2"
cat > $TMPOK <<_EOF_
Pivote: -10
Resultado: 25
_EOF_
ejecutaOK datosEnteros2.dat -10

# #########################################
cian "\n* Pivote -100 datos 1"
cat > $TMPOK <<_EOF_
Pivote: -100
Resultado: 30
_EOF_
ejecutaOK datosEnteros1.dat -100

cian "\n* Pivote -100 datos 2"
cat > $TMPOK <<_EOF_
Pivote: -100
Resultado: 50
_EOF_
ejecutaOK datosEnteros2.dat -100


# #########################################

cian "\n* Argumento pivote incorrecto"
let PRUEBAS++
./$EJECUTA  datosEnteros1.dat xx 2>/dev/null
if [ $? -eq 134 ]
then
    rojo "ERROR: el programa fue abortado"
    let ERRORES++
else
    if [ $? -ne 0 ]
    then
        verde "CORRECTO: código distinto de 0"
    else
        rojo "Error: Si fichero no existe debería devolver código != 0"
        let ERRORES++
    fi
fi

# #########################################

magenta "\nPruebas terminadas ============"
echo -e "Realizadas $PRUEBAS pruebas con $ERRORES errores"

rm $EJECUTA
rm $TMPF
rm $TMPOK
