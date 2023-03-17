CC = g++
CPPFLAGS = -Wall -ggdb
INCLUDE_DIR	= -Isrc -Isrc/core -Isrc/txt 
INCLUDE_DIR_= -I./extern/include -Isrc -Isrc/core -I src/sdl2/sdlLab

all: bin/sdlJeu

OBJ_COR=obj/core/Dimension.o \
        obj/core/Fraise.o \
		obj/core/Gardien.o \
		obj/core/Jeu.o \
		obj/core/Labyrinthe.o \
		obj/core/Niveau.o \
		obj/core/Partie.o \
		obj/core/Position.o

OBJ_TXT=obj/txt/mainTxtJeu.o \
		obj/txt/txtJeu.o \
		obj/txt/winTxt.o

OBJ_SDL=obj/sdl2/sdlLab.o \
		obj/sdl2/main_sdlLab.o 

bin/sdlJeu:$(OBJ_COR) $(OBJ_SDL)
	$(CC) -o $@ $(OBJ_COR) $(OBJ_SDL) -lSDL2 -lSDL2_ttf -lSDL2_image

bin/txtJeu: $(OBJ_COR) $(OBJ_TXT)
	$(CC) -o $@ $(OBJ_COR) $(OBJ_TXT)

obj/txt/%.o: src/txt/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

obj/sdl2/%.o: src/sdl2/sdlLab/%.cpp 
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_) $< -lSDL2 -lSDL2_ttf -lSDL2_image -o $@ 

obj/core/%.o: src/core/%.cpp src/core/%.h
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	rm -f obj/txt/* obj/sdl2/* obj/core/* bin/*