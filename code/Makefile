INCF=-I/usr/include/mysql
LNKF=-L/usr/lib/i386-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl

programme:
	gcc -Wall src/main.c -o bin/Programme $(INCF) $(LNKF)

clean:
	rm bin/* src/*~ obj/*
