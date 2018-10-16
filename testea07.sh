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
TMPMA=tempfileMA$$
TMPME=tempfileME$$


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
    pivote=10
    if [ $# -gt 1 ]
    then
        pivote=$2
    fi
    FICHMA="$1_mayores_$pivote.dat"
    FICHME="$1_menores_$pivote.dat"
    rm -f $FICHMA $FICHME

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

    let PRUEBAS++

    if [ -r  $FICHMA ]
    then
        diff  --ignore-trailing-space -q $TMPMA $FICHMA &>/dev/null
        if [ $? -eq 0 ]
        then
            verde "CORRECTO: el fichero de mayores"
        else
            rojo "ERROR: el fichero de mayores debería contener"
            cat $TMPMA
            rojo "Pero contiene"
            cat $FICHMA
            let ERRORES++
        fi
    else
        rojo "No existe el fichero de mayores: -$FICHMA-"
    fi

    let PRUEBAS++
    if [ -r  $FICHME ]
    then
        diff  --ignore-trailing-space -q $TMPME $FICHME &>/dev/null
        if [ $? -eq 0 ]
        then
            verde "CORRECTO: el fichero de menores"
        else
            rojo "ERROR: el fichero de menores debería contener"
            cat $TMPME
            rojo "Pero contiene"
            cat $FICHME
            let ERRORES++
        fi
    else
        rojo "No existe el fichero de mayores: -$FICHME-"
    fi
    rm -f $FICHMA $FICHME

}


# #########################################
cian "\n* Pivote por defecto datos 1"
cat > $TMPMA <<_EOF_
37
34
34
25
34
31
25
44
18
43
12
_EOF_
cat > $TMPME <<_EOF_
-38
-17
-19
-45
-11
-17
-35
-48
-34
-47
-40
-15
-46
-24
2
-27
-34
-10
-43
_EOF_
cat > $TMPOK <<_EOF_
Pivote: 10
Iguales: 0
_EOF_
ejecutaOK datosEnteros1

cian "\n* Pivote por defecto datos 2"
cat > $TMPOK <<_EOF_
Pivote: 10
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
51
38
59
88
57
49
92
23
23
68
16
78
71
53
76
29
21
65
_EOF_
cat > $TMPME <<_EOF_
-65
-9
-62
-34
-51
-88
-55
-82
-47
-36
8
6
-78
-96
0
3
-35
-91
-30
-62
-13
-66
-92
1
-51
-42
-78
-14
-87
8
-89
-13
_EOF_
ejecutaOK datosEnteros2


# #########################################
cian "\n* Pivote 5 datos 1"
cat > $TMPOK <<_EOF_
Pivote: 5
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
37
34
34
25
34
31
25
44
18
43
12
_EOF_
cat > $TMPME <<_EOF_
-38
-17
-19
-45
-11
-17
-35
-48
-34
-47
-40
-15
-46
-24
2
-27
-34
-10
-43
_EOF_
ejecutaOK datosEnteros1 5

cian "\n* Pivote 5 datos 2"
cat > $TMPOK <<_EOF_
Pivote: 5
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
51
38
59
88
57
8
6
49
92
23
23
68
16
78
71
53
76
29
21
8
65
_EOF_
cat > $TMPME <<_EOF_
-65
-9
-62
-34
-51
-88
-55
-82
-47
-36
-78
-96
0
3
-35
-91
-30
-62
-13
-66
-92
1
-51
-42
-78
-14
-87
-89
-13
_EOF_
ejecutaOK datosEnteros2 5


# #########################################
cian "\n* Pivote 40 datos 1"
cat > $TMPOK <<_EOF_
Pivote: 40
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
44
43
_EOF_
cat > $TMPME <<_EOF_
-38
-17
-19
-45
37
34
34
-11
-17
-35
-48
25
-34
-47
34
31
-40
-15
-46
25
-24
2
18
-27
-34
12
-10
-43
_EOF_
ejecutaOK datosEnteros1 40

cian "\n* Pivote 40 datos 2"
cat > $TMPOK <<_EOF_
Pivote: 40
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
51
59
88
57
49
92
68
78
71
53
76
65
_EOF_
cat > $TMPME <<_EOF_
-65
-9
-62
-34
38
-51
-88
-55
-82
-47
-36
8
6
-78
-96
0
3
-35
-91
23
23
-30
16
-62
-13
-66
-92
1
-51
-42
-78
-14
29
21
-87
8
-89
-13
_EOF_
ejecutaOK datosEnteros2 40


# #########################################
cian "\n* Pivote 100 datos 1"
cat > $TMPOK <<_EOF_
Pivote: 100
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
_EOF_
cat > $TMPME <<_EOF_
-38
-17
-19
-45
37
34
34
-11
-17
-35
-48
25
-34
-47
34
31
-40
-15
-46
25
-24
2
44
18
-27
-34
43
12
-10
-43
_EOF_
ejecutaOK datosEnteros1 100

cian "\n* Pivote 100 datos 2"
cat > $TMPOK <<_EOF_
Pivote: 100
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
_EOF_
cat > $TMPME <<_EOF_
-65
-9
-62
51
-34
38
59
-51
88
-88
-55
-82
-47
-36
57
8
6
-78
-96
0
3
49
-35
92
-91
23
23
68
-30
16
-62
-13
78
71
-66
53
-92
1
76
-51
-42
-78
-14
29
21
-87
8
65
-89
-13
_EOF_
ejecutaOK datosEnteros2 100

# #########################################
cian "\n* Pivote -10 datos 1"
cat > $TMPOK <<_EOF_
Pivote: -10
Iguales: 1
_EOF_
cat > $TMPMA <<_EOF_
37
34
34
25
34
31
25
2
44
18
43
12
_EOF_
cat > $TMPME <<_EOF_
-38
-17
-19
-45
-11
-17
-35
-48
-34
-47
-40
-15
-46
-24
-27
-34
-43
_EOF_
ejecutaOK datosEnteros1 -10

cian "\n* Pivote -10 datos 2"
cat > $TMPOK <<_EOF_
Pivote: -10
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
-9
51
38
59
88
57
8
6
0
3
49
92
23
23
68
16
78
71
53
1
76
29
21
8
65
_EOF_
cat > $TMPME <<_EOF_
-65
-62
-34
-51
-88
-55
-82
-47
-36
-78
-96
-35
-91
-30
-62
-13
-66
-92
-51
-42
-78
-14
-87
-89
-13
_EOF_
ejecutaOK datosEnteros2 -10

# #########################################
cian "\n* Pivote -100 datos 1"
cat > $TMPOK <<_EOF_
Pivote: -100
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
-38
-17
-19
-45
37
34
34
-11
-17
-35
-48
25
-34
-47
34
31
-40
-15
-46
25
-24
2
44
18
-27
-34
43
12
-10
-43
_EOF_
cat > $TMPME <<_EOF_
_EOF_
ejecutaOK datosEnteros1 -100

cian "\n* Pivote -100 datos 2"
cat > $TMPOK <<_EOF_
Pivote: -100
Iguales: 0
_EOF_
cat > $TMPMA <<_EOF_
-65
-9
-62
51
-34
38
59
-51
88
-88
-55
-82
-47
-36
57
8
6
-78
-96
0
3
49
-35
92
-91
23
23
68
-30
16
-62
-13
78
71
-66
53
-92
1
76
-51
-42
-78
-14
29
21
-87
8
65
-89
-13
_EOF_
cat > $TMPME <<_EOF_
_EOF_
ejecutaOK datosEnteros2 -100


# #########################################

cian "\n* Argumento pivote incorrecto"
let PRUEBAS++
./$EJECUTA  datosEnteros1 xx 2>/dev/null
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
rm $TMPMA
rm $TMPME
