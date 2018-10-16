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
TMPIN=tempfileIN$$


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

ejecutaOK() {

    let PRUEBAS++
    ./$EJECUTA <$TMPIN >$TMPF 2>/dev/null
    if [ $? -eq 0 ]
    then
        verde "CORRECTO: código devuelto es 0"
    else
        rojo "Error: La ejecución debe ser CORRECTO pero devuelve !=0"
        let ERRORES++
    fi

    let PRUEBAS++
    diff  --ignore-trailing-space -q $TMPOK $TMPF &>/dev/null
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
cian "\n* Entrada 0 directamente"
cat > $TMPIN <<_EOF_
0
_EOF_
cat > $TMPOK <<_EOF_
0 0x0
_EOF_
ejecutaOK

cian "\n* Números potencia de 2"
cat > $TMPIN <<_EOF_
1
2
4
8
16
32
1024
0
_EOF_
cat > $TMPOK <<_EOF_
1 0x1
1 0x2
1 0x4
1 0x8
1 0x10
1 0x20
1 0x400
0 0x0
_EOF_
ejecutaOK

cian "\n* Números de 2 bits"
cat > $TMPIN <<_EOF_
3
6
12
5
10
9
18
33
1032
0
_EOF_
cat > $TMPOK <<_EOF_
2 0x3
2 0x6
2 0xc
2 0x5
2 0xa
2 0x9
2 0x12
2 0x21
2 0x408
0 0x0
_EOF_
ejecutaOK

cian "\n* Números de 3 bits"
cat > $TMPIN <<_EOF_
7
14
11
13
273
0
_EOF_
cat > $TMPOK <<_EOF_
3 0x7
3 0xe
3 0xb
3 0xd
3 0x111
0 0x0
_EOF_
ejecutaOK

cian "\n* Números de muchos bits"
cat > $TMPIN <<_EOF_
61
65535
437
0
_EOF_
cat > $TMPOK <<_EOF_
5 0x3d
16 0xffff
6 0x1b5
0 0x0
_EOF_
ejecutaOK


# #########################################

cian "\n* Entrada incorrecta"
let PRUEBAS++
./$EJECUTA &>/dev/null <<_EOF_
4
xx
_EOF_
if [ $? -ne 0 ]
then
    verde "CORRECTO: código distinto de 0"
else
    rojo "Error: Si no es entero debe devolver != 0"
    let ERRORES++
fi

# #########################################

magenta "\nPruebas terminadas ============"
echo -e "Realizadas $PRUEBAS pruebas con $ERRORES errores"

rm $EJECUTA
rm $TMPF
rm $TMPOK
rm $TMPIN
