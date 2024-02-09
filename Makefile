include .env
export

CXX = g++
CXXFLAGS = -std=c++20 -Wall -pedantic -g

ifeq ($(OS),Windows_NT)
	# PATH TO SFML LIBRARY
	SFML_INCLUDE = -I${WIN_SFML_INCLUDE_PATH}
	SFML_LIB = -L${WIN_SFML_LIB_PATH} -lsfml-graphics -lsfml-window -lsfml-system
else # Linux
	SFML_INCLUDE = -Isrc/
	SFML_LIB = -lsfml-graphics -lsfml-window -lsfml-system
endif

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

EXE = sfml-app

all: $(EXE) run
build: $(EXE) clean-obj

$(EXE): $(OBJ)
	$(CXX) $^ -o bin/$@ $(SFML_LIB)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

run:
	cd ./bin; \
	./$(EXE)

clean-obj:
	rm -f $(OBJ)
