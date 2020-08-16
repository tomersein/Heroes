CC = g++
OBJS = Creature.o Zombie.o Vampire.o Archer.o Wizard.o Black_Dragon.o Hero.o Warrior.o Thief.o Necromancer.o Game.o main.o
EXEC = Heroes
DEBUG_FLAG = -g
COMP_FLAG = -c
CLEAN = clean
$(EXEC):$(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
Creature.o:Creature.h GameException.h Creature.cpp
	$(CC) $(COMP_FLAG) $*.cpp
Zombie.o:Zombie.h Zombie.cpp Creature.h
	$(CC) $(COMP_FLAG) $*.cpp
Vampire.o:Vampire.h Vampire.cpp Creature.h
	$(CC) $(COMP_FLAG) $*.cpp
Archer.o:Archer.h Archer.cpp Creature.h
	$(CC) $(COMP_FLAG) $*.cpp
Wizard.o:Wizard.h Wizard.cpp Creature.h
	$(CC) $(COMP_FLAG) $*.cpp
Black_Dragon.o:Black_Dragon.h Black_Dragon.cpp Creature.h
	$(CC) $(COMP_FLAG) $*.cpp
Hero.o:Hero.h Hero.cpp Vampire.h Zombie.h Archer.h Wizard.h Black_Dragon.h
	$(CC) $(COMP_FLAG) $*.cpp
Thief.o:Thief.h Thief.cpp Hero.h
	$(CC) $(COMP_FLAG) $*.cpp
Warrior.o:Warrior.h Warrior.cpp Hero.h
	$(CC) $(COMP_FLAG) $*.cpp
Necromancer.o:Necromancer.h Necromancer.cpp Hero.h
	$(CC) $(COMP_FLAG) $*.cpp
Game.o:Necromancer.h Thief.h Warrior.h Game.h Game.cpp
	$(CC) $(COMP_FLAG) $*.cpp
main.o:main.cpp Game.h
	$(CC) $(COMP_FLAG) $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)
