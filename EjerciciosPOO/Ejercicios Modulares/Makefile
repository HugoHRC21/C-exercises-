# Variables
CC = g++
CFLAGS = -Wall -g -Iinclude
SOURCES = main/main.cpp src/HashTable.cpp src/Person.cpp src/Functions.cpp 
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)
EXECUTABLE = bin/main.exe

# Regla principal
all: $(EXECUTABLE)

# Regla para crear el ejecutable
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar los archivos objeto
bin/%.o: main/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

obj/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)