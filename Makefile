CC = g++
CPPFLAGS = -Wall -ggdb
INCLUDE_DIR	= -Isrc -Isrc/core -Isrc/txt 
INCLUDE_DIR_= -I./extern/include -Isrc -Isrc/core -I src/sdl2/sdlLab

all: bin/sdlJeu bin/txtJeu bin/reg

OBJ_COR=obj/core/Dimension.o \
        obj/core/Fraise.o \
		obj/core/Gardien.o \
		obj/core/Jeu.o \
		obj/core/Labyrinthe.o \
		obj/core/Niveau.o \
		obj/core/Position.o \
		
OBJ_REG=obj/core/mainTest.o 

OBJ_TXT=obj/txt/mainTxtJeu.o \
		obj/txt/txtJeu.o \
		obj/txt/winTxt.o \


OBJ_SDL=obj/sdl2/sdlLab.o \
		obj/sdl2/main_sdlLab.o 

bin/sdlJeu:$(OBJ_COR) $(OBJ_SDL)
	$(CC) -o $@ $(OBJ_COR) $(OBJ_SDL) -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

bin/txtJeu: $(OBJ_COR) $(OBJ_TXT)
	$(CC) -o $@ $(OBJ_COR) $(OBJ_TXT)
	
bin/reg : $(OBJ_COR) $(OBJ_REG)
	$(CC) -o $@ $(OBJ_COR) $(OBJ_REG)

obj/core/mainTest.o: src/core/mainTest.cpp  src/core/Gardien.h src/core/Fraise.h src/core/Jeu.h src/core/Labyrinthe.h src/core/Position.h
	$(CC) -c $(CPPFLAGS)  $< -o $@


obj/txt/mainTxtJeu.o: src/txt/mainTxtJeu.cpp src/txt/txtJeu.h src/core/Jeu.h src/core/Labyrinthe.h
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

obj/txt/txtJeu.o: src/txt/txtJeu.cpp src/txt/txtJeu.h src/core/Jeu.h src/core/Labyrinthe.h 
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

obj/txt/winTxt.o: src/txt/winTxt.cpp src/txt/txtJeu.h src/core/Jeu.h src/core/Labyrinthe.h
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

obj/sdl2/%.o: src/sdl2/sdlLab/%.cpp 
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR_) $< -lSDL2 -lSDL2_ttf -lSDL2_image -o $@ 

obj/core/%.o: src/core/%.cpp src/core/%.h
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	rm -f obj/txt/* obj/sdl2/* obj/core/* bin/*