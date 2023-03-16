EXEC_NAME_A = afflab
EXEC_NAME_T = text

BIN=./bin/
OBJ_C=obj/core/
OBJ_S=obj/sdl2/
OBJ_T=obj/txt/

SRC_C=src/core/
SRC_S=src/sdl2/
SRC_T=src/txt/

INCLUDES = -I./extern/include -Isrc -Isrc/core -I src/sdl2
INCLUDE_DIR	= -Isrc -Isrc/core -Isrc/txt -Itxt


OBJ_FILES_A = $(OBJ_S)main_sdlLab.o $(OBJ_S)sdlLab.o $(OBJ_C)Labyrinthe.o $(OBJ_C)Dimension.o $(OBJ_C)Position.o $(OBJ_C)Fraise.o $(OBJ_C)Gardien.o $(OBJ_C)Niveau.o $(OBJ_C)Jeu.o
OBJ_FILES_T = $(OBJ_T)mainTxtJeu.o $(OBJ_T)winTxt.o $(OBJ_T)txtJeu.o $(OBJ_C)Dimension.o $(OBJ_C)Position.o $(OBJ_C)Labyrinthe.o $(OBJ_C)Fraise.o $(OBJ_C)Gardien.o $(OBJ_C)Jeu.o 



CC = g++
CFLAGS = -Wall -ggdb


all: $(BIN)$(EXEC_NAME_A) 

$(BIN)$(EXEC_NAME_A): $(OBJ_FILES_A)
	$(CC) $(OBJ_FILES_A) -o $(BIN)$(EXEC_NAME_A)  -lSDL2 -lSDL2_ttf -lSDL2_image

$(BIN)$(EXEC_NAME_T): $(OBJ_FILES_T)
	$(CC) $(OBJ_FILES_T) -o $(BIN)$(EXEC_NAME_T)  -lSDL2 -lSDL2_ttf -lSDL2_image

$(OBJ_S)main_sdlLab.o: $(SRC_S)sdlLab/main_sdlLab.cpp $(SRC_S)sdlLab/sdlLab.h $(SRC_C)Jeu.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_S)sdlLab/main_sdlLab.cpp -o $(OBJ_S)main_sdlLab.o
$(OBJ_S)sdlLab.o: $(SRC_S)sdlLab/sdlLab.h $(SRC_S)sdlLab/sdlLab.cpp $(SRC_C)Jeu.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_S)sdlLab/sdlLab.cpp -o $(OBJ_S)sdlLab.o
$(OBJ_C)Jeu.o: $(SRC_C)Jeu.h $(SRC_C)Jeu.cpp $(SRC_C)Niveau.h $(SRC_C)Fraise.h $(SRC_C)Gardien.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Jeu.cpp -o $(OBJ_C)Jeu.o
$(OBJ_C)Niveau.o: $(SRC_C)Niveau.h $(SRC_C)Niveau.cpp $(SRC_C)Labyrinthe.h $(SRC_C)Position.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Niveau.cpp -o $(OBJ_C)Niveau.o
$(OBJ_C)Fraise.o: $(SRC_C)Fraise.h $(SRC_C)Fraise.cpp $(SRC_C)Labyrinthe.h $(SRC_C)Position.h $(SRC_C)Gardien.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Fraise.cpp -o $(OBJ_C)Fraise.o
$(OBJ_C)Gardien.o: $(SRC_C)Gardien.h $(SRC_C)Gardien.cpp $(SRC_C)Labyrinthe.h $(SRC_C)Position.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Gardien.cpp -o $(OBJ_C)Gardien.o
$(OBJ_C)Labyrinthe.o: $(SRC_C)Labyrinthe.h $(SRC_C)Labyrinthe.cpp $(SRC_C)Dimension.h $(SRC_C)Position.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Labyrinthe.cpp -o $(OBJ_C)Labyrinthe.o
$(OBJ_C)Dimension.o: $(SRC_C)Dimension.h $(SRC_C)Dimension.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Dimension.cpp -o $(OBJ_C)Dimension.o
$(OBJ_C)Position.o: $(SRC_C)Position.h $(SRC_C)Position.cpp 
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_C)Position.cpp -o $(OBJ_C)Position.o
$(OBJ_T)txtJeu.o: $(SRC_T)txtJeu.h $(SRC_T)txtJeu.cpp $(SRC_T)winTxt.cpp $(SRC_T)winTxt.h (SRC_C)Jeu.cpp $(SRC_C)Jeu.h
	$(CC) $(CFLAGS) $(INCLUDE_DIR)  $(INCLUDES) -c $(SRC_T)txtJeu.cpp -o $(OBJ_T)txtJeu.o
$(OBJ_T)mainTxtJeu.o: $(SRC_T)txtJeu.h $(SRC_T)txtJeu.cpp $(SRC_T)winTxt.cpp $(SRC_T)winTxt.h  $(SRC_C)Jeu.cpp $(SRC_C)Jeu.h
	$(CC) $(CFLAGS) $(INCLUDE_DIR)  $(INCLUDES) -c $(SRC_T)mainTxtJeu.cpp -o $(OBJ_T)mainTxtJeu.o
$(OBJ_T)winTxt.o: $(SRC_T)winTxt.h $(SRC_T)winTxt.cpp 
	$(CC) $(CFLAGS) $(INCLUDE_DIR) $(INCLUDES) -c $(SRC_T)winTxt.cpp -o $(OBJ_T)winTxt.o
clean:
	rm $(OBJ_C)*.o $(OBJ_S)*.o $(OBJ_T)*.o $(BIN)*
v_afflab:
	valgrind ./$(BIN)$(EXEC_NAME_A)
v_text:
	valgrind ./$(BIN)$(EXEC_NAME_T)


 




