/*Jeux*/
    #ifdef _WIN32
        #include "rapidos.c"
        #include "pomme.c"
        #include "trouvelemouton.c"
        #include "qpg.c"
        #include "batum.c"
    #endif
    #ifdef __linux__
        #include "Aleatorium.h"
    #endif
    int pileouface(){
        
        int manche=1;
        int victoire=0;
        do{
            effacer();
            printf("\n+==============================================================+\n");
            printf("                 \033[4m\033[1;31m[Bienvenue à SOLEIL ou LUNE]\033[0m\n\n"); 
            printf("Dans \033[1;33mSOLEIL\033[0m ou \033[1;30mLUNE\033[0m, choisissez entre \033[1;33mSOLEIL\033[0m ou \033[1;30mLUNE\033[0m,\n");
            printf("Si votre réponse \033[4mcorrespond\033[0m à celle du maître du jeu,\n");
            printf("vous \033[0;32mremportez\033[0m la partie ! Dans le cas contraire, vous \033[0;31mperdez\033[0m !\n");
            printf("\033[0;31m[!]\033[0mAttention, vous n'avez que 3 manches pour en remporter une !");
            printf("\n+==============================================================+\n");
            printf("                         [Manche %d]\n",manche);
            printf("          Que choisissez vous entre \033[1;33mSOLEIL\033[0m OU \033[1;30mLUNE\033[0m ?\n");
            printf("           ╔══════════╗               ╔══════════╗\n");
            printf("           ║ 1 \033[1;33mSOLEIL\033[0m ║               ║ 2  \033[1;30mLUNE\033[0m  ║\n");
            printf("           ╚══════════╝               ╚══════════╝\n");
            if(manche!=1){
                printf("Oh non vous avez \033[1;31mPERDU\033[0m! Il vous reste %d chances.\n",4-manche);
            }
            int piece=1+rand()%2;
            int tentative=verifscan(1,2);
            if(tentative==piece){
                victoire=1;
            }
            else{
                manche++;
            }
            
        }while(manche<=3&&victoire!=1);
        char inutile;
        if(victoire==0){
            printf("\033[0;31m                Dommage vous perdez la partie !\n\n\033[0m");
            continuer();
            return 0; //Defaite
        }
        else{
            printf("\033[0;32m                  Bravo vous remportez la partie !\n\n\033[0m");
            continuer();
            return 1; //Victoire
        }
        
    }
    int calcul(){
        int manche=1;
        int victoire=0,tentative=0;
        int manchegagnee=0;
        void reglemaths(){
            printf("\n+=================================================================+\n");
            printf("                 \033[4m\033[1;31m[Bienvenue à ÉCLAIR MATHÉMATIQUES]\033[0m\n\n"); 
            printf("Dans \033[0;33mÉclair Mathématiques\033[0m, vous allez être confronté à \033[4m5 calculs\033[0m,\n");
            printf("Si vous trouvez \033[1m2 bonnes réponses\033[0m vous \033[0;32mremportez\033[0m la partie !\n");
            printf("Dans le cas contraire, vous \033[0;31mperdez\033[0m la partie!\n");
            printf("\033[0;31m[!]\033[0mAttention, vous n'avez que \033[1m3 secondes\033[0m pour retenir le calcul !");
            printf("\n+=================================================================+\n");
        }
        do{
            /*Début de la partie*/
                effacer();
                reglemaths();
                if(manche!=1){
                    if(manchegagnee){
                        printf("     Bravo ! Vous \033[0;32mREMPORTEZ\033[0m la manche, il vous en manque une !\n");
                    }
                    else{
                        printf("           Oh non vous avez \033[1;31mPERDU\033[0m! Il vous reste %d chances.\n",6-manche);
                    } 
                }
                continuer();
                
            /*Gténération d'un calcul*/
                int x,y;
                x=rand()%51;
                y=rand()%51;

            /*Affichage du calcul et décompte*/
            printf("                    [Manche \033[0;31m%d\033[0m | \033[0;32m%d\033[0m bonne réponse]\n\n",manche,victoire);
            printf("                            \033[1m %d + %d\033[0m\n",x,y);
            printf("+-----------------------------------------------------------------+\n");
            fflush(stdout);
            printf("                                \033[1m3\033[0m\n");
            sleep(1);
            printf("                                \033[1m2\033[0m\n");
            sleep(1);
            printf("                                \033[1m1\033[0m\n");
            sleep(1);
            /*Fin du décompte*/
            effacer();
            reglemaths();
            printf("                    [Manche \033[0;31m%d\033[0m | \033[0;32m%d\033[0m bonne réponse]\n\n",manche,victoire);
            printf("                            \033[1m XX + YY\033[0m\n",x,y);
            //tcflush(STDIN_FILENO, TCIFLUSH);
            tentative=verifscan(0,100);
            if(tentative==x+y){
                victoire++;
                manche++;
                manchegagnee=1;
            }
            else{
                manche++;
                manchegagnee=0;
            }
            
        }while(manche<=5&&victoire!=2);
        char inutile;
        if(victoire!=2){
            printf("\033[0;31m                Dommage vous perdez la partie !\n\n\033[0m");
            continuer();
            return 0; //Defaite
        }
        else{
            printf("\033[0;32m                  Bravo vous remportez la partie !\n\n\033[0m");
            continuer();
            return 1; //Victoire
        }
    }
    int prv(){
        int manche=1, victoireJ=0, victoireO=0, choixOrdi=0; //declaration variables
        int* pvictoireJ = &victoireJ;                        //declaration pointeurs pour pouvoir modifier les points
        int* pvictoireO = &victoireO; 

        void afficher4(){            //Explication règle du jeu
            printf("\n+------------- \033[4m\033[1;31mBienvenue dans Poule Renard Vipère !\033[0m --------------+\n");
            printf("\nVoici les regles : \n - Il faut remporter \033[1;33m3 Manches\033[0m pour gagner\n - \033[1;31mLe Renard\033[0m🦊 mange \033[1;30mla Poule\033[0m🐔, \033[1;30mla Poule\033[0m🐔 picore \033[0;32mla Vipère\033[0m🐍\net \033[0;32mla Vipère\033[0m🐍 mord \033[1;31mle Renard\033[0m🦊\n");
            printf(" - Pour simplifier, on utilisera les chiffres 1, 2 et 3 \nqui désignent");
            printf(" respectivement \033[1;31mLe Renard\033[0m(1)🦊, \033[1;30mla Poule\033[0m(2)🐔\n et \033[0;32mla Vipère\033[0m(3)🐍\n");
            printf(" - Si le maître du jeu a pris le même animal, il y a égalité\n");
            printf("+-----------------------------------------------------------------+\n\n");  
        }

        int choixJoueur(int victoire, int defaite){ //Fonction pour afficher et enregistrer le choix du Joueur
                int choixJ;
                printf("+============= \033[4m\033[1;31mManche %d\033[0m : Choisissez votre animal ! ==============+\n", manche);
        printf("╔═══════════════╗     ╔═════════════════════════════╗ \n");
                printf("║ 1 => \033[1;31mRenard\033[0m🦊 ║     ║ Victoire Joueur : %d         ║ \n", victoire);
                printf("║ 2 => \033[1;30mPoule\033[0m🐔  ║     ║                             ║\n");
                printf("║ 3 => \033[0;32mVipère\033[0m🐍 ║     ║ Victoire Maître du jeu : %d  ║\n", defaite);
                printf("╚═══════════════╝     ╚═════════════════════════════╝\n");
                printf("+=================================================================+\n");
                choixJ=verifscan(1,3);
            
                switch (choixJ) {
                case 1:
                        printf("\nVous avez choisit : \033[1;31mle Renard\033[0m🦊\n");
                    break;
                case 2:
                    printf("\nVous avez choisit : \033[1;30mla Poule\033[0m🐔\n");
                    break;
                case 3:
                    printf("\nVous avez choisit : \033[0;32mla Vipère\033[0m🐍\n");
                    break;
                }
                return choixJ;
            }
            int choixOrdinateur(int choixJ) {  // Fonction pour afficher le choix de l'ordinateur
            srand(time(NULL));        
            int choix = rand() % (3-1+1)+1;  // Génère un nombre aléatoire entre 1 et 3
            switch (choix) {
                case 1:
                    printf("\nLe maître du jeu choisit : \033[1;31mle Renard\033[0m🦊\n");
                    break;
                case 2:
                    printf("\nLe maître du jeu choisit : \033[1;30mla Poule\033[0m🐔\n");
                    break;
                case 3:
                    printf("\nLe maître du jeu choisit : \033[0;32mla Vipère\033[0m🐍\n");
                    break;
            }
            return choix;
            }
            int determinerGagnant(int choixJoueur, int choixOrdi){ // Fonction pour déterminer le gagnant de la partie
                if (choixJoueur == choixOrdi)                       // 0 pour égalité, 1 pour joueur gagnant, -1 pour ordinateur gagnant
                    return 0;
                else if ((choixJoueur == 1 && choixOrdi == 2) || (choixJoueur == 2 && choixOrdi == 3) || (choixJoueur == 3 && choixOrdi == 1))
                    return 1;
                else
                    return -1;
            }
            int gagnant(int c, int *J, int *O){ //Fonction pour déterminer le gagnant de la manche et comptabiliser les manches gagnées
                if (c == 0){
                        printf("\nÉgalité !\n");
                } else if (c == 1){
                    printf("\n\033[1;33m✅Vous avez gagné cette manche!\033[0m\n");
                    *J+=1;
                } else {
                    printf("\n\033[1;31m❌Le maître du jeu a gagné la manche !\033[0m\n");
                    *O+=1;
                }
                    
            }
                
            do{
                effacer();
                afficher4();
                int choixJ = choixJoueur(victoireJ, victoireO);
                printf("                        vs");
                int choixOrdi = choixOrdinateur(choixJ);
                int resultat = determinerGagnant(choixJ, choixOrdi);
                gagnant(resultat, pvictoireJ, pvictoireO);
                manche++;
                continuer();

            }while(victoireJ<3 && victoireO<3);
            
            if (victoireJ == 3){ //Affiche qui a gagné le jeu
                printf("\033[1;33mVous avez gagné !🎉\033[0m\n");
                continuer();
                return 1; //Victoire
            } else {
                printf("\033[1;31mVous avez perdu !😱\033[0m\n");
                continuer();
                return 0; //Defaite
            }
    }
    int tictac() {
        int nombreMystere, nombreJoueur, essais = 0;
        int min = 1, max = 100;
        int result=303;
        void reglejuste(){
            printf("\n+==============================================================+\n");
            printf("                 \033[4m\033[1;31m[Bienvenue au Tic Tac Prix]\033[0m\n\n"); 
            printf("- Dans \033[0;35mTic Tac Prix\033[0m vous devez deviner un nombre entre \033[1;37m1\033[0m et \033[1;37m100\033[0m\n");
            printf("- Si votre réponse \033[4mcorrespond\033[0m à celle du maître du jeu,\n");
            printf("vous \033[0;32mgagnez\033[0m la partie et la clé ! Dans le \033[1;31mcas contraire\033[0m,\n");
            printf("aidez vous \033[4mdes indices\033[0m pour le trouver (\033[1;32mPLUS\033[0m OU \033[1;34mMOINS\033[0m) !\n");
            printf("\033[0;31m[!]\033[0mAttention, vous avez \033[1;37m\033[4m7 essais\033[0m ou vous \033[1;31mperdez\033[0m la partie !");
            printf("\n+==============================================================+\n");
        }
        // Génération du nombre mystère
        nombreMystere = (rand() % (max - min + 1)) + min;
        effacer();
        reglejuste();
        continuer();
        
        // Boucle du jeu
        do {
            effacer();
            reglejuste();
            printf("\033[1;37mEssais : %d\033[0m\n",essais);
            if(result==1){
                printf("C'est \033[1;32mPLUS\033[0m !");
            }
            else if(result==0){
                printf("C'est \033[1;34mMOINS\033[0m !");
            }
            if(essais==7){
                printf("\n\033[1;31mPerdu\033[0m Vous avez dépassé les 7 essais.\n");
                printf("La réponse était :  %d !\n",nombreMystere);
                continuer();
            return 0;
            }
            nombreJoueur=verifscan(0,100);
            essais++;
            if ((nombreJoueur < nombreMystere)&&essais!=0) { 
                result=1;
            } 
            else if ((nombreJoueur > nombreMystere)&&essais!=0) {
                result=0;
            } 
            else if ((nombreJoueur == nombreMystere)&&essais!=0){
                printf("\033[1;32mBravo\033[0m Vous avez trouvé le \033[0;35mTic Tac Prix\033[0m en %d essais !\n", essais);
                continuer();
                return 1;
            }
        } while (1);
    }
    void shop(Joueur *joueur){
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*varibales*/
            int choix=0;
        /*Affichage*/
        while(1){
            effacer();
            printf("         ┳┳┓  ┏┓  ┏┓  ┏┓  ┏┓  ┳  ┳┓\n");
            printf("         ┃┃┃  ┣┫  ┃┓  ┣┫  ┗┓  ┃  ┃┃\n");
            printf("         ┛ ┗  ┛┗  ┗┛  ┛┗  ┗┛  ┻  ┛┗\n");
            printf("==========================================\n");
            printf("\033[0;33mVotre argent : %d 💲\033[0m\n",joueur->argent);
            printf("\033[0;31m[1]\033[0m - Acheter une vie ❤️  : 2 000 💲\n");
            printf("\033[0;31m[2]\033[0m - Acheter une expérience 🔳 : 250 💲\n");
            printf("\033[0;31m[3]\033[0m - Acheter du temps ⌛ : 3 000 💲\n");
            printf("\033[0;31m[4]\033[0m - Acheter un Joker 🃏 : 4 000 💲\n");
            printf("\033[0;31m[5]\033[0m - Acheter un cadeau ❓ : 6 666💲\n");
            printf("\033[0;31m[6]\033[0m - Quitter 🚪 ");
            choix=verifscan(1,6);
            switch(choix){
                case 1:
                    if((joueur->argent)>=2000){
                        joueur->argent-=2000;
                        joueur->pv++;
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mAchats effectués !\033[0m\n"); 
                        continuer();
                        return;
                    }
                    else{
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous n'avez pas assez de sous !\033[0m\n");
                        continuer(); 
                    }
                break;
                case 2:
                    if((joueur->argent)>=250){
                        joueur->argent-=250;
                        joueur->xp++;
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mAchats effectués !\033[0m\n"); 
                        continuer();
                        return;
                    }
                    else{
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous n'avez pas assez de sous !\033[0m\n");
                        continuer(); 
                    }
                break;
                case 3:
                    if((joueur->argent)>=3000){
                        joueur->argent-=3000;
                        joueur->temps+=5*60;
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mAchats effectués !\033[0m\n"); 
                        continuer();
                        return;
                    }
                    else{
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous n'avez pas assez de sous !\033[0m\n");
                        continuer(); 
                    }
                break;
                case 4:
                    if((joueur->argent)>=4000){
                        joueur->argent-=4000;
                        joueur->pass++;
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mAchats effectués !\033[0m\n"); 
                        continuer();
                        return;
                    }
                    else{
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous n'avez pas assez de sous !\033[0m\n");
                        continuer(); 
                    }
                break;
                case 5:
                    if((joueur->argent)>=6666){
                        joueur->argent-=6666;
                        joueur->skin=8;
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mAchats effectués !\033[0m\n"); 
                        continuer();
                        return;
                    }
                    else{
                        printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous n'avez pas assez de sous !\033[0m\n");
                        continuer(); 
                    }
                break;
                case 6:
                    return;
                break;
            }
    }

    }
    void bonus(Joueur *joueur){
        /*Verifier pointeurs joueur*/
            effacer();
            afficher(joueur);
            verifierJoueur(joueur);
        printf("\033[0;33m[Système Aléatorium]\033[0m : Vous êtes tombé sur la case \033[0;32mBonus\033[0m ou \033[1;31mMalus\033[0m !\n");
        continuer();
        effacer();
        afficher(joueur);
        printf("\033[0;33m[Système Aléatorium]\033[0m : Vous êtes tombé sur la case \033[0;32mBonus\033[0m ou \033[1;31mMalus\033[0m !\n");
        int nb=rand()%18;
        switch (nb){
            case 0:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné un coeur ❤️  !\033[0m\n"); 
                joueur->pv ++;
                continuer();
            break;
            case 1:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné de l'expérience 🔳 !\033[0m\n");
                joueur->xp ++;
                continuer();
            break;
            case 2:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné un joker 🃏 !\nIl vous permet d'éviter un mini jeux !\033[0m\n");
                joueur->pass ++;
                continuer();
            break;
            case 3:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné 1 000 💲 !\033[0m\n");
                joueur->argent+=1000;
                continuer();
            break;
            case 4:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous avez perdu un coeur ❤️  !\033[0m\n"); 
                joueur->pv --;
                continuer();
            break;
            case 5:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous avez été renvoyé au départ !\033[0m\n"); 
                int y,x;
                RechercherJoueur(&y,&x,joueur);
                joueur->map[y][x]=0;
                joueur->map[joueur->py][joueur->px]=2;
                continuer();
            break;
            case 6:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous avez rien gagné !\033[0m\n");
                continuer(); 
            break;
            case 7:
                shop(joueur);
            break;
            case 8:
                shop(joueur);
            break;
            case 9:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné de l'expérience 🔳 !\033[0m\n");
                joueur->xp ++;
                continuer();
            break;
            case 10:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mVous avez rien gagné !\033[0m\n");
                continuer(); 
            break;
            case 11:
                shop(joueur);
            break;
            case 12:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné 1 000 💲 !\033[0m\n");
                joueur->argent+=1000;
                continuer();
            break;
            case 13:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné de l'expérience 🔳 !\033[0m\n");
                joueur->xp ++;
                continuer();
            break;
            case 14:
                shop(joueur);
            break;
            case 15:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné de l'expérience 🔳 !\033[0m\n");
                joueur->xp ++;
                continuer();
            break;
            case 16:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné 1 000 💲 !\033[0m\n");
                joueur->argent+=1000;
                continuer();
            break;
            case 17:
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez gagné 1 000 💲 !\033[0m\n");
                joueur->argent+=1000;
                continuer();
            break;
            continuer();
        }
        return;
    }
    void cherchemoi(Joueur *joueur,int objets){
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        int haut, bas;
        do {
            haut =rand() % (MAP);
            bas =rand() % (MAP);
        } while (joueur->map[haut][bas] != 0); 
        joueur->map[haut][bas]=objets;
    }

/*Detecter le mini jeux*/
    int detecterminijeux(int num, Joueur *joueur){
        /*Fonction qui permet de détecter le mini jeux qu'il va rencontrer*/
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
            int resulat=0;
            int sondage=2;
            srand(time(NULL));

            if(joueur->pass!=0&&num!=58&&num!=59&&num!=10){
                effacer();
                afficher(joueur);
                printf("\033[0;33m[Système Aléatorium]\033[0m : \033[0;32mVous avez un joker de disponible!\033[0m\n");
                printf("         \033[0;32mVoullez vous l'utiliser ? \033[1;37m1- Oui 2- Non : \033[0m");
                sondage=verifscan(1,2);
            }
            if(sondage==2){
                 if(num==50){
                    resulat=pileouface();
                }
                else if(num==51){
                    resulat=calcul();
                }
                else if(num==52){
                    resulat=prv();
                }
                else if(num==53){
                    resulat=rapidos();
                }
                else if(num==54){
                    resulat=pommeraison();
                }
                else if(num==55){
                    resulat=trouvelemouton();
                }
                else if(num==56){
                    resulat=questiongolem();
                }
                else if(num==57){
                    resulat=tictac();
                }
                else if(num==60){
                    resulat=batum();
                }
                else if(num==10){
                    resulat=bossf(joueur);
                } 
            }
            else{
                resulat=1;
                joueur->pass--;
            }
            srand(joueur->graine);
            if(resulat){
                joueur->cle ++;
                joueur->xp ++;
                joueur->argent+=500;
            }
            else{
                joueur->pv --;
            }
            return resulat;
    }