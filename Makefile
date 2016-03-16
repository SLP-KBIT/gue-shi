gue: main.o input.o title.o
	gcc -o gue main.o input.o title.o
main.o: main.c
	gcc -o main.o -c main.c
input.o: input.c
	gcc -o input.o -c input.c
title.o: title.c
	gcc -o title.o -c title.c
.PHONY: clean delete
delete:
	find . -name "*.o" | xargs rm -r
clean: delete
	rm -r gue
