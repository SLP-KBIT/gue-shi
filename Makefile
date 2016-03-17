gue: main.o input.o title.o
	gcc -I $(CURDIR) -o gue main.o input.o title.o
main.o: main.c
	gcc -I $(CURDIR) -o main.o -c main.c
input.o: sys/input.c
	gcc -I $(CURDIR) -o input.o -c sys/input.c
title.o: game/title.c
	gcc -I $(CURDIR) -o title.o -c game/title.c
.PHONY: clean delete
delete:
	find . -name "*.o" | xargs rm -r
clean: delete
	rm -r gue
