# la cible (programme) au sens makefile suivie des dependances
# le regle a appliquer (apres tabulation dans le fichier) pour cette cible

CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=bpceid

all: $(EXEC)

debug: CFLAGS=-W -Wall -ansi -pedantic -g
debug: $(EXEC)

get_list.o: get_list.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_value.o: get_value.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_key.o: get_key.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

is_list.o: is_list.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

is_key.o: is_key.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

disp_prop_llst.o: disp_prop_llst.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_ansiblehost_properties.o: get_ansiblehost_properties.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_dmz_properties.o: get_dmz_properties.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_sat_properties.o: get_sat_properties.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_gconf_properties.o: get_gconf_properties.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

set_llst_header.o: set_llst_header.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

get_fqdn.o: get_fqdn.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c bpceid.h
	$(CC) -o $@ -c $< $(CFLAGS)

bpceid: main.o get_fqdn.o set_llst_header.o get_sat_properties.o disp_prop_llst.o is_key.o is_list.o get_key.o get_value.o get_list.o get_ansiblehost_properties.o get_dmz_properties.o get_gconf_properties.o
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC) 
