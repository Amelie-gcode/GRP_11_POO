# Nom de l'exécutable final
EXEC = programme

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++17 -O2

# Drapeaux de liaison pour SFML
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Rechercher automatiquement tous les fichiers source (.cpp)
SRC = $(wildcard *.cpp)

# Générer automatiquement les fichiers objets correspondants
OBJ = $(SRC:.cpp=.o)

# Règle par défaut (celle qui sera exécutée par défaut)
all: $(EXEC)

# Règle pour construire l'exécutable
$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(SFML_LIBS)

# Règle générique pour construire les fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJ) $(EXEC)

# Nettoyer mais garder les fichiers objets (utile pour recompiler rapidement)
clean-obj:
	rm -f $(OBJ)

# Indiquer que ces règles ne sont pas des fichiers
.PHONY: all clean clean-obj
