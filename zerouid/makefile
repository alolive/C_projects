# la cible (programme) au sens makefile suivie des dependances
# le regle a appliquer (apres tabulation dans le fichier) pour cette cible

CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=zerouid

all: $(EXEC)

debug: CFLAGS=-W -Wall -ansi -pedantic -g
debug: $(EXEC)

check_nodns.o: check_nodns.c zerouid.h
	$(CC) -o $@ -c $< $(CFLAGS)

check_upper.o: check_upper.c zerouid.h
	$(CC) -o $@ -c $< $(CFLAGS)

build_root_token.o: build_root_token.c zerouid.h
	$(CC) -o $@ -c $< $(CFLAGS)

set_decode_password.o: set_decode_password.c zerouid.h
	$(CC) -o $@ -c $< $(CFLAGS)

set_token_suffix.o: set_token_suffix.c zerouid.h
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c zerouid.h
	$(CC) -lcrypt -o $@ -c $< $(CFLAGS)

zerouid: main.o set_token_suffix.o set_decode_password.o build_root_token.o check_upper.o check_nodns.o
	$(CC) -lcrypt -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC) 
