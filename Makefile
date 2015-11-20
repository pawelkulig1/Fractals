all:
	gcc main.c gfx.c rotation.c -o main -lX11 -lm
