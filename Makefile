EXEC_NAME = afflab

BIN=./bin/
OBJ_C=obj/core/
OBJ_S=obj/sdl2/
SRC_C=src/core/
SRC_S=src/sdl2/

INCLUDES = -I./extern/include -Isrc -Isrc/core -I src/sdl2


OBJ_FILES = $(OBJ_S)main_sdlLab.o $(OBJ_S)sdlLab.o $(OBJ_C)Labyrinthe.o $(OBJ_C)Dimension.o $(OBJ_C)Position.o


CC = g++
CFLAGS = -Wall -ggdb


all: $(BIN)$(EXEC_NAME)

$(BIN)$(EXEC_NAME): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(BIN)$(EXEC_NAME)  -lSDL2 -lSDL2_ttf -lSDL2_image

$(OBJ_S)main_sdlLab.o: $(SRC_S)sdlLab/main_sdlLab.cpp $(SRC_S)sdlLab/sdlLab.h $(SRC_C)Labyrinthe.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_S)sdlLab/main_sdlLab.cpp -o $(OBJ_S)main_sdlLab.o

$(OBJ_S)sdlLab.o: $(SRC_S)sdlLab/sdlLab.h $(SRC_S)sdlLab/sdlLab.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_S)sdlLab/sdlLab.cpp -o $(OBJ_S)sdlLab.o
$(OBJ_C)Labyrinthe.o: $(SRC_C)Labyrinthe.h $(SRC_C)Labyrinthe.cpp $(SRC_C)Dimension.h $(SRC_C)Position.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Labyrinthe.cpp -o $(OBJ_C)Labyrinthe.o
$(OBJ_C)Dimension.o: $(SRC_C)Dimension.h $(SRC_C)Dimension.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Dimension.cpp -o $(OBJ_C)Dimension.o
$(OBJ_C)Position.o: $(SRC_C)Position.h $(SRC_C)Position.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Position.cpp -o $(OBJ_C)Position.o

clean:
	rm $(OBJ_C)*.o $(OBJ_S)*.o $(BIN)*


v_afflab:
	valgrind ./$(BIN)$(EXEC_NAME)


 




