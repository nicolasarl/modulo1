#Autor: Alberto Hamilton Castro
#Fichero Makefile para compilar las distintas pruebas
# preparadas para verificar el correcto funcionamiento
# del ejercicio
#
# basta con ejecutar en línea de comandos
#  make  ->  para compilar las pruebas básica
#  make prueba##  -> para obtener ese ejecutable concreto (no poner cpp)
#  make clean -> borrar ficheros generados y dejar solo los fuentes
#  make exe## -> trata de compilar y ejecutar la prueba##
#  make exe -> trata de compilar y ejecutar todas las pruebas
#  make fallidas -> ídem que la anterior pero sólo muestra resultado
#      de las fallidas


GPP=g++-5 -Wall --std=c++14

pruebas:=$(wildcard prueba??.cpp)

clases:=$(wildcard [A-Z]*.cpp)

ficheroZip=Ficheros_P2_E1.zip

#Evitamos que se borren los fichero intermedios (%.o)
.SECONDARY :

all : $(pruebas:.cpp=)

info :
	echo "pruebas: $(pruebas)"
	echo "clases: $(clases)"


depend : .dependC .dependP .dependE

.dependC: $(clases) Makefile
	@rm -f ./.dependC
	@$(GPP)  -MM $(clases) > ./.dependC 2>/dev/null

.dependP: $(pruebas) $(clases) Makefile
	@rm -f ./.dependP
	@$(GPP)  -MM $(pruebas) > ./.dependP 2>/dev/null

.dependE: .dependP
	@rm -f ./.dependE
	@cat ./.dependP | sed -e's/\.o//' -e's/\..pp/\.o/g' > ./.dependE


-include .dependC
-include .dependP
-include .dependE

%.o : %.cpp
	$(GPP) -c -o $@ $<

prueba% : prueba%.o
	$(GPP) -g -o $@ $^

#reglas para borrar los fichero generados
# y dejar sólo los fuente
clean :
	rm -f *.o $(pruebas:.cpp=) .depend*

#Generación de zip
zip : $(ficheroZip)

$(ficheroZip) : Makefile $(pruebas)
	-rm $@
	zip $@ $^

#Reglas para ejecutar los distintos grupos de pruebas

exe% : prueba%
	./$<

exe :  $(sort $(pruebas:.cpp=))
	@for fa in $^; \
	do echo "\n$$(tput setaf 2)==== $$fa ===========================$$(tput setaf 9)"; \
	./$$fa;done

fallidas :   $(sort $(pruebas:.cpp=))
	@for fa in $^; \
	do if ./$$fa >/dev/null 2>&1; \
	then echo "==== "$$fa CORRECTA""; \
	else echo "\n$$(tput setaf 2)==== $$fa ===========================$$(tput setaf 9)"; \
	./$$fa; fi; done


fallan :
	-make clean
	make fail

fail:
	-make -k all 2>/dev/null
	@echo -e "\n\n==========================="
	@for fa in $(sort $(pruebas:.cpp=)); \
	do titulo=$$(grep 'define TITULO' $$fa.cpp | sed -e's/^#define TITULO //'); \
	if [ ! -x ./$$fa ] ; \
	then echo "$$(tput setaf 1)==== $$fa NO EXISTE  $$titulo $$(tput setaf 9)"; \
	elif { ./$$fa; } >ejecucion.log 2>&1; \
	then echo "$$(tput setaf 2)==== $$fa CORRECTA   $$titulo $$(tput setaf 9)"; \
	else \
	   if grep -w 'core' ejecucion.log ; \
	   then \
	      PORCEN="(core)" ;\
	   else \
	      PORCEN=$$(cat ejecucion.log | grep % | sed -e's/^.*pruebas //'); \
	   fi; \
	   echo "$$(tput setaf 5)==== $$fa INCORRECTA $$PORCEN $$titulo $$(tput setaf 9)"; \
	fi; done
