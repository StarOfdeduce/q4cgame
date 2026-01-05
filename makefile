CC = g++
CCFLAGS = -g 
CCLIBS = -lncurses
mygame: main.o Gui.o Game.o Item.o Ship.o Bullet.o Gunboat.o Player.o Torpedo.o Destroyer.o 
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Item.o  Bullet.o Ship.o Gunboat.o Player.o Torpedo.o Destroyer.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Item.o: Item.C Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.C
	
Ship.o: Ship.h Ship.C
	$(CC) $(CCFLAGS) -c -o Ship.o Ship.C
	
Gunboat.o: Gunboat.h Gunboat.C
	$(CC) $(CCFLAGS) -c -o Gunboat.o Gunboat.C
	
Destroyer.o: Destroyer.h Destroyer.C
	$(CC) $(CCFLAGS) -c -o Destroyer.o Destroyer.C
	
Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C
	
Torpedo.o: Torpedo.h Torpedo.C
	$(CC) $(CCFLAGS) -c -o Torpedo.o Torpedo.C
	
Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C
	
clean:
	rm -rf mygame *.o
