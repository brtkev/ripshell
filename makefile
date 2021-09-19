# Makefile para compilar archivos en el directorio actual
#Nombre del ejecutable. Deseable en mayusculas.
#make ${nombre de ejecutable}


TARGET = ripshell
#Bibliotecas incluidas, La biblioteca math.h es una muy comun
LIBS = -lm
#Compilador utilizado, por ej icc, pgcc, gcc, g++
CC = gcc
# Banderas del compilador, por ej -DDEBUG - 02 - 03 -wall -g
CFLAGS = -g

# Palabras que usa el Makefile que podrian ser el nombre de un Programa
.PHONY: default all clean 
# compilacion por defecto

default: $(TARGET)
all: default
# incluye los archivos .o y .c que estan en el directorio actual
OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
# incluye los archivos.h que estan en el directorio actual
HEADERS = $(wildcard *.h)
# compila automaticamente solo archivos fuente que se han Modificado
# $< es el primer prerrequisito, generalmente el archivofuente
# $@ nombre del archivo que se esta Generando, archivo objeto
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
#preserva archivos intermedios
.PRECIOUS: $(TARGET) $(OBJECTS)

# borra archivos .o
clean: 
	-rm -f *.o core
#borra archivos .o y el ejecutable
#cleanall: clean 
#	-rm -f $(TARGET)

# enlaza objetos y crea el ejecutable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

dev : clean $(TARGET)
	./$(TARGET) $(args)