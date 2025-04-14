FILES = ./src/boxes.c ./src/cesare.c ./src/header.c ./src/menu.c ./src/text.c ./src/usergui.c main.c

build-all:
	gcc -Wno-unused-variable -Wno-implicit-function-declaration -o programma.exe -I./include $(FILES)
	./programma.exe