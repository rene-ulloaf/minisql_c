CC := g++
CFLAGS := -Wall
FMSQL = minisql.cc ./include/estructuras.h ./include/TDAListaTabla.h ./include/archivos.h
FARCH = ./src/archivos.cpp ./include/estructuras.h ./include/TDAListaTabla.h ./include/archivos.h
MODMSQL = minisql.o
MODARCH = archivos.o
MODULOS = minisql.o archivos.o

archivos.o : ./src/archivos.cpp ./include/estructuras.h ./include/TDAListaTabla.h ./include/archivos.h
	@echo Creando ejecutable archivo

	$(CC) -c -I $< -o $@
	$(CC) $< -o $@

minisql.o : minisql.cc ./include/estructuras.h ./include/TDAListaTabla.h ./include/archivos.h
	@echo Creando ejecutable minisql

	$(CC) -c $< -o $@
	$(CC) $< -o $@



debug:
	@echo generando ejecutable con debug

	$(CC) $(CFLAGS) $(FMSQL) -o $(MODMSQL) -c
	$(CC) $(CFLAGS) $(FARCH) -o $(MODARCH) -c
	
	$(CC) $(FMSQL) -o $(MODMSQL)
	$(CC) $(FARCH) -o $(MODARCH)
test :
	@echo generando ejecutable con test

	$(CC) $(CFLAGS) $(FMSQL) -o $(MODMSQL) -c
	$(CC) $(FMSQL) -o $(MODMSQL)
clean:
	@echo limpiando...
	rm -f $(MODULOS)
