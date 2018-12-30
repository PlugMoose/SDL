CFLAGS = -I./Header `sdl2-config --cflags --libs`
OBJDIR = Obj

FILES = $(wildcard ./Source/*.c ./Source/*.cpp)

M: $(OBJ)
		gcc -c $(FILES) $(CFLAGS) -o ./Obj/Temp.o
		gcc ./Obj/Temp.o $(CFLAGS)  -o main

clean:
		rm -f Bin/* Dep/*
