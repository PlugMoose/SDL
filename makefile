CFLAGS = -I./Header `sdl2-config --cflags --libs`

FILES = $(wildcard ./Source/*.c ./Source/*.cpp)
OBJ = $(patsubst ./Source/%.c,./Obj/%.o,$(FILES))

M: L
		g++  $(OBJ) $(CFLAGS)  -o ./Bin/Main
L:
		g++ -c $(FILES) $(CFLAGS) -o $(OBJ)

clean:
		rm -f Bin/* Dep/*
