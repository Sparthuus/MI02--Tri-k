#ifdef __linux__
    #include "Aleatorium.h"
#endif
void reglesmouton() {//Cette fonction donne uniquement les regles du jeu
	printf("\033[1;33m+===========================================================================+\033[0m\n");
	printf("Voici les règles du jeu:\n");
	printf("-Un cadrillage va s'afficher \n");
	printf("il va falloir que tu trouves les\033[1;32m 3 moutons cachés\033[0m\n");
	printf("Tu vas l'indiquer de la maniere suivante:\n");
	printf("  -tu dois ecrire seulement 2 caracteres les abscisses et les ordonnées.\n");

	printf("  -Il faut commencer par la lettre et ensuite le chiffre\n");
	printf("ex : la première case est A1, la sixième est B2 , etc\n");

	printf("-Fais attention à ne pas tomber nez à nez face au\033[1;31m loup \033[0msinon c'est perdu.\n");
	printf("-Lorsque tu indiques une case vide,\n");
	printf("une croix apparaitera et tu ne pourras plus accéder à cette case\n");

	printf("-Pour gagner tu dois me rapporter mes 3 moutons.\n");
	printf("\n\033[1;34mBonne chance!!!!!!!!!\033[0m\n");
	printf("\033[1;33m+==========================================================================+\033[0m\n");
}
void debut() {// Cette fonction donne le contexte et les regles du jeu
	effacer();
	printf("\033[1;34m+==========================\033[1;36mTROUVE LES 3 MOUTONS\033[1;34m============================+\033[0m\n");
	printf("Salut cher ami  je suis René l'agriculteur.\n");
	printf("Comme tu le sais bien tu vas devoir trouver \033[1;33mune clé\033[0m.\n");
	printf("Cette clé je la possède,\n");
	printf("mais avant que je te la donne j'aimerais que tu me rendes un petit service.\n");
	printf("3 de mes moutons se sont échappés de mon enclos la nuit dernière.\n");
	printf("Ses moutons sont toute ma vie.\n");
	printf("Je pense que tu commences à comprendre...\n");
	printf("Il va falloir que \033[1;32mtu retrouves ses 3 moutons et que tu me les rapportes.\033[0m\n");
	printf("Derniere petite chose fais attention \033[1;31mun loup\033[0m vit dans les parrages.\n");
	printf("Je te déconseille de le croiser si tu vois ce que je veux dire ....\n");
	printf("\033[1;34m+==========================================================================+\033[0m\n");
	continuer();
	effacer();
	reglesmouton();
	continuer();
}

void remplirtab(char tab[TAILLE2][TAILLE2]) {//Cette fonction construit le tableau
	tab[0][0] = ' ';
	for (int i = 1; i < TAILLE2; i++) {
		tab[0][i] = 'A' + i - 1;
	}
	for (int i = 1; i < TAILLE2; i++) {
		tab[i][0] = '1' + i - 1;
	}

	for (int i = 1; i < TAILLE2; i++) {
		for (int j = 1; j < TAILLE2; j++) {
			tab[i][j] = ' ';
		}
	}
}
void affichetab(char tab[TAILLE2][TAILLE2]) {//Cette fonction affiche le tableau 
	for (int i = 0; i < TAILLE2; i++) {
		for (int j = 0; j < TAILLE2; j++) {
			if (tab[i][j] == '8') {
				printf("\033[1;38m[🐑 ]\033[0m");
			}
			else if (tab[i][j] == '9') {
				printf("\033[1;38m[🐺 ]\033[0m");
			}
			else if (tab[i][j] == ' ') {
				printf("\033[1;38m[   ]\033[0m");
			}
			else {
				printf("\033[1;38m[ %c ]\033[0m", tab[i][j]);
			}
			
		}
		printf("\n");
	}
}
int conversion(char a) {//Cette fonction donne la positon d'une lettre dans l alphabet
	return a - '@';
}
int conversion2(char a) {
	return a - '0';//Cette fonction transforme un chiffre char en chiffre int
}
int veriftab(char tab[TAILLE2][TAILLE2], char casee[]) {//Cette fonction verifie si ce qui est tapé est bien correct.
	int a = 0;
	if (casee == NULL) {
		exit(1);
	}
	while (a == 0) {

		if (strlen(casee) != 2) {
			effacer();
			reglesmouton();
			affichetab(tab);
			printf("Il me faut juste la ligne et la colonne\n");
			return 1;
		}
		else if (casee[0] < 'A' || casee[0]>('A' + TAILLE2 - 2)) {
			effacer();
			reglesmouton();
			affichetab(tab);
			printf("La premiere case doit etre une lettre entre A et D\n");
			return 2;
		}
		else if (casee[1] < '1' || casee[1]>('1' + TAILLE2 - 2)) {
			effacer();
			reglesmouton();
			affichetab(tab);
			printf("La deuxieme case doit etre une valeur entre 1 et 4\n");
			return 3;
		}
		a++;
	}
	return 0;

}
int verifmouton(char tab[TAILLE2][TAILLE2], char tab2[TAILLE2][TAILLE2], char casee[]) {//Cette fonction verifie si la case choisi est deja prise et sinon rempli le tableau
	int x = conversion(casee[0]);
	int y = conversion2(casee[1]);
	while (tab2[y][x] == 'X' || tab2[y][x] == '8' || tab2[y][x] == '9') {
		effacer();
		reglesmouton();
		affichetab(tab2);
		printf("Tu as deja été sur cette case \n");
		scanf("%s", casee);
		x = conversion(casee[0]);
		y = conversion2(casee[1]);
		effacer();
		while (veriftab(tab2, casee) != 0) {

			scanf("%s", casee);
			x = conversion(casee[0]);
			y = conversion2(casee[1]);
		}
		
	}
	if (tab[y][x] == '8') {
		tab2[y][x] = '8';
		return 2;
	}
	else if (tab[y][x] == '9') {
		tab2[y][x] = '9';
		return 0;
	}
	else {
		tab2[y][x] = 'X';
		return 1;
	}
}
void moutons(char tab[TAILLE2][TAILLE2]) {//Cette fonction rempli un tableau avec des moutons et un loup de maniere aleatoire
	int alea = rand() % (TAILLE2 - 1) + 1;
	int alea2 = rand() % (TAILLE2 - 1) + 1;
	for (int i = 0; i < MOUTONS; i++) {
		tab[alea][alea2] = '8';
		alea = rand() % (TAILLE2 - 1) + 1;
		alea2 = rand() % (TAILLE2 - 1) + 1;
		while (tab[alea][alea2] == '8') {
			alea = rand() % (TAILLE2 - 1) + 1;
			alea2 = rand() % (TAILLE2 - 1) + 1;
		}
	}
	alea = rand() % (TAILLE2 - 1) + 1;
	alea2 = rand() % (TAILLE2 - 1) + 1;
	while (tab[alea][alea2] != ' ') {
		alea = rand() % (TAILLE2 - 1) + 1;
		alea2 = rand() % (TAILLE2 - 1) + 1;
	}
	tab[alea][alea2] = '9';


}
int trouvelemouton() {
	srand(time(NULL));
	char tab2[TAILLE2][TAILLE2];
	char casee[TAILLE3];
	char tab[TAILLE2][TAILLE2];
	int win = 0;
	char lettre;
	debut();
	effacer();
	reglesmouton();
	remplirtab(tab);
	affichetab(tab);
	remplirtab(tab2);
	moutons(tab);

	//affichetab(tab);
	int loose = 0;
	char c = ' ';
	while (win != 3 && loose == 0) {
		if (win > 1) {
			c = 's';
		}

		printf("Tu as trouvé\033[1;33m %d mouton%c\033[0m\n", win, c);
		printf("Donne moi ta case\n");
		scanf("%s", casee);
		effacer();

		while (veriftab(tab2, casee) != 0) {

			scanf("%s", casee);
		}
		int verifier = verifmouton(tab, tab2, casee);
		if (verifier == 1) {
			effacer();
			reglesmouton();
			affichetab(tab2);

			printf("Ta case ne contient ni un\033[1;33m mouton\033[0m ni le \033[1;31mloup \033[0mdonc recommences:\n");
			//affichetab(tab);

		}
		else if (verifier==0) {
			effacer();
			reglesmouton();
			affichetab(tab2);
			loose++;
		}
		else {
			effacer();
			reglesmouton();
			win++;
			affichetab(tab2);
		}
	}
	if (win == 3) {
		printf("Bravo tu as reussi l'epreuve trouve le mouton je te donne ta\033[1;33m cle\033[0m tu peux passer aux defi suivant\n");
		continuer();
		return 1;
	}
	else {
		printf("Le\033[1;31m loup \033[0mt'as mangé pas de bol mais pas de cle non plus\n");
		continuer();
		return 0;
	}


	
}
