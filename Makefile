FILES = ./src/menu/libreria/boxes.c ./src/matrix/matrix.c ./src/header.c ./src/menu/libreria/menu.c ./src/matrix/determinant.c ./src/text/text.c main.c

build-all:
	gcc -Wno-unused-variable -Wno-implicit-function-declaration -o programma.exe -I./include $(FILES)
	./programma.exe