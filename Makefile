FILES = ./src/menu/libreria/boxes.c ./src/menu/libreria/menu.c ./src/matrix/matrix.c ./src/header.c ./src/matrix/determinant.c ./src/matrix/operations.c ./src/matrix/rank.c ./src/matrix/inverted.c ./src/text/text.c main.c

build-all:
	gcc -Wno-unused-variable -Wno-implicit-function-declaration -o programma.exe -I./include $(FILES)
	./programma.exe

run:
	gcc -o programma.exe -I./include $(FILES)
	cls
	./programma.exe