include .env
export

CXX = clang++
CXXFLAGS = -std=c++20 -Wall -pedantic -g

UNAME_S := $(shell uname -s)

ifeq ($(OS),Windows_NT)
	# PATH TO SFML LIBRARY
	SFML_INCLUDE = -I${WIN_SFML_INCLUDE_PATH}
	SFML_LIB = -L${WIN_SFML_LIB_PATH} -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin) # MacOS
	# PATH TO SFML LIBRARY
	SFML_INCLUDE = -I${MAC_SFML_INCLUDE_PATH}
	SFML_LIB = -L${MAC_SFML_LIB_PATH} -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	else # Linux
	SFML_INCLUDE = -Isrc/
	SFML_LIB = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	endif
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
