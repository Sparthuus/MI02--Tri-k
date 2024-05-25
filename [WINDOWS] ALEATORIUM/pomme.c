#ifdef __linux__
    #include "Aleatorium.h"
#endif
void afficheTab2D(char tab[TAILLE][TAILLE]) {// fonction pour afficher le tableau

	for (int j = 0; j < TAILLE; j++) {
	printf("                             ");
		for (int i = 0; i < TAILLE; i++) {
			if(tab[i][j]=='X'){
				printf("[🍎]");
			}
			else if(tab[i][j]=='O'){
				printf("[🍇]"); 
			}
			else{
				printf("[  ]");
			}
			

		}
		printf("\n");
	}
}

void regles(){
	printf("\033[1;34m+---------------------------\033[1;31mPomme raisin\033[1;34m---------------------------+\033[0m\n");
	printf("Bienvenue dans le jeu du pomme raisin\n");
	//printf("Voici les regles du jeu:\n");
	printf("-Tu dois gagner \033[1;31m3 manches.\033[0m\n");
	printf("-Il faut que tu reussisse a alligner \033[1;31m3 pommes\033[0m \n");
	printf("que se soit horizontale verticale ou diagonale.\n");
	printf("-Pour ce jeu on va simplifier les choses avec des chiffres :\n");
	printf("la premiere case sera associe au 1, deuxieme au 2,etc...jusqu a 9:\n");
	printf("[1][2][3]\n");
	printf("[4][5][6]\n");
	printf("[7][8][9]\n");
	printf("\033[1;34m+------------------------------------------------------------------+\033[0m\n");
}
int victoire(char tab[TAILLE][TAILLE]) {//fonction qui verifie si l'utilisateur a perdu ou gagner une manche ou fait egalite
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if ((tab[i][j] == tab[i + 1][j]) && (tab[i + 1][j] == tab[i + 2][j])) {
				if ((tab[i][j] == 'X')) {
					return 1;
				}
				else if ((tab[i][j] == 'O')) {
					return 2;
				}
			}
		}
	}
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < TAILLE; j++) {
			if ((tab[j][i] == tab[j][i + 1]) && (tab[j][i + 1] == tab[j][i + 2])) {
				if ((tab[j][i] == 'X')) {
					return 1;
				}
				else if ((tab[j][i] == 'O')) {
					return 2;
				}
			}
		}
	}

	if (((tab[0][0] == tab[1][1]) && (tab[1][1] == tab[2][2]))) {
		if (tab[0][0] == 'X') {
			return 1;
		}
		else if (tab[0][0] == 'O') {
			return 2;
		}

	}
	else if (((tab[0][2] == tab[1][1]) && (tab[1][1] == tab[2][0]))) {
		if (tab[0][2] == 'X') {
			return 1;
		}
		else if (tab[0][2] == 'O') {
			return 2;
		}
	}
	for (int j = 0; j < TAILLE; j++) {
		for (int i = 0; i < TAILLE; i++) {
			if (tab[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 3;
}
int joueurp(char tab[TAILLE][TAILLE], int a, int b) {//fonction qui fait le tour du joueurp
	while ((a < 1 || a>(TAILLE * TAILLE))) {
		a=verifscan(1,9);
	}

	if (tab[(a - 1) % TAILLE][(a - 1) / TAILLE] == 'X' || tab[(a - 1) % TAILLE][(a - 1) / TAILLE] == 'O') {
		return 0;
	}
	tab[(a - 1) % TAILLE][(a - 1) / TAILLE] = 'X' - b;
	return tab[TAILLE - 1][TAILLE - 1];

}
int Ordi(char tab[TAILLE][TAILLE]) {//fonction qui fait le tour de l ordi
	int choixOrdi = rand() % (TAILLE * TAILLE) + 1; 
	while (joueurp(tab, choixOrdi, TAILLE * TAILLE) == 0) {

		choixOrdi = rand() % (TAILLE * TAILLE) + 1;
	}

	return tab[TAILLE - 1][TAILLE - 1];
}
int ppartie(char tab[TAILLE][TAILLE], int choix2, int manche) {// fonction qui fait le derouler d'une partie
	for (int j = 0; j < TAILLE; j++) {
		for (int i = 0; i < TAILLE; i++) {
			tab[i][j] = ' ';
		}
	}
	afficheTab2D(tab);
	while (victoire(tab) == 0) {
		printf("Manche %d\n", manche);
		printf("A toi de jouer:\n");
		choix2=verifscan(1,9);
		while (joueurp(tab, choix2, 0) == 0) {
			printf("Erreur la case que tu as choisi est deja prise");
			choix2=verifscan(1,9);
		}
		effacer();
		regles();
		
		afficheTab2D(tab);
		if (victoire(tab) == 3) {
			return 3;
		}
		else if (victoire(tab) == 1) {
			return 1;
		}
		else if (victoire(tab) == 2) {
			return 2;
		}
		printf("L ordinateur joue:\n");
		Ordi(tab);

		afficheTab2D(tab);
		if (victoire(tab) == 2) {
			return 2;
		}
		else if (victoire(tab) == 3) {
			return 3;
		}
		manche++;

	}
}

int pommeraison() {
	effacer();
	int  choix2 = 0;
	int manche = 1;
	char tab[TAILLE][TAILLE];
	int partie = 1;
	int joueurp = 0;
	int ordi = 0;
	regles();
	continuer(); 
	while (partie != 4) {
		effacer();
		regles();
		printf("                      ");
		printf("La partie %d peut commencer\n", partie);
		printf("                                ");
		printf("%d - %d\n", joueurp, ordi);
		int respartie = ppartie(tab, choix2, manche);

		if (respartie == 1) {
			
			printf("Bien joue tu as gagnee la %d partie\n", partie);
			joueurp++;
			
			
		}
		else if (respartie == 3) {
			printf("il y a egalite\n");
		}

		else {

			printf("Ahahahahahah tu as perdu \n");

			ordi++;

		}
		if(joueurp==2){
		printf("%d - %d\n", joueurp, ordi);
		printf("Bravo tu remportes ce duel voici ta cle\n");
		continuer();
		return 1;
	}
	else if(ordi==2){
	printf("%d - %d\n", joueurp, ordi);
		printf("Bon tu as perdu tu n as donc pas la cle dommage\n");
		continuer();
		return 0;
	}
		continuer();
		partie++;
	}
	printf("%d - %d\n", joueurp, ordi);
	
	if (joueurp > ordi) {
		printf("Bravo tu remportes ce duel voici ta cle\n");
		continuer();
		return 1;
	}
	else if (joueurp < ordi) {
		printf("Bon tu as perdu tu n as donc pas la cle dommage\n");
		continuer();
		return 0;
	}
	else {
		printf("Tu as fais egalite il faut le battre tu n as donc pas la cle\n");
		continuer();
		return 0;
	}

	
}
