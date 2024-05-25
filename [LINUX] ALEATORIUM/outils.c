
/*Outils*/
#ifdef _WIN32
    typedef struct{
        /*Contient toutes les données importantess*/
        char nom[10];
        int skin;
        int cle;
        int montre;
        int pass;
        int pv;
        int xp;
        int argent;
        //Système
        int graine;
        int px;
        int py;
        int **map;
        int ***StockageDesSalles;
        int salle;
        int sallemax;
        int porte;
        int temps;
    }Joueur;
    #include "sauvegarde.c"
#endif
#ifdef __linux__
    #include "Aleatorium.h"
#endif
void effacer(){
    /*effacer le terminal*/
    printf("\033[2J\033[H");
}
void continuer(){
    /*Fonction qui permet de faire une pause*/
    printf("\033[1;30mCliquez sur \033[4mEntrée\033[0m \033[1;30mpour continuer\033[0m\n");
    #ifdef _WIN32
        while (!kbhit() || getch() != '\r') {}
    #elif __linux__
        int ch;
        //initscr();
        //cbreak();
        //noecho();  
        while((ch=getch())!='\n'); 
        //endwin();         
    #endif
}
void verifierJoueur(const Joueur *joueur) {
    if (joueur == NULL) {
        printf("Le pointeur joueur est NULL !\n");
        exit(EXIT_FAILURE);
    }
    if (joueur->map == NULL) {
        printf("Le pointeur joueur->map est NULL !\n");
        exit(EXIT_FAILURE);
    }
    if (joueur->StockageDesSalles == NULL) {
        printf("Le pointeur joueur->StockageDesSalles est NULL !\n");
        exit(EXIT_FAILURE);
    }
}
void RechercherJoueur(int *py,int *px, Joueur *joueur){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    /*Verifier py et px*/
        if (py == NULL) {
                printf("Le pointeur py est NULL !\n");
                exit(EXIT_FAILURE);
            }
        if (px == NULL) {
                printf("Le pointeur pxx est NULL !\n");
                exit(EXIT_FAILURE);
            }
    /*permet de retrouver le joueur sur le map*/
    for(int y=0;y<MAP;y++){
        for(int x=0;x<MAP;x++){
            if(joueur->map[y][x]==2){
                *px=x;
                *py=y;
                return;
            }
        }
    }
}
void RechercherJoueurMenu(int *py,int *px, int **menu){
    /*verification des pointeurs du menu*/
        if (menu == NULL) {
            printf("Le pointeur menu est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < MENULARG; i++) {
            if (menu[i] == NULL) {
                printf("Le pointeur menu est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
    /*Verifier py et px*/
        if (py == NULL) {
                printf("Le pointeur py est NULL !\n");
                exit(EXIT_FAILURE);
            }
        if (px == NULL) {
                printf("Le pointeur pxx est NULL !\n");
                exit(EXIT_FAILURE);
            }
    /*permet de retrouver le joueur sur le menu*/
    for(int y=0;y<MENULARG;y++){
        for(int x=0;x<MENULONG;x++){
            if(menu[y][x]==2){
                *px=x;
                *py=y;
                return;
            }
        }
    }
}
int verifscan(int min,int max){
    /*Fonction qui permet de ne pas buguer lors des scanf*/
    int ret_var = 0;
    int valeur = 1;
    int verif=0;
    printf("\n+----------------------[Tapez votre réponse]-------------------+\n");
    while (ret_var != 1 || valeur < 0){
        do{
            if(verif!=0){
                printf("Choix invalide. Veuillez choisir entre %d et %d.\n",min,max);
            }  
            ret_var = scanf("%d", &valeur);
            while(getchar()!='\n'){} // Ligne facultative de sécurisation
            verif++;
        }while(valeur<min || valeur>max);
    }
    return valeur; 
}
void CreationJeu(int **tab, int longueur, int largeur) {
    /*Verifier pointeur tab*/
        if (tab == NULL) {
            printf("Le pointeur tab est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < longueur; i++) {
            if (tab[i] == NULL) {
                printf("Le pointeur tab est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
    /*Fonction pour placer un mini jeu sur la nouvelle salle*/
    int jeu[NBDEJEU];
        if (HACK == 303||HACK==1) {
            for (int i = 0; i < NBDEJEU; i++) {
                jeu[i] = 0;
            }
        } 
        else {
            for (int i = 0; i < NBDEJEU; i++) {
                jeu[i] = 50 + i;
            }
        }
        int nb = rand() % NBDEJEU;
        int haut, bas;
        do {
            haut = 1 + rand() % (longueur - 2);
            bas = 1 + rand() % (largeur - 2);
        } while (tab[haut][bas] == 2);
        tab[haut][bas] = jeu[nb];
}
void CreationBonus(int **tab, int longueur, int largeur) {
    /*Verifier pointeur tab*/
        if (tab == NULL) {
            printf("Le pointeur tab est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < longueur; i++) {
            if (tab[i] == NULL) {
                printf("Le pointeur tab est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
    /*Fonction pour placer un mini jeu sur la nouvelle salle*/
            int nb = 1;
            int haut=1, bas=1;
            if(nb==1){
                haut = 1 + rand() % (longueur - 2);
                bas = 1 + rand() % (largeur - 2);
                if(tab[haut][bas]==0){
                    tab[haut][bas]=4;
                }
            }
            return;
}
void CreationBoss(int **tab, int longueur, int largeur) {
    /*Verifier pointeur tab*/
        if (tab == NULL) {
            printf("Le pointeur tab est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < longueur; i++) {
            if (tab[i] == NULL) {
                printf("Le pointeur tab est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
        
    /*Fonction pour placer un mini jeu sur la nouvelle salle*/
        int haut=1, bas=1;
            haut = 1 + rand() % (longueur - 2);
            bas = 1 + rand() % (largeur - 2);
            if(tab[haut][bas]==0){
                tab[haut][bas]=10;
            }
        return;
}
void afficherstat(Joueur *joueur){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    /*Gérer l'xp*/
        if(joueur->xp==5){
            joueur->xp=0;
            joueur->pv++;
        }
        int xp=joueur->xp;
    /*Petit affichage*/
        printf("\033[1;37m+");
        for(int i =0; i <VISION*2+11; i++){
            printf("==");
        }
        printf("+\033[0m\n");
    /*Temps*/
        printf(" \033[1;33mTemps :");
            printf("⌛");
        for(int i=0; i<(joueur->temps)/60;i++){
            printf("⌛");
        }
        printf("\033[0m\n");
    /*Point de vie*/
        printf(" \033[1;31mPoint de vie :");
        for(int i=0;i<joueur->pv;i++){
            printf("❤️ ");
        }
        printf("\033[0m\n");
    /*Point d'expérience*/
        printf(" \033[0m\033[1;37mPoint d'expérience :");
        for(int i=0;i<MAXXP;i++){
            if(xp>0){
                printf("🔳");
                xp--;
            }
            else{
                printf("⬜");
            }
            
        }
        printf("\033[0m\n");
    /*Argent*/
        printf(" \033[0;32mArgent : \033[0m");
        printf("\033[1;37m%d 💲\033[0m\n",joueur->argent);
    /*Inventaire*/
        printf(" \033[0;34mInventaire :\033[0m");
        /*Apparition des clés*/
            if(HACK!=0){
                printf("♾️ ");
            }
            else{
                for(int i=0;i<joueur->cle;i++){
                printf("🔑");
                }
            }
        /*Apparition des objets de quetes*/
            for(int i=0;i<joueur->montre;i++){
                printf("⌚");
            }
        /*Appartion des free pass*/
            if(HACK!=0){
                printf("♾️ ");
            }
            else{
                for(int i=0;i<joueur->pass;i++){
                    printf("🃏");
                }
            }
        /*test*/
            //printf("\n%d %d %d",joueur->salle, joueur->porte,joueur->sallemax);
        printf("\n");
        /*Petit affichage*/
            printf("\033[1;37m+");
            for(int i =0; i <VISION*2+11; i++){
                printf("==");
            }
            printf("+\033[0m\n");
    /*tutoriel*/
        printf("  \033[1;30m  ⮝                             ┌───┐\n");
        printf("  ⮜   ⮞ : Pour vous déplacer      │Esc│ : Pour sauvegarder\n");
        printf("    ⮟                             └───┘   ou quitter\n");
    /*Petit affichage*/
        printf("+");
        for(int i =0; i <VISION*2+11; i++){
            printf("--");
        }
        printf("+\033[0m\n");
    
}
void afficher(Joueur *joueur){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    /*Rechercher Position du joueur*/
        int y,x;
        RechercherJoueur(&y,&x,joueur);
    /*Bordure*/    
    printf("          ╔");
    for(int i = y - VISION; i <= y + VISION; i++){
        printf("══");
    }
    printf("╗\n");
    for(int i = y - VISION; i <= y + VISION; i++) {
        printf("          ║");
        for(int j = x - VISION; j <= x + VISION; j++) {
            if(i >= 0 && i < MAP && j >= 0 && j < MAP) {
                /*Afficher la map*/
                switch(joueur->map[i][j]) {
                    case 1:
                        printf("⬜"); //Murs
                    break;
                    /*Skin du joueur*/
                        case 2:
                            if(HACK==0){
                                if(joueur->skin==1){
                                    printf("🤠"); //Joueur 
                                }
                                else if(joueur->skin==2){
                                    printf("😭"); //Joueur 
                                }
                                else if(joueur->skin==3){
                                    printf("😎"); //Joueur 
                                }
                                else if(joueur->skin==4){
                                    printf("😷"); //Joueur 
                                }
                                else if(joueur->skin==5){
                                    printf("😁"); //Joueur 
                                }
                                else if(joueur->skin==6){
                                    printf("😨"); //Joueur 
                                }
                                else if(joueur->skin==7){
                                    printf("🤡"); //Joueur 
                                }
                                else if(joueur->skin==8){
                                    printf("🤑"); //Joueur 
                                }
                            }
                            else{
                               printf("🤑"); //Joueur hack 
                            }
                            
                        break;
                    case 3:
                        printf("🚪"); //Porte  
                    break;
                    case 0:
                        //printf("⬛"); //Sol
                        printf("  "); //Sol  
                    break;
                    /*Bonus*/
                        case 4:
                            printf("🎰");
                        break;
                        case 5:
                            printf("🔑");
                        break;
                        case 6:
                            printf("⌚");
                        break;
                        case 7:
                            printf("😱");
                        break;
                    /*Boss*/
                        case 10:
                            printf("🧐");
                        break;
                    /*Gerer les colisions*/
                        case 444:
                            if(HACK==303){
                                printf("❌"); //Indiquer
                            }
                            else{
                                printf("\033[1;30m▒▒");
                                printf("\033[0m");
                            }     
                        break;
                    /*Mini jeux*/
                        case 50:
                            printf("🌓");
                        break;
                        case 51:
                            printf("⚡");
                        break;
                        case 52:
                            printf("🦊");
                        break;
                        case 53:
                            printf("🏁");
                        break;
                        case 54:
                            printf("🍎");
                        break;
                        case 55:
                            printf("🐑");
                        break;
                        case 56:
                            printf("🗿");
                        break;
                        case 57:
                            printf("💣");
                        break;
                        case 60:
                            printf("⚓");
                        break;
                    /*pnj*/
                        case 58:
                            printf("🤓");
                        break;
                        case 59:
                            printf("😱");
                        break;
                    /*Vide*/
                        default:
                            printf("\033[1;30m▒▒");
                            printf("\033[0m");
                        break;
                        
                }
            }
            
        }
        printf("║\n");
    }
    printf("          ╚");
    for(int i = y - VISION; i <= y + VISION; i++){
        printf("══");
    }
    printf("╝\n");
    afficherstat(joueur); //afficher les stats
    //afficher les touches
    return;
    
}
void verifchar(char *nom, int max) {
    /* Vérifier pointeur nom */
    if (nom == NULL) {
        printf("Le pointeur nom est NULL !\n");
        exit(EXIT_FAILURE);
    }

    printf("\n+----------------------[Tapez votre réponse]-------------------+\n");

    do {
        fgets(nom, max + 1, stdin);

        // Supprimer le '\n' de la fin de la chaîne s'il est présent
        if (nom[strlen(nom) - 1] == '\n') {
            nom[strlen(nom) - 1] = '\0';
        } else {
            // Si la chaîne est trop longue, vider le reste du flux d'entrée
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }

        // Vérifier si la saisie est juste une ligne vide
        if (strlen(nom) == 0 || (strlen(nom) == 1 && nom[0] == '\n')) {
            printf("Saisie invalide. Veuillez entrer quelque chose.\n");
        }
        
    } while (strlen(nom) == 0 || (strlen(nom) == 1 && nom[0] == '\n') || strlen(nom) > max); // Continuer tant que la saisie est invalide ou dépasse la limite
}
void gagne(Joueur *joueur){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    effacer(); 
    printf("██╗   ██╗ ██████╗ ██╗   ██╗███████╗     █████╗ ██╗   ██╗███████╗███████╗    ██████╗  █████╗ ████████╗████████╗██╗   ██╗    \n");
    printf("██║   ██║██╔═══██╗██║   ██║██╔════╝    ██╔══██╗██║   ██║██╔════╝╚══███╔╝    ██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║   ██║    \n");
    printf("██║   ██║██║   ██║██║   ██║███████╗    ███████║██║   ██║█████╗    ███╔╝     ██████╔╝███████║   ██║      ██║   ██║   ██║    \n");
    printf("╚██╗ ██╔╝██║   ██║██║   ██║╚════██║    ██╔══██║╚██╗ ██╔╝██╔══╝   ███╔╝      ██╔══██╗██╔══██║   ██║      ██║   ██║   ██║    \n");
    printf(" ╚████╔╝ ╚██████╔╝╚██████╔╝███████║    ██║  ██║ ╚████╔╝ ███████╗███████╗    ██████╔╝██║  ██║   ██║      ██║   ╚██████╔╝    \n");
    printf("  ╚═══╝   ╚═════╝  ╚═════╝ ╚══════╝    ╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚══════╝    ╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝    ╚═════╝     \n");
    printf("\n");
    printf("\n");
    printf("                     █████╗ ██╗     ███████╗ █████╗ ████████╗ ██████╗ ██████╗ ██╗██╗   ██╗███╗   ███╗                      \n");
    printf("                    ██╔══██╗██║     ██╔════╝██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗██║██║   ██║████╗ ████║                      \n");
    printf("                    ███████║██║     █████╗  ███████║   ██║   ██║   ██║██████╔╝██║██║   ██║██╔████╔██║                      \n");
    printf("                    ██╔══██║██║     ██╔══╝  ██╔══██║   ██║   ██║   ██║██╔══██╗██║██║   ██║██║╚██╔╝██║                      \n");
    printf("                    ██║  ██║███████╗███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║██║╚██████╔╝██║ ╚═╝ ██║                      \n");
    printf("                    ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝     ╚═╝                      \n\n");
    sleep(2);
    printf("                                               \033[1;37mDIRECTEURS\033[0m                                        \n\n");
    sleep(1);
    printf("                        Mathieu NGUYEN     Hicham EL JARJINI     Alexandre HALHOUTE                                        \n\n");
    sleep(2);
    printf("                                              \033[1;37mMISE EN SCENE\033[0m\n\n");
    sleep(1);
    printf("                                         Réalisateur Hideo KOJIMA\n");
    sleep(1);
    printf("                               Assistant Réalisateur George LUCAS\n");
    sleep(1);
    printf("                                            Ecriture Alexandre HALHOUTE\n");
    sleep(1);
    printf("                                          Scénariste Kai'sa\n");
    sleep(1);
    printf("                                       Ingénieur son Congé Maladie\n");
    sleep(1);
    printf("                                        Perche micro Aussi\n\n");
    sleep(2); 
    printf("                                                 \033[1;37mCASTING\033[0m \n\n ");
    sleep(1);
    printf("                                               René René\n");
    sleep(1);
    printf("                                                 Bob Bob\n");
    sleep(1);
    printf("                                             Moutons Hicham EL JARJINI\n");
    sleep(1);
    printf("                                                Loup Mathieu NGUYEN\n");
    sleep(1);
    printf("                              Capitaine de la barque Alexandre HALHOUTE\n\n");
    sleep(2);
    printf("                                              \033[1;37mREMERCIEMENTS\033[0m \n\n ");
    sleep(1);
    printf("                                            Romuald GRIGNON\n");
    sleep(1);
    printf("                                             Romuald GRIGNON\n");
    sleep(1);
    printf("                                                 Eva ANSERMIN\n");
    sleep(1);
    printf("                                             Romuald GRIGNON\n");
    sleep(1);
    printf("                                             Romuald GRIGNON\n");
    sleep(1);
    printf("                                             Romuald GRIGNON\n\n");
    sleep(2);
    printf("              \033[1;37mDemain, disponible sur PS5 / GameCube / Xbox 360 / Wii / Nintendo 3DS / Game Boy\033[0m \n\n ");
    continuer();
    void menu();
    menu();   
}
void perdu(Joueur *joueur){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    effacer(); 
    printf("██╗   ██╗ ██████╗ ██╗   ██╗███████╗     █████╗ ██╗   ██╗███████╗███████╗    ██████╗ ███████╗██████╗ ██████╗ ██╗   ██╗    ██╗\n");
    printf("██║   ██║██╔═══██╗██║   ██║██╔════╝    ██╔══██╗██║   ██║██╔════╝╚══███╔╝    ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║   ██║    ██║\n");
    printf("██║   ██║██║   ██║██║   ██║███████╗    ███████║██║   ██║█████╗    ███╔╝     ██████╔╝█████╗  ██████╔╝██║  ██║██║   ██║    ██║\n");
    printf("╚██╗ ██╔╝██║   ██║██║   ██║╚════██║    ██╔══██║╚██╗ ██╔╝██╔══╝   ███╔╝      ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║   ██║    ╚═╝\n");
    printf(" ╚████╔╝ ╚██████╔╝╚██████╔╝███████║    ██║  ██║ ╚████╔╝ ███████╗███████╗    ██║     ███████╗██║  ██║██████╔╝╚██████╔╝    ██╗\n");
    printf("  ╚═══╝   ╚═════╝  ╚═════╝ ╚══════╝    ╚═╝  ╚═╝  ╚═══╝  ╚══════╝╚══════╝    ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝     ╚═╝\n");
    printf("            ███████╗ ███████ ██╗   ██ ███████  ███╗   ██ ███████ ███████╗     ██╗   ██ ██╗███████████████╗    ██╗\n");
    printf("            ██╔══██║ ██╔════ ██║   ██ ██╔════  ████╗  ██ ██╔════╝╚══███╔╝     ██║   ██ ██║╚══██╔══██╔════╝    ██║\n");
    printf("            ██████═╝ █████╗  ██║   ██ █████╗   █████╗ ██ █████╗   ███╔╝       ██║   ██ ██║   ██║  █████╗      ██║\n");
    printf("            ██╔══██  ██╔══╝  ╚██╗ ██╔ ██╔══╝   ██║╚██╗██ ██╔═══╝ ███╔╝        ╚██╗ ██╔ ██║   ██║  ██╔══╝      ╚═╝\n");
    printf("            ██║  ██  ███████╗ ╚████╔╝ ███████  ██║ ╚████ ██████ ████████╗      ╚████╔╝ ██║   ██║  ███████╗    ██╗\n");
    printf("            ╚═╝  ╚═╝ ╚══════╝ ╚═══╝ ╚══════╚═╝  ╚═══╚══════╚══════╝╚═══╝       ╚═══╝  ╚═╝   ╚═╝  ╚══════╝    ╚═╝\n");
    continuer();
    void menu();
    menu();   
}