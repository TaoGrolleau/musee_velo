INCF=-I/usr/include/mysql
LNKF=-L/usr/lib/i386-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl
MLVF=`pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` `pkg-config --libs-only-l MLV`

programme: affichage 
	gcc -Wall -O3 src/main.c obj/affichage.o -o bin/Programme $(INCF) $(LNKF) $(MLVF)

affichage:
	gcc -c src/affichage.c -o obj/affichage.o 

clean:
	rm bin/* src/*~ obj/* error.log

exec:
	./bin/Programme 2> error.log

