
#ifdef _WIN32
	typedef struct {
		char nom[4];
		float attaque;
		float vie;
		float defense;
	}monstre1;
	typedef struct {
		char nom[4];
		float attaque;
		float vie;
		float defense;
	}boss;
	typedef struct {
		float attaque;
		float heal;
	}Ulti;
	typedef struct {
		char nom[100];
		float vie;
		float q;
		float e;
		Ulti r;
		int ult;
		int flash;
	}JoueurJeu;
#endif
#ifdef __linux__
	#include "Aleatorium.h"
#endif
JoueurJeu constructJoueurJeu(int combat) {
	JoueurJeu a;
	if (combat == 0) {
		a.vie = 100;
		a.q = 15;
		a.e = 15;
		a.ult = 1;
		a.flash = 1;
		a.r.attaque = 25;
		a.r.heal = 5;
	}
	else {
		a.vie = 200;
		a.q = 25;
		a.e = 25;
		a.ult = 1;
		a.flash = 1;
		a.r.attaque = 45;
		a.r.heal = 10;
	}
	return a;

}
monstre1 constructmonstre(int combat) {
	monstre1 b;
	//printf("Donne moi un nom pour le monstre\n");
	//scanf_s("%s", b.nom, 100);
	if (combat == 0) {
		b.nom[0] = 'R';
		b.nom[1] = 'e';
		b.nom[2] = 'n';
		b.nom[3] = 'e';
		b.vie = 100;
		b.attaque = 30;
		b.defense = 12;
	}
	else {
		//b.nom[3] = "Bob";
		b.nom[0]='B';
		b.nom[1]='o';
		b.nom[2]='b';
		b.nom[3]='\0';
		b.vie = 200;
		b.attaque = 45;
		b.defense = 20;
	
	}
	return b;
}

void phrasesalea(){
	int alea =rand()%8;
	switch(alea){
		case 0:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE SUIS MÉCHANT, ET CE N'EST PAS UNE BLAGUE !!!!!!");
		break;
		case 1:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : ABANDONNE ! MON TRIOMPHE EST INÉLUCTABLE !!!!!");
		break;
		case 2:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : LE CYCLE DE LA VIE ET DE LA MORT DOIT ÊTRE PRÉSERVÉ,\nJE VIVRAI, TU MOURRAS!!!!!");
		break;
		case 3:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : PLIC, PLOC, L'HEURE DE TA MORT A SONNÉ !!!!!!");
		break;
		case 4:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VEUX SAVOIR COMMENT JE ME SUIS FAIT CES CICATRICES ??????");
		break;
		case 5:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE SUIS VOTRE PIRE CAUCHEMAR !!!!!!");
		break;
		case 6:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : LA PITIÉ EST UNE FAIBLESSE RÉSERVÉE AUX FAIBLES !!!!!!");
		break;
		case 7:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS VOIR DE QUEL BOIS JE ME CHAUFFE !!!!!");
		break;
		case 8:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : ÇA VA ÊTRE TA FÊTE !!!!!");
		break;
		case 9:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS REGRETTER D'ÊTRE NÉ !!!!");
		break;
		case 10:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : LA VIE N'EST QU'UN JEU, ET JE SUIS\nLE SEUL À EN CONNAÎTRE LES RÈGLES !!!!");
		break;
		case 11:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE VAIS TE REFAIRE LE PORTRAIT !!!!!!");
		break;
		case 12:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : LE MAL TRIOMPHE TOUJOURS, PARCE QUE LE BIEN NE PEUT PAS FAIRE DE MAL !!!!!!");
		break;
		case 13:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : UN HOMME M'A UN JOUR DIT DE METTRE DES VÊTEMENTS.\nDONC J'AI PORTÉ SA PEAU AHAH !!!!!!");
		break;
		case 14:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE NE SUIS PAS TON ENNEMI, JE SUIS L'ENNEMI !!!!!!");
		break;
		case 15:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : DEMACIA !!!!!!");
		break;
		case 16:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : SI VOUS VOULEZ QUE JE VOUS FRAPPE MOINS, MOUREZ PLUS VITE !!!!!!");
		break;
		case 17:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : TOUT LE MONDE MEURT, CERTAINS ONT JUSTE\nBESOIN D'UN PEU D'AIDE !!!!!!");
		break;
		case 18:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS VOULEZ QUE JE JOUE ÉQUITABLEMENT ?\nMAIS NOUS NE JOUONS MÊME PAS AU MÊME JEU !!!!");
		break;
		case 19:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE N'AI TUÉ AUCUN HOMME QUI, AU DÉPART, NE MÉRITAIT D'ETRE TUÉ !!!!!!");
		break;
		case 20:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE METS LES PIEDS OÙ JE VEUX, ET C’EST SOUVENT) DANS LA GUEULE !!!!!!");
		break;
		case 21:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE VAIS TE REMETTRE AU RAYON SURGELÉ !!!!!!");
		break;
		case 22:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : JE METS LES PIEDS OÙ JE VEUX,\nET C’EST SOUVENT DANS LA GUEULE !!!!!!");
		break;
		case 23:
		printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VOIS, LE MONDE SE DIVISE EN DEUX CATÉGORIES,\nCEUX QUI ONT UN PISTOLET CHARGÉ ET CEUX QUI CREUSENT. TOI, TU CREUSES !!!!!");
		break;
	}
}
void introboss() { 
	//int monstres = MONSTRES;
	effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Bravo ! Tu es la première personne à avoir atteint la dernière salle !\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");	
	printf("\033[1;31m[🧐 BOB]\033[0m : Bravo ! Tu es la première personne à avoir atteint la dernière salle !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Mais avant de remporter le jackpott vous devez réussir le Fight club !\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");	
	printf("\033[1;31m[🧐 BOB]\033[0m : Bravo ! Tu es la première personne à avoir atteint la dernière salle !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Mais avant de remporter le jackpott vous devez réussir le Fight club !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Tu vas devoir te battre contre mon disciple René !\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");	
	printf("\033[1;31m[🧐 BOB]\033[0m : Bravo ! Tu es la première personne à avoir atteint la dernière salle !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Mais avant de remporter le jackpott vous devez réussir le Fight club !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Tu vas devoir te battre contre mon disciple René !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Alors oui ce défi est de taille mais c'est le dernier !\n");
		continuer();
	effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");	
	printf("\033[1;31m[🧐 BOB]\033[0m : Bravo ! Tu es la première personne à avoir atteint la dernière salle !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Mais avant de remporter le jackpott vous devez réussir le Fight club !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Tu vas devoir te battre contre mon disciple René !\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : Alors oui ce défi est de taille mais c'est le dernier !\n");	
	printf("\033[1;31m[🧐 BOB]\033[0m : Alors, es-tu prêt à te battre ?\n");
	continuer();
	effacer();
}
void reglesB(monstre1 c,JoueurJeu b,int a) {
	printf("\033[1;33m+==============================[\033[1;36mAleatorium club\033[1;33m]=============================+\033[0m\n");
	printf("-\033[1;31mRené va apparaitre et tu vas devoir le battre\033[0m.\n");
	printf("Pour cela tu auras \033[1;34m4 sorts\033[0m differents :\n\n");
	printf(" -Le\033[1;31m 1\033[0m est ton attaque : Il inflige\033[1;31m %.2f degats\033[0m.\n",b.q);
	printf("                         Tu pourra l'utiliser chaque\033[1;36m tour\033[0m.\n\n");
	printf(" -Le \033[1;32m2\033[0m est ton soin : il permet de reprendre\033[1;32m %.2f pv\033[0m.\n",b.e);
	printf("                      Tu pourra l'utiliser chaque\033[1;36m tour\033[0m.\n\n");
	printf(" -Le \033[1;33m3\033[0m est ton \033[1;33mflash\033[0m : Il permet d'empeches ton ennemi de jouer pendant %d \033[1;36mtour\033[0m.\n",TEMPSSOUSFLASH);
	printf("                        Tu pourra l'utiliser tout les %d \033[1;36mtours\033[0m.\n\n", COMPTEURFLASH);
	printf(" -Le \033[1;35m4\033[0m est ton ultime : Il te donne \033[1;32m%.2f pv\033[0m en plus et augmente ton\033[1;31m 1\033[0m de %.2f.\n", b.r.heal, b.r.attaque);
	printf("                        Tu pourra l'utiliser tout les %d\033[1;36m tours\033[0m.\n\n", COMPTEURULT);
	printf("\n%s peut attaquer ou défendre : \n",c.nom);
	printf(" -Son \033[1;31mattaque\033[0m t'enleve \033[1;31m%.2f \033[0m de pv\n",c.attaque);
	printf(" -Sa \033[1;32mdéfense \033[0mréduit ton 1 de \033[1;32m%.2f\033[0m  pour le prochain \033[1;36mtour\033[0m\n",c.defense);
	printf("\033[1;33m+===========================================================================+\033[0m\n");
	if (a == 0) {
		printf("                      \033[1;31mLe combat contre le boss va commencer\033[0m\n");
		continuer();
		effacer();
		a = 1;
	}
	

}
void fin() {
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS AVEZ TUÉ MON RENÉ ????????\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS AVEZ TUÉ MON RENÉ ????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS LE REGRETTER !!!!\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS AVEZ TUÉ MON RENÉ ????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS LE REGRETTER !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : PERSONNE A LE DROIT DE REMPORTER L'ALEATORIUM !!!!\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS AVEZ TUÉ MON RENÉ ????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS LE REGRETTER !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : PERSONNE A LE DROIT DE REMPORTER L'ALEATORIUM !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : EH OUI TOUT CELA EST UNE GRANDE ARNAQUE !!!!\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS AVEZ TUÉ MON RENÉ ????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS LE REGRETTER !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : PERSONNE A LE DROIT DE REMPORTER L'ALEATORIUM !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : EH OUI TOUT CELA EST UNE GRANDE ARNAQUE !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TOUT CE QUE TU VAS GAGNER, C'EST LA MORT !!!!\n");
		continuer();
		effacer();
	printf("\033[1;34m+==================================[\033[1;36mAleatorium club\033[1;34m]=============================+\033[0m\n");
	printf("\033[1;31m[🧐 BOB]\033[0m : QUUUUOOIIIII ???????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : VOUS AVEZ TUÉ MON RENÉ ????????\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS LE REGRETTER !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : PERSONNE A LE DROIT DE REMPORTER L'ALEATORIUM !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : EH OUI TOUT CELA EST UNE GRANDE ARNAQUE !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TOUT CE QUE TU VAS GAGNER, C'EST LA MORT !!!!\n");
	printf("\033[1;31m[👿 DARK BOB]\033[0m : TU VAS PAYER POUR LA MORT DE MON RENÉ !!!!\n");
	continuer();
	effacer();
}
int combat(monstre1 a, JoueurJeu b,int boss1) {
	int alea = 0;
	int choix;
	int round=0;
	int activeR=0;
	int tempssousR = 0;
	float attaqueini=b.q;
	float viie = b.vie;
	int tempsd = 0;
	int erreur = 0;
	int sorts1 = 0;
	int sorts2 = 0;
	int compteurult=0;
	int compteurflash = 0;
	int compteurflash2 = TEMPSSOUSFLASH+2;
	int compteurult2=TEMPSSOUSULT+2;
	int premier = 0;
	while (a.vie > 0 && b.vie > 0) {
		if (premier == 0) {
			reglesB(a,b, 1);
			premier = 1;
		}
		if (erreur == 0) {
			printf("                             \033[1;33m[Tour %d]\033[0m\n",round);
			printf("\033[1;36mInformations \033[0m%s : \n",b.nom);
			printf("╔══════════════════════════════╗ \n");
			printf("║\033[1;32mPV : %.2f\033[0m   \n",b.vie);
			printf("║\033[1;31m1) ATTAQUE : %.2f\033[0m \n",b.q);
			printf("║\033[1;32m2) SOIN : %.2f\033[0m  \n",b.e);
			printf("║\033[\033[1;33m3) FLASH : %d\033[0m \n",b.flash);
			printf("║\033[1;35m4) ULTIME : %d\033[0m  \n",b.ult);
			printf("╚══════════════════════════════╝\n");
			
			if(boss1==0){
				printf("                                    \033[1;36mInformations \033[0m%s : \n",a.nom);
			}
			else{
				printf("                                    \033[1;36mInformations \033[0m%s : \n",a.nom);
			}
			printf("                                    ╔══════════════════════════════╗ \n");
			printf("                                    ║\033[1;32mPV : %.2f\033[0m       \n" ,a.vie);
			printf("                                    ║\033[1;31mATTAQUE : %.2f \033[0m  \n", a.attaque);
			printf("                                    ║\033[1;33mDEFENSE : %.2f\033[0m \n", a.defense);
			printf("                                    ╚══════════════════════════════╝\n");
			if(boss1==1){
				phrasesalea();
			}
			printf("\n                        \033[1;33m[C'est ton tour]\033[0m");

		}
		
		erreur = 0;
		
		choix= verifscan(1,4);
		effacer();
		reglesB(a,b, 1);
		switch (choix) {
			
			case 1:
				
				if (b.ult == 0) {
				compteurult++;
				}
				if (b.flash == 0&&compteurflash2>TEMPSSOUSFLASH) {
					compteurflash++;
				}
			
				printf("%s decides d' \033[1;31mATTAQUER\033[0m ! %s perd \033[1;31m%.2f pv \033[0m !\n",b.nom, a.nom, b.q);;
				a.vie = a.vie - b.q;
				if (compteurult2 > TEMPSSOUSULT) {
					b.q = attaqueini;
				}
				else {
					printf("Tu as encore ton \033[1;35m4\033[0m donc profites en\n");
				}
				break;
			case 2:
				if (b.ult == 0) {
					compteurult++;
				}
				if (b.flash == 0&&compteurflash2>TEMPSSOUSFLASH) {
					compteurflash++;
				}
		
				printf("%s decides de se \033[1;32mSOIGNER\033[0m et gagne\033[1;32m %.2f pv !\033[0m\n",b.nom,b.r.heal);
				b.vie = b.vie + b.e;
				/*if (b.vie > viie) {
					b.vie =	viie;
				}*/
				if (compteurult2 > TEMPSSOUSULT) {
					b.q = attaqueini;
				}
				else {
					printf("Tu as encore ton \033[1;35m4\033[0m donc profites en\n");
				}
				break;

			case 4:
				if (b.flash == 0&&compteurflash2>TEMPSSOUSFLASH) {
					compteurflash++;
				}
				if (b.ult==0) {
					printf("Tu n'as plus ton \033[1;35mULTIME\033[0m tu ne peux pas l'utiliser !\n");
					erreur = 1;
				}
				else {
					printf("%s decides d'utiliser son \033[1;35mULTIME\033[0m! Il va devenir imbattable !!!!!\n",b.nom);
					b.q = b.q + b.r.attaque;
					b.vie = b.vie + b.r.heal;
					/*if (b.vie > viie) {
						b.vie = viie;
					}*/
					b.ult = 0;
					compteurult = 0;
					compteurult2 = 0;
				}
			
				break;
			case 3:
				if (b.ult == 0) {
					compteurult++;
				}
				if (b.flash==0) {
					printf("Tu n'as plus ton \033[1;33mFLASH\033[0m tu ne peux pas l'utiliser ! \n");
					erreur = 1;
				}
				else {
					printf("%s decides de \033[1;33mFLASH\033[0m et reussi à esquiver !\n",b.nom);
					b.flash = 0;
					compteurflash = 0;
					compteurflash2 = 0;
				}
				if (compteurult2 > TEMPSSOUSULT) {
					b.q = attaqueini;
				}

		}
		
		alea = rand() % 2;
		if (compteurflash2>TEMPSSOUSFLASH&&erreur==0) {
			if (alea == 0) {
				printf("-> %s decide \033[1;31md'attaquer\033[0m !\n", a.nom);
				b.vie = b.vie - a.attaque;
			}
			else {
				printf("-> %s prefere se \033[1;33mdefendre\033[0m !\n",a.nom);
				b.q = b.q - a.defense;
				if (b.q < 3) {
					b.q = 3;
				}
			}

		}
		if (b.flash == 0) {
			compteurflash2++;
		}
		if (b.ult == 0) {
			compteurult2++;
		}
		if (compteurult == COMPTEURULT) {
			b.ult = 1;
		}
		if (compteurflash == COMPTEURFLASH) {
			b.flash = 1;
		}
		
		//effacer();
		if(erreur==0){
			round++;
		}
		

	}
	if (boss1 == 0) {
		effacer();
		reglesB(a,b, 1);
		if (a.vie <= 0) {
			printf("\033[1;33m[RENE]\033[0m : On sait tous pertinemment qu'on va mourir un jour ou l'autre,\net pourtant on vit comme si on était immortel !\n");
			sleep(1);
			printf("\033[1;33m[RENE]\033[0m : Malgré l'affection qui nous unnissait. L'argent a fait de toi un monstre.!\n");
			sleep(1);
			printf("\033[1;33m[RENE]\033[0m : \033[1;31mMais...ahrghh...sache...Rghoo..que Bob est....argh....!\033[0m\n");
			sleep(1);
			printf("\033[1;33m[RENE]\033[0m : \033[1;32m\033[1;32mRené est mort.\033[0m \n");
			continuer();
			effacer();
			return 1;

		}
		else {
			printf("\033[1;31m[🧐 BOB]\033[0m : AHAHAHA je savais que mon René te batterais !\n");
			printf("\033[1;31m[🧐 BOB]\033[0m : Tu ne peux pas vaincre l'Aleatorium ! C'est impossible !\n");
			continuer();
			return 0;
		}
	}
	else {
		effacer();
		reglesB(a,b, 1);
		if (a.vie <= 0) {
			printf("\033[1;31m[👿 DARK BOB]\033[0m : Non... je.. je ne peux pas parti comme ça... !!\n");
			sleep(2);
			printf("\033[1;31m[👿 DARK BOB]\033[0m : QU'AS-TU FAIS ?!?!\n");
			sleep(2);
			printf("\033[1;31m[👿 DARK BOB]\033[0m : MON EMPIRE, MON CHEF-D'OEUVRE, MA GLOIREEE !!\n");
			sleep(2);
			printf("\033[1;31m[👿 DARK BOB]\033[0m : MEURT ! MORI IN INFERNO !!\n");
			tcflush(STDIN_FILENO, TCIFLUSH);
			continuer();
			return 1;
		}
		else {
			printf("\033[1;31m[👿 DARK BOB]\033[0m : JE SUIS BOOOB !!\n");
			sleep(2);
			printf("\033[1;31m[👿 DARK BOB]\033[0m : JE SUIS A L E A T O R I U M...\n");
			sleep(2);
			printf("\033[1;31m[👿 DARK BOB]\033[0m : AUCUNE FORCE EN CE MONDE NE PEUT DETRUIRE CE QUE JE SUIS !!\n");
			tcflush(STDIN_FILENO, TCIFLUSH);
			continuer();
			return 0;
		}
		
	}
	
	
}
int bossf(Joueur *joueur) {
	/*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
	srand(time(NULL));
	char copie[100];
	monstre1 a;
	JoueurJeu c;
	int res=0;
	c = constructJoueurJeu(0);
	a = constructmonstre(0);
	strcpy(c.nom, joueur->nom);
	introboss();
	reglesB(a,c,0);
	//printf("Donne moi ton pseudo pour jouer\n");
	//scanf("%s", c.nom);
	for (int i = 0; i < 100; i++) {
		copie[i] = c.nom[i];
	}
	//c = constructJoueurJeu();
	
	effacer();
	res = combat(a, c,0);
	if (res == 0) {
		return 0;
	}
	else {
		c = constructJoueurJeu(1);
		for (int i = 0; i < 100; i++) {
			c.nom[i]=copie[i];
		}
		fin();
		//reglesB(a,c, 0);
		a = constructmonstre(1);
		effacer();
		res=combat(a, c,1);
		if(res==1){
			gagne(joueur);
		}
		else{
			return 0;
		}
	}
	return 0;
}
