CC=gcc

all: Aleatorium

creationmap.o: creationmap.c Aleatorium.h
	$(CC) -c $< -o $@

deplacement.o: deplacement.c Aleatorium.h
	$(CC) -c $< -o $@

detecterdeplacement.o: detecterdeplacement.c Aleatorium.h
	$(CC) -c $< -o $@

intro.o: intro.c Aleatorium.h
	$(CC) -c $< -o $@

Jeu.o: Jeu.c Aleatorium.h
	$(CC) -c $< -o $@

main.o: main.c Aleatorium.h
	$(CC) -c $< -o $@

menu.o: menu.c Aleatorium.h
	$(CC) -c $< -o $@
batum.o : batum.c Aleatorium.h
	$(CC) -c $< -o $@

boss.o : boss.c Aleatorium.h
	$(CC) -c $< -o $@
minijeux.o: minijeux.c Aleatorium.h
	$(CC) -c $< -o $@

outils.o: outils.c Aleatorium.h
	$(CC) -c $< -o $@

param.o: param.c Aleatorium.h
	$(CC) -c $< -o $@

pomme.o : pomme.c Aleatorium.h
	$(CC) -c $< -o $@

qpg.o: qpg.c Aleatorium.h
	$(CC) -c $< -o $@

rapidos.o : rapidos.c Aleatorium.h
	$(CC) -c $< -o $@

sauvegarde.o : sauvegarde.c Aleatorium.h
	$(CC) -c $< -o $@

trouvelemouton.o : trouvelemouton.c Aleatorium.h
	$(CC) -c $< -o $@


Aleatorium: main.o Jeu.o creationmap.o deplacement.o detecterdeplacement.o intro.o \
            menu.o minijeux.o outils.o param.o pomme.o qpg.o rapidos.o sauvegarde.o \
            trouvelemouton.o boss.o batum.o
	$(CC) $^ -o $@ -lncurses

effacer:
	rm main.o Jeu.o creationmap.o deplacement.o detecterdeplacement.o intro.o \
            menu.o minijeux.o outils.o param.o pomme.o qpg.o rapidos.o sauvegarde.o \
            trouvelemouton.o boss.o batum.o Aleatorium