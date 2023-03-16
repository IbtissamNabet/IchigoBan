CC = g++
CPPFLAGS = -Wall -ggdb
INCLUDE_DIR	= -Isrc -Isrc/core -Isrc/txt

all: bin/txtJeu

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

bin/txtJeu: $(OBJ_COR) $(OBJ_TXT)
	$(CC) -o $@ $(OBJ_COR) $(OBJ_TXT)

obj/txt/%.o: src/txt/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

obj/core/%.o: src/core/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

obj/sdl2/%.o: src/sdl2/%.cpp
	$(CC) -c $(CPPFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	rm -f obj/txt/* obj/sdl2/* obj/core/* bin/*