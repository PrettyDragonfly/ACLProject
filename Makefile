COMPILE = g++ -Wall
CIBLE = game

#folders
ENT = src/model/entities/
INP = src/model/inputs/
MAP = src/model/map/
MOD = src/model/

#sources
SRC = $(MOD)game.o

#headers
HEAD = $(MOD)Game.h

########################################################################################################################

help:
	echo "Makefile basique temporaire juste pour build le projet: make run pour build et run, make clean pour supprimer l'exe et les .o"

run:	game
	./game

game: src/main.cpp $(SRC) $(HEAD)
	$(COMPILE) $(SRC) src/main.cpp -o $(CIBLE)

clean:
	rm -f $(CIBLE)
	rm -f $(SRC)

########################################################################################################################

$(MOD)game.o: $(MOD)Game.cpp	$(MOD)Game.h
	$(COMPILE)	-c	$(MOD)Game.cpp	-o $(MOD)game.o