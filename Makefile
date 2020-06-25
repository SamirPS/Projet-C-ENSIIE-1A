game : carte.o structure.o plateau.o interface.o main.o
	gcc -g -Wall -Wextra obj/main.o obj/carte.o obj/structure.o  obj/plateau.o obj/interface.o  -o bin/game
test : carte.o structure.o plateau.o interface.o test.o
	gcc -g -Wall -Wextra obj/test.o obj/carte.o obj/structure.o  obj/plateau.o obj/interface.o  -o bin/test -lcunit
main.o : src/main.c
	gcc -g -Wall -Wextra -c src/main.c -o obj/main.o
test.o : src/test.c
	gcc -g -Wall -Wextra -c src/test.c -o obj/test.o
interface.o : src/interface.c headers/interface.h 
	gcc -g -Wall -Wextra -c src/interface.c -o obj/interface.o
plateau.o : src/plateau.c headers/plateau.h
	gcc -g -Wall -Wextra -c src/plateau.c -o obj/plateau.o
structure.o : src/structure.c headers/structure.h
	gcc -g -Wall -Wextra -c  src/structure.c -o obj/structure.o
carte.o : src/carte.c headers/carte.h
	gcc -g -Wall -Wextra -c src/carte.c -o obj/carte.o
