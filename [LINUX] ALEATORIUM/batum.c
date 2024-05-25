
#ifdef __linux__
    #include "Aleatorium.h"
#endif
void afficheTab2Dbatum(char tab[taille][taille]) {
	for (int j = 0; j < taille; j++) {
		for (int i = 0; i < taille; i++) {
			if (tab[i][j] == 'X') {
				printf("[🚤]", tab[i][j]);//mettre emoji bateau1
			}
			else if (tab[i][j] == 'Z') {
				printf("[🛶]", tab[i][j]);//mettre emoji d un autre bateau
			}
			else if (tab[i][j] == 'J') {
				printf("[🚢]", tab[i][j]);//mettre emoji d'un autre bateau
			}
			else if (tab[i][j] == '9') {
				printf("[❌]");
			}
			else if (tab[i][j] == 'T') {
				printf("[💥]");//mettre case valide
			}
			else {
				printf("[%c ]", tab[i][j]);
			}
		}
		printf("\n");
	}
}
void constructTab(char tab[taille][taille]) {
	tab[0][0] = ' ';
	for (int i = 1; i < taille; i++) {
		tab[i][0] = 'A' + (i - 1);
	}
	for (int i = 1; i < taille; i++) {
		tab[0][i] = '1' + (i - 1);
	}
	for (int j = 1; j < taille; j++) {
		for (int i = 1; i < taille; i++) {
			tab[i][j] = ' ';
		}
	}
}
void debutbato(int a) {
	char tabdemo[taille][taille];
	char tabdemo2[taille][taille];
	constructTab(tabdemo);
	constructTab(tabdemo2);
	printf("\033[1;34m+--------------------------------------------\033[1;31mNAVI BELLUM\033[1;34m----------------------------------------+\033[0m\n");
	printf("Dans \033[1;31mNAVI BELLUM\033[1;34m\033[0m, vous devez \033[0;32mdétruire\033[0m \033[4m\033[1;37mles trois bateaux\033[0m de votre adversaire.\n");
	printf("avant qu'il vous \033[1;31mdétruisent\033[0m vos trois bateaux !\n\n");
	printf("\033[4mPour placer votre bateau :\033[0m \n");
	printf("   - Tu indiquera en premier la lettre et le chiffre de la case.\n");
	printf("\033[0;31m[!]\033[0mAttention, les bateau doivent être placés soit \033[4mà la verticale\033[0m ou \033[4mà l'horizontale\033[0m\n");
	printf("   - Il existe 3 types de bateaux : 4 cases, 3 cases, 2 cases\n");
	printf("   - Si tu es bloqué ou tu veux replacer ton bateau :\nil suffit d'entrer la dernière case et les bateaux s'effaceront! \n");
	printf("\n- Il faut \033[0;32mremportez\033[0m une manche pour gagner la \033[1;33mclé\033[0m!\n\n");
	printf("\033[4mVoici un exemple :\033[0m \n\n");
	int ordi3();
	ordi3(tabdemo, tabdemo2, tabdemo2, tabdemo2);
	afficheTab2Dbatum(tabdemo);
	printf("\033[1;34m+-------------------------------------------------------------------------------------------+\033[0m\n");
	if (a == 0) {
		continuer();
		effacer();
	}
	
}

int conversion3(int a) {
	return a + '0';
}
int soustraction(char*** bateau,int k,int i) {
	return *(*(*(bateau + k) + i) + 0) - *(*(*(bateau + k)+0) + 0);
}
int soustraction2(char*** bateau, int k, int i) {
	return *(*(*(bateau + k) + i) + 1) - *(*(*(bateau + k)) + 1);
}
int verifbateau(char tab[taille][taille],char ***bateau, int taillebateau, int i,int k,int poschar,int posint) {
	int a = 0;
	
	while (a == 0) {
		
		if (strlen(*(*(bateau + k) + i)) != 2) {
			afficheTab2Dbatum(tab);
			printf("Recommences la case ne contient pas le bon nombre de caracteres,il en faut 2.\n "); 
			return 1;
		}
		else if (*(*(*(bateau + k) + i) + 0) < 'A' || *(*(*(bateau + k) + i)+0) > ('A' + (taille - 2))) {
			afficheTab2Dbatum(tab);
			printf("Recommences il faut que la case commence par une lettre compris entre A et %c\n", 'A' + (taille - 2));
			
			return 2;
		}
		else if (*(*(*(bateau + k) + i) + 1) < '1' || *(*(*(bateau + k) + i) + 1) > '1' + (taille - 2)) {
			afficheTab2Dbatum(tab);
		printf("Recommences il faut que la case finisse par un chiffre compris entre 1 et %c\n", '1' + (taille - 2));

			return 3;
		}
		if (i > 0) {
			if (soustraction(bateau, k, i) != 0 && soustraction2(bateau, k, i) != 0) {
				if (tab[poschar][posint] == ' ') {
					afficheTab2Dbatum(tab);
					printf("\033[0;31m[!]\033[0mErreur recommences tes cases ne sont pas alignés (tu ne peux pas faire de diagonales)\n");
					return 4;
				}
			}
			else if (soustraction(bateau, k, i) <= -taillebateau || soustraction(bateau, k, i) >= taillebateau) {
				if (tab[poschar][posint] == ' ') {
					afficheTab2Dbatum(tab);

					printf("\033[0;31m[!]\033[0mErreur ton bateau fais %d cases\n", taillebateau);
					return 5;
				}
			}
			else if (soustraction2(bateau, k, i) <= -taillebateau || soustraction2(bateau, k, i) >= taillebateau) {
				if (tab[poschar][posint] == ' ') {
					afficheTab2Dbatum(tab);

					printf("\033[0;31m[!]\033[0mErreur ton bateau fais %d cases\n", taillebateau);
					return 5;
				}
			}
			if (i > 1) {
				if (soustraction(bateau, k, i-1) != 0&& soustraction2(bateau, k, i-1) == 0) {
					if (*(*(*(bateau + k) + i) + 1) != *(*(*(bateau + k)) + 1)) {
						if (tab[poschar][posint] == ' ') {
							afficheTab2Dbatum(tab);
							printf("\033[0;31m[!]\033[0mErreur recommences tes cases ne sont pas alignés (tu ne peux pas faire de diagonales)\n");
							return 4;
						}
					}
					else {
						a++;
					}
				}
				else if (soustraction(bateau, k, i-1) == 0 && soustraction2(bateau, k, i-1) != 0) {
					if (*(*(*(bateau + k) + i) + 0) != *(*(*(bateau + k)) + 0)) {
						if (tab[poschar][posint] == ' ') {
							afficheTab2Dbatum(tab);
							printf("\033[0;31m[!]\033[0mErreur recommences tes cases ne sont pas alignes (tu ne peux pas faire de diagonales)\n");
							return 4;
						}
					}
					else {
						a++;
					}
				}
				else {
					a++;
				}
			}
			else {
				a++;
			}
		}
		else {
			a++;
			
		}
		
	}
	return 0;	
}
int casePrise(char tab[taille][taille], int poschar, int posint,int k) {
	if (tab[poschar][posint] == 'X'|| tab[poschar][posint]=='9'|| tab[poschar][posint] == 'T'|| tab[poschar][posint]=='J'|| tab[poschar][posint]=='Z') {
		effacer();
		debutbato(1);
		afficheTab2Dbatum(tab);
		printf("\033[0;31m[!]\033[0mErreur case deja prise\n");
		return 0;
	}
	if (k == 0) {
		tab[poschar][posint] = 'X';
	}
	else if (k == 1) {
		tab[poschar][posint] = 'J';
	}
	else {
		tab[poschar][posint] = 'Z';
	}
	return tab[taille-1][taille-1];
}


void creebateau(char tab[taille][taille],int taillebateau, int sens, int direction, int abscisse, int ordonnee,int k) {
	for (int i = 0; i < taillebateau; i++) {
		if (direction == 0) {
			if (sens == 0) {
				
					tab[abscisse + i][ordonnee] = 'X';
				
				
			}
			else {
				
					tab[abscisse - i][ordonnee] = 'X';
				
				
			}
		}
		else {
			if (sens == 0) {
			
					tab[abscisse][ordonnee+i] = 'X';
				
			}
			else {
				
					tab[abscisse][ordonnee-i] = 'X';
				
				
			}
		}
	}
}
int verifbateauu(char tab[taille][taille], int taillebateau, int sens, int direction,int abscisse,int ordonnee){
	for (int i = 0; i < taillebateau; i++) {
		if (direction == 0) {
			if (sens == 0) {
				if (tab[abscisse+i][ordonnee] != ' ') {
					return 1;
				}
			}
			else {
				if (tab[abscisse - i][ordonnee] != ' ') {
					return 1;
				}
			}
		}
		else {
			if (sens == 0) {
				if (tab[abscisse][ordonnee+i] != ' ') {
					return 1;
				}
			}
			else {
				if (tab[abscisse][ordonnee-i] != ' ') {
					return 1;
				}
			}
		}
	}
	return 0;
}
int ordi3(char tab[taille][taille],char tabpremierbateau[taille][taille], char tabsecondbateau[taille][taille], char tabtroisiemebateau[taille][taille]) {
	srand(time(NULL));
	int taillebateau = taille - 2;
	int abscisse;
	int ordonnee;
	int alea;
	int sens;
	for (int k = 0; k < 3; k++) {
		abscisse =  1+ rand() % 5;
		ordonnee = 1 + rand() % 5;
		alea = rand() % 2;
		sens = rand() % 2;
		while (verifbateauu(tab,taillebateau,sens,alea,abscisse,ordonnee) == 1) {
			abscisse = 1 + rand() % 5;
			ordonnee = 1 + rand() % 5;
			alea = rand() % 2;
			sens = rand() % 2;
		}
		if (verifbateauu(tab, taillebateau, sens, alea, abscisse, ordonnee) == 0) {
			creebateau(tab, taillebateau, sens, alea, abscisse, ordonnee,k);
		}
		taillebateau--;
		for (int j = 0; j < taille; j++) {
			for (int i = 0; i < taille; i++) {
				if (k == 0) {
					tabpremierbateau[i][j] = tab[i][j];
				}
				else if (k == 1) {
					tabsecondbateau[i][j] = tab[i][j];
				}
				else {
					tabtroisiemebateau[i][j] = tab[i][j];
				}
			}
		}
		//afficheTab2Dbatum(tab);
	}
}
int veriftabgagne(char tab[taille][taille]) {
	int nombre = 0;
	for (int j = 1; j < taille; j++) {
		for (int i = 1; i < taille; i++) {
			if (tab[i][j] == 'T') {
				nombre++;
			}
		}
	}
	if (nombre == 9) {
		return 1;
	}
	return 0;
}
int veriftperdu(char tab[taille][taille]) {
	int nombre = 0;
	for (int j = 1; j < taille; j++) {
		for (int i = 1; i < taille; i++) {
			if (tab[i][j] == 'X'||tab[i][j] == 'J'||tab[i][j] == 'Z') {
				return 1;
			}
		}
	}
	return 0;
}
int verifOrdi(char tab[taille][taille],int abscisse,int ordonnee) {
	for (int i = 0; i < 1; i++) {
		if (tab[abscisse+i][ordonnee] == 'X') {
			tab[abscisse+i][ordonnee] = 'T';
			return 1;
		}
		else if (tab[abscisse-i][ordonnee] == 'X') {
			tab[abscisse-i][ordonnee] = 'T';
			return 2;
		}
		else if (tab[abscisse][ordonnee+i] == 'X') {
			tab[abscisse][ordonnee+i] = 'T';
			return 3;
		}
		else if (tab[abscisse][ordonnee-i] == 'X') {
			tab[abscisse][ordonnee-i] = 'T';
			return 4;
		}
	}
	return 0;
	
}
int comparerchaquebateau(char tab[taille][taille],char tab1[taille][taille],int taillebateau) {
	int compte = 0;
	for (int j = 0; j < taille; j++) {
		for (int i = 0; i < taille; i++) {
			if (tab[i][j] == 'X') {
				if (tab1[i][j]=='T') {
					compte++;
				}
			}
		
		}
	}
	if (compte == taillebateau) {
		return 1;
	}
	return 0;
}
int ordi2(char tab[taille][taille]) {
	srand(time(NULL));
	int taillebateau = taille - 2;
	int essai = 1;
	int abscisse;
	int ordonnee;
	for (int i = 0; i < essai; i++) {
		abscisse = 1 + rand() % 5;
		ordonnee = 1 + rand() % 5;
			if(tab[abscisse][ordonnee] == 'X'|| tab[abscisse][ordonnee]=='J'|| tab[abscisse][ordonnee]=='Z') {
				tab[abscisse][ordonnee] = 'T';
				afficheTab2Dbatum(tab);
				printf("\033[1;31mL'adversaire a toucher un de tes bateaux\033[0m\n");
				return 1;
			}
			if (tab[abscisse][ordonnee] == ' ') {
				tab[abscisse][ordonnee] = '9';
				afficheTab2Dbatum(tab);
				printf("\033[1;32mL'adversaire n'a pas réussi toucher un de tes bateaux\033[0m\n");
				sleep(2);
			}
			else if (tab[abscisse][ordonnee] == 'T') {
				i--;
			}
			else if (tab[abscisse][ordonnee] == '9') {
				i--;
			}
	}
	return 0;
}
int verifreponse(char tab[taille][taille],char casee[2]) {
	int a = 0;
	effacer();
	afficheTab2Dbatum(tab);
	while (a == 0) {
		if (strlen(casee) != 2) {
			printf("\033[0;31m[!]\033[0mErreur il faut donner une lettre et un chiffre uniquement:\n");
			return 1;
		}
		else if (casee[0]<'A' || casee[0]> ('A' + (taille - 2))) {
			printf("Recommences il faut que la case commence par une lettre compris entre A et %c\n", 'A' + (taille - 2));
			return 2;
		}
		else if (casee[1]<'1' || casee[1]> ('1' + (taille - 2))) {
			printf("Recommences il faut que la case finisse par un chiffre compris entre 1 et %c\n", '1' + (taille - 2));
			return 3;
		}
		a++;
	}
	return 0;
}
int comparetab(char tab[taille][taille], char tab2[taille][taille], int poschar,int posint) {
	if (tab[poschar][posint] == tab2[poschar][posint]) {
		return 1;
	}
	return 0;
}
int distance(char tab[taille][taille], int poschar, int posint, int taillebateau) {
	for (int i = 1; i < taillebateau;i++) {
		if (tab[poschar + i][posint] == ' ') {
			return 1;
		}
		else if (tab[poschar - i][posint] == ' ') {
			return 1;
		}
		else if (tab[poschar][posint+i] == ' ') {
			return 1;
		}
		else if (tab[poschar][posint-i] == ' ') {
			return 1;
		}

	}
	printf("\033[0;31m[!]\033[0mTu ne peux pas !\n");
	tab[poschar][posint] = ' ';
	return 0;
}
int verifdisp(char*** bateau,int taillebateau,int poschar,int posint) {
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < taillebateau; i++) {
			if (conversion(*(*(*(bateau)+i) + 0)) == poschar && conversion2(*(*(*(bateau)+i) + 1)) == posint) {
				return 1;
			}
			 
		}
	}
	return 0;
}
int  destructBateau(char tab[taille][taille],char ***bateau,int poschar,int posint,int taillebateau,int k,int i ){

			if (tab[poschar][posint] == 'X') {
				for (int j = 0; j < taille; j++) {
					for (int t = 0; t < taille; t++) {
						if (tab[t][j] == 'X'||tab[t][j]=='J'||tab[t][j]=='Z') {
							tab[t][j] = ' ';
						}
					}
				}
				return 1;
			}
			else if (tab[poschar][posint] == 'J') {
				for (int j = 0; j < taille; j++) {
					for (int t = 0; t < taille; t++) {
						if (tab[t][j] == 'J' || tab[t][j] == 'Z') {
							tab[t][j] = ' ';
						}
					}
				}
				return 2;
			}
			else if (tab[poschar][posint] == 'Z') {
				for (int j = 0; j < taille; j++) {
					for (int t = 0; t < taille; t++) {
						if (tab[t][j] == 'Z') {
							tab[t][j] = ' ';
						}
					}
				}
				return 3;
			}
		
	
}
int batum() {
	effacer();
	int manche = 1;
	srand(time(NULL));
	char casee[3];
	char ***bateau =NULL;
	int taillebateau = taille - 2;
	bateau = malloc(3 * sizeof(char**));
	if (bateau == NULL) {
		printf("Erreur\n");
		exit(1);
	}
	char tab[taille][taille];
	char tab2[taille][taille];
	char tab3[taille][taille];
	constructTab(tab);
	constructTab(tab2);
	constructTab(tab3);
	char choix=0;
	int passer = 0;
	int increment = 0;
	debutbato(0);
	while (manche < MANCHE+1) {
		taillebateau = taille - 2;
		constructTab(tab);
		constructTab(tab2);
		constructTab(tab3);
		debutbato(1);
		printf("\033[4mBienvenue dans la manche %d !\033[0m\n", manche);
		printf("\n");
		afficheTab2Dbatum(tab);
		

		for (int k = 0; k < 3; k++) {
			printf("\nPlace le bateau contenant %d cases :\n", taillebateau);
			
			*(bateau + k) = malloc((taillebateau) * sizeof(char*));
			if (*(bateau + k) == NULL) {
				printf("erreur \n");
				exit(2);
			}
			for (int i = 0; i < taillebateau; i++) {
				*(*(bateau + k) + i) = malloc(3 * sizeof(char));
				if (*(*(bateau + k) + i) == NULL) {
					printf("erreur \n");
					exit(2);
				}
				int a = 0;
				
				tcflush(STDIN_FILENO, TCIFLUSH);
				scanf("%s", *(*(bateau + k) + i));
				int poschar = conversion(*(*(*(bateau + k) + i) + 0));
				int posint = conversion2(*(*(*(bateau + k) + i) + 1));
			
				effacer();
				debutbato(1);
			

				while (verifbateau(tab,bateau, taillebateau, i, k,poschar,posint) != 0) {//|| distance(tab, poschar, posint, taillebateau) == 0
					tcflush(STDIN_FILENO, TCIFLUSH);
					scanf("%s", *(*(bateau + k) + i));
					effacer();
					debutbato(1);
					poschar = conversion(*(*(*(bateau + k) + i) + 0));
					posint = conversion2(*(*(*(bateau + k) + i) + 1));
				}
				if ((casePrise(tab, poschar, posint,k) == 0) || passer == 1) {
					printf("\033[1;37mTon bateau s'est effacé tu dois recommencer !\033[0m\n");
					int destruc = destructBateau(tab, bateau, poschar, posint, taillebateau, k, i);
					i = taillebateau + 15;
					if (destruc == 1) {
						taillebateau = 5;
						k = -1;
						
					}
					else if (destruc == 2) {
						taillebateau = 4;
						k = 0;
						
					}
					else {
						taillebateau = 3;
						k=1;
						
					}
				}
				afficheTab2Dbatum(tab);
				if (i != taillebateau-1) {
					printf("Place ta nouvele case !\n");
				}
			}

			taillebateau--;
		}
		char premierbateau[taille][taille];
		char secondbateau[taille][taille];
		char troisiemebateau[taille][taille];
		ordi3(tab2,premierbateau,secondbateau,troisiemebateau);
		//afficheTab2Dbatum(tab2);
		effacer();
		debutbato(1);
		printf("l'adversaire a placé ses bateaux : \n");
		while (veriftperdu(tab) == 1 && veriftabgagne(tab3) == 0) {
			int rejouer = 0;
			int poschar2;
			int posint2;
			int rescompare = 1;
			int k = 0;
			effacer();
			debutbato(1);
			printf("L'adversaire joue:\n");
			while (ordi2(tab) == 1&&veriftperdu(tab) == 1) {
				sleep(2);
				effacer();
				debutbato(1);
				printf("L'adversaire recommence\n");
			}
			
			while (rescompare == 1 && veriftabgagne(tab3)==0 && veriftperdu(tab) == 1) {
				afficheTab2Dbatum(tab3);
				if (rejouer == 0) {
					printf("A toi de jouer :\n");
					rejouer++;
				}
				else {
					printf("\033[1;32mBien joué tu as trouve une case tu peux rejouer\033[0m\n");
				}
				tcflush(STDIN_FILENO, TCIFLUSH);
				scanf("%s", casee);
				poschar2 = conversion(casee[0]);
				posint2 = conversion2(casee[1]);
				while (verifreponse(tab3, casee) != 0 || casePrise(tab3, poschar2, posint2,k) == 0) {
					tcflush(STDIN_FILENO, TCIFLUSH);
					scanf("%s", casee);
					poschar2 = conversion(casee[0]);
					posint2 = conversion2(casee[1]);
				}
				effacer();
				debutbato(1);
				rescompare= comparetab(tab2, tab3, poschar2, posint2);
				if (rescompare == 1) {
					tab3[poschar2][posint2] = 'T';
				}
				else {
					tab3[poschar2][posint2] = '9';
					afficheTab2Dbatum(tab3);
					printf("\033[1;31mDommage il n'y pas de bateau ici !\033[0m\n");
					sleep(2);
					effacer();
				}	
			}
			
		}
		if (veriftperdu(tab) == 0) {
			effacer();
			debutbato(1);
			afficheTab2Dbatum(tab);
			printf("\033[1;31mBon tu as perdu l'adversaire a coulé tout tes bateaux\033[0m\n");
			continuer();
			return 0;
		}
		else if(veriftabgagne(tab3)==1) {
			effacer();
			debutbato(1);
			afficheTab2Dbatum(tab3);
			printf("\033[1;32mBon bah tu as gagnee tout les bateaux adverses ont été coulés\033[0m\n");
			continuer();
			return 1;
			
		}
		manche++;
	}
	


	return 0;
}