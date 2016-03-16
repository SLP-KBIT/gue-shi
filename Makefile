gue: main.o input.o
	gcc -o gue main.o input.o
main.o: main.c
	gcc -o main.o -c main.c
input.o: input.c
	gcc -o input.o -c input.c
.PHONY: clean delete
delete:
	find . -name "*.o" | xargs rm -r
clean: delete
	rm -r gue
