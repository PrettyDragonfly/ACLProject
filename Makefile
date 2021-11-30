COMPILE = g++ -Wall -std=c++11
CIBLE = game
SDL = -lSDL2 -lSDL2_image

#folders
ENT = src/model/entities/
INP = src/model/inputs/
MAP = src/model/map/
MOD = src/model/
VUE = src/view/
RES = src/ressources/

#sources
SRC = $(MOD)game.o $(MOD)world.o $(MAP)map.o $(MAP)floor.o $(MAP)tile.o $(MAP)breakwall.o $(MAP)unbreakwall.o $(ENT)entity.o $(ENT)player.o $(ENT)bomb.o $(VUE)game_view.o $(INP)input.o $(ENT)enemy.o

#headers
HEAD = $(MOD)Game.h $(MOD)World.h $(MAP)Map.h $(MAP)Floor.h $(MAP)Tile.h $(MAP)Breakable_Wall.h $(MAP)Unbreakable_Wall.h $(ENT)Entity.h $(ENT)Player.h $(ENT)Bomb.h  $(VUE)Game_View.h $(INP)Input_Manager.h $(ENT)Enemy.h

########################################################################################################################

help:
	echo "Makefile basique juste pour build le projet: make run pour build et run, make clean pour supprimer l'exe et les .o"

run:	game
	./game

game: 	src/main.cpp $(SRC) $(HEAD)
	$(COMPILE) $(SRC) src/main.cpp -o $(CIBLE) $(SDL)

test: test/test_pa.cpp $(SRC) $(HEAD)
	$(COMPILE) $(SRC) test/test_pa.cpp -o test_pa

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
	$(COMPILE)	-c	$(MAP)Unbreakable_Wall.cpp -o	$(MAP)unbreakwall.o

$(MAP)breakwall.o: 		$(MAP)Breakable_Wall.cpp 		$(MAP)Breakable_Wall.h
	$(COMPILE)	-c 	$(MAP)Breakable_Wall.cpp		-o 	$(MAP)breakwall.o

$(INP)input.o:			$(INP)Input_Manager.cpp 		$(INP)Input_Manager.h
	$(COMPILE)	-c	$(INP)Input_Manager.cpp			-o	$(INP)input.o

$(ENT)entity.o:			$(ENT)Entity.cpp 			$(ENT)Entity.h
	$(COMPILE)	-c	$(ENT)Entity.cpp			-o	$(ENT)entity.o

$(ENT)player.o:			$(ENT)Player.cpp 			$(ENT)Player.h
	$(COMPILE)	-c	$(ENT)Player.cpp			-o	$(ENT)player.o

$(ENT)bomb.o: 		$(ENT)Bomb.cpp 					$(ENT)Bomb.h
	$(COMPILE)	-c 	$(ENT)Bomb.cpp				-o  $(ENT)bomb.o

$(VUE)game_view.o: 		$(VUE)Game_View.cpp 		$(VUE)Game_View.h
	$(COMPILE)	-c 	$(VUE)Game_View.cpp			-o 	$(VUE)game_view.o

$(ENT)enemy.o:			$(ENT)Enemy.cpp			$(ENT)Enemy.h
	$(COMPILE)	-c	$(ENT)Enemy.cpp				-o	$(ENT)enemy.o

