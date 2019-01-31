CFLAGS = -I./Headers -lSDL2_image -I/usr/include/SDL2 -D_REENTRANT -lSDL2

FILESC = $(wildcard ./Source/*.c)
FILES+ = $(wildcard ./Source/*.cpp)
FILES = $(FILESC) $(FILES+)
OBJC = $(patsubst ./Source/%.c,./Obj/%.o,$(FILESC))
OBJ+ = $(patsubst ./Source/%.cpp,./Obj/%.o,$(FILES+))
OBJ = $(OBJC) $(OBJ+)

MASTER:
	g++ $(FILES) $(CFLAGS)  -o ./Bin/Main



#Master:
#		g++ -c $(CFLAGS) $(FILESC) $(FILES+) -o $(OBJ)
#		g++ $(CFLAGS) -o ./Bin/Main $(OBJ)
