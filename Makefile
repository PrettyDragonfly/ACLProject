COMPILE = g++ -Wall
CIBLE = game

#folders
ENT = src/model/entities/
INP = src/model/inputs/
MAP = src/model/map/
MOD = src/model/
VUE = src/view/

#sources
SRC = $(MOD)game.o $(MOD)world.o $(MAP)floor.o $(MAP)map.o $(MAP)tile.o $(MAP)unbreakwall.o $(ENT)player.o $(ENT)entity.o $(ENT)bomb.o $(VUE)game_view.o $(INP)input.o

#headers
HEAD = $(MOD)Game.h $(MOD)World.h $(MAP)Map.h $(MAP)Floor.h $(MAP)Tile.h $(MAP)Unbreakable_Wall.h $(ENT)Entity.h $(ENT)Bomb.h $(ENT)Player.h $(VUE)Game_View.h $(INP)Input_Manager.h

########################################################################################################################

help:
	echo "Makefile basique juste pour build le projet: make run pour build et run, make clean pour supprimer l'exe et les .o"

run:	game
	./game

game: 	src/main.cpp $(SRC) $(HEAD)
	$(COMPILE) $(SRC) src/main.cpp -o $(CIBLE)

clean:
	rm -f $(CIBLE)
	rm -f $(SRC)

########################################################################################################################

$(MOD)game.o: 			$(MOD)Game.cpp				$(MOD)Game.h
	$(COMPILE)	-c	$(MOD)Game.cpp				-o 	$(MOD)game.o

$(MOD)world.o: 			$(MOD)World.cpp				$(MOD)World.h
	$(COMPILE)	-c	$(MOD)World.cpp				-o 	$(MOD)world.o

$(MAP)map.o:			$(MAP)Map.cpp 				$(MAP)Map.h
	$(COMPILE)	-c	$(MAP)Map.cpp				-o	$(MAP)map.o

$(MAP)floor.o:			$(MAP)Floor.cpp 			$(MAP)Floor.h
	$(COMPILE)	-c	$(MAP)Floor.cpp				-o	$(MAP)floor.o

$(MAP)tile.o:			$(MAP)Tile.cpp 				$(MAP)Tile.h
	$(COMPILE)	-c	$(MAP)Tile.cpp				-o	$(MAP)tile.o

$(MAP)unbreakwall.o:	$(MAP)Unbreakable_Wall.cpp 	$(MAP)Unbreakable_Wall.h
	$(COMPILE)	-c	$(MAP)Unbreakable_Wall.cpp	-o	$(MAP)unbreakwall.o

$(INP)input.o:			$(INP)Input_Manager.cpp 			$(INP)Input_Manager.h
	$(COMPILE)	-c	$(INP)Input_Manager.cpp			-o	$(INP)input.o

$(ENT)entity.o:			$(ENT)Entity.cpp 			$(ENT)Entity.h
	$(COMPILE)	-c	$(ENT)Entity.cpp			-o	$(ENT)entity.o

$(ENT)player.o:			$(ENT)Player.cpp 			$(ENT)Player.h
	$(COMPILE)	-c	$(ENT)Player.cpp			-o	$(ENT)player.o

$(ENT)bomb.o:			$(ENT)Bomb.cpp 			$(ENT)Bomb.h
	$(COMPILE)	-c	$(ENT)Bomb.cpp			-o	$(ENT)bomb.o

$(VUE)game_view.o: 		$(VUE)Game_View.cpp 		$(VUE)Game_View.h
	$(COMPILE)	-c 	$(VUE)Game_View.cpp			-o 	$(VUE)game_view.o