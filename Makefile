gue: main.o
	gcc -o gue main.o
main.o: main.c
	gcc -o main.o -c main.c
.PHONY: clean delete
delete:
	find . -name "*.o" | xargs rm -r
clean: delete
	rm -r gue
