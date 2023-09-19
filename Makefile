CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -g

ifeq ($(OS),Windows_NT)
	# PATH TO SFML LIBRARY
	SFML_INCLUDE = -ID:\CPP-libs\SFML-2.5.1\includes
	SFML_LIB = -LD:\CPP-libs\SFML-2.5.1\lib -lsfml-graphics -lsfml-window -lsfml-system
else
	SFML_INCLUDE = -Isrc
	SFML_LIB = -lsfml-graphics -lsfml-window -lsfml-system
endif

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

EXE = sfml-app

all: $(EXE) run clean-obj

$(EXE): $(OBJ)
	$(CXX) $^ -o bin/$@ $(SFML_LIB)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

run:
	cd ./bin; \
	./$(EXE)

clean-obj:
	rm -f $(OBJ)
