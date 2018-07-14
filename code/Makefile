INCF=-I/usr/include/mysql
LNKF=-L/usr/lib/i386-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl
MLVF=`pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV` `pkg-config --libs-only-l MLV`

programme:
	gcc -Wall src/main.c -o bin/Programme $(INCF) $(LNKF) $(MLVF)

clean:
	rm bin/* src/*~ obj/*
