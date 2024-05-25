#ifdef __linux__
    #include "Aleatorium.h"
#endif
void affichermenu(int **menu){
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
    /*Affichage du titre*/
        printf("\033[1;37m╔═╗ ╦   ╔═╗ ╔═╗ ╔╦╗ ╔═╗ ╦═╗ ╦ ╦ ╦ ╔╦╗\n");
        printf("╠═╣ ║   ║╣  ╠═╣  ║  ║ ║ ╠╦╝ ║ ║ ║ ║║║\n");
        printf("╩ ╩ ╩═╝ ╚═╝ ╩ ╩  ╩  ╚═╝ ╩╚═ ╩ ╚═╝ ╩ ╩\033[0m\n");
        printf("\n=====================================\n");
    /*Affichage de la salle*/
        for(int i =0; i <MENULARG; i++) {
            for(int j =0; j <MENULONG; j++) {
                    switch(menu[i][j]) {
                        case 1:
                            printf("   ");
                        break;
                        case 2:
                            printf("🙂"); //Joueur 
                        break;
                        case 3:
                            printf("🔵"); //Sol
                        break;
                        case 4:
                            printf("⚫"); //Sol
                        break;
                        case 5:
                            printf("🔴"); //Sol
                        break;  
                        case 6:
                            printf("💾"); //Charger
                        break;  
                        case 7:
                            printf("⚔️ "); //Nouvelle partie
                        break;  
                        case 8:
                            printf("🚪"); //Porte
                        break;  
                        case 0: 
                            printf("⚪"); //Sol  
                        break;
                            
                    }
                
                
            }
            printf("\n");
        }
        printf("=====================================\n\n");
    return;
}
void creercategorie(int **menu){
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
    /*cration de la salle*/
        for(int i=0;i<MENULARG;i++){ 
            for(int j=0;j<MENULONG;j++){
                if(i==0||i==MENULARG-1||j==MENULONG-1||j==0){
                        menu[i][j]=1; //Création des murs autour de la salle
                }
                else{
                    menu[i][j]=0; //Création du sol
                }
            }
        }
    /*Charger une partie*/
        for(int i=1;i<6;i++){
            for(int j=1;j<6;j++){
                menu[i][j]=3;
            }
        }
    /*Nouvelle partie*/
        for(int i=1;i<6;i++){
            for(int j=6;j<11;j++){
                menu[i][j]=4;
            }
        }
    /*Quitter*/
        for(int i=1;i<6;i++){
            for(int j=11;j<16;j++){
                menu[i][j]=5;
            }
        }
    /*Placer les emojis*/
        menu[3][3]=6;
        menu[3][8]=7;
        menu[3][13]=8;
}
void messagequiter() {
    printf(" █████╗ ██╗     ███████╗ █████╗ ████████╗ ██████╗ ██████╗ ██╗██╗   ██╗███╗   ███╗\n");
    printf("██╔══██╗██║     ██╔════╝██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗██║██║   ██║████╗ ████║\n");
    printf("███████║██║     █████╗  ███████║   ██║   ██║   ██║██████╔╝██║██║   ██║██╔████╔██║\n");
    printf("██╔══██║██║     ██╔══╝  ██╔══██║   ██║   ██║   ██║██╔══██╗██║██║   ██║██║╚██╔╝██║\n");
    printf("██║  ██║███████╗███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║██║╚██████╔╝██║ ╚═╝ ██║\n");
    printf("╚═╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝ ╚═════╝ ╚═╝     ╚═╝\n");
}
void deplacementmenu(int **menu,int direction,int *num,Joueur *joueur){
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
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    /*Rechercher Position du joueur*/
        int y,x;
        int resulat;
        RechercherJoueurMenu(&y,&x,menu);
    /*Gérer la colision ou non*/
        int verif=0;
        /*Haut*/
            if(direction==1){
                
                /*Si c'est du Sol*/
                    if(menu[y-1][x]==0){
                        creercategorie(menu); 
                        menu[y-1][x]=2;
                        (*num)=0;
                    }
                /*Si c'est charger partie*/
                    else if(menu[y-1][x]==3){
                        creercategorie(menu);
                        (*num)=1;
                        menu[y-1][x]=2;
                    }
                /*Si c'est nouvelle partie*/
                    else if(menu[y-1][x]==4){
                        creercategorie(menu);
                        (*num)=2;
                        menu[y-1][x]=2;
                    }
                /*Si c'est quitter*/
                    else if(menu[y-1][x]==5){
                        creercategorie(menu);
                        (*num)=3;
                        menu[y-1][x]=2;
                    }
                /*Charger partie*/
                    else if(menu[y-1][x]==6){
                        verif=verifcharge(joueur);
                        if(verif==1){
                            joueur=chargerlapartie(joueur);
                            jeu(joueur,0);
                        } 
                    }
                /*Nouvelle partie*/
                    else if(menu[y-1][x]==7){
                        effacer();
                        free(menu);
                        jeu(joueur,1);
                    }
                /*Quitter*/
                    else if(menu[y-1][x]==8){
                        effacer();
                        messagequiter();
                        free(menu);
                        exit(1);
                    }
                    
                    else{

                    }
            }
        /*Droite*/
            else if(direction==2){
                /*Si c'est du Sol*/
                    if(menu[y][x+1]==0){
                        creercategorie(menu);
                        menu[y][x+1]=2;
                        (*num)=0;
                    }
                /*Si c'est charger partie*/
                    else if(menu[y][x+1]==3){
                        creercategorie(menu);
                        (*num)=1;
                        menu[y][x+1]=2;
                    }
                /*Si c'est nouvelle partie*/
                    else if(menu[y][x+1]==4){
                        creercategorie(menu);
                        (*num)=2;
                        menu[y][x+1]=2;
                    }
                /*Si c'est quitter*/
                    else if(menu[y][x+1]==5){
                        creercategorie(menu);
                        (*num)=3;
                        menu[y][x+1]=2;
                    }
                /*Charger partie*/
                    else if(menu[y][x+1]==6){
                        verif=verifcharge(joueur);
                        if(verif==1){
                            joueur=chargerlapartie(joueur);
                            jeu(joueur,0);
                        } 
                    }
                /*Nouvelle partie*/
                    else if(menu[y][x+1]==7){
                        effacer();
                        free(menu);
                        jeu(joueur,1);
                    }
                /*Quitter*/
                    else if(menu[y][x+1]==8){
                        effacer();
                        free(menu);
                        exit(1);
                    }
                    else{

                    }
            }
        /*Bas*/
            else if(direction==3){
                /*Si c'est du Sol*/
                    if(menu[y+1][x]==0){
                        creercategorie(menu);
                        menu[y+1][x]=2;
                        (*num)=0;
                    }
                /*Si c'est charger partie*/
                    else if(menu[y+1][x]==3){
                        creercategorie(menu);
                        (*num)=1;
                        menu[y+1][x]=2;
                        
                    }
                /*Si c'est nouvelle partie*/
                    else if(menu[y+1][x]==4){
                        creercategorie(menu);
                        (*num)=2;
                        menu[y+1][x]=2;
                        
                    }
                /*Si c'est quitter*/
                    else if(menu[y+1][x]==5){
                        creercategorie(menu);
                        (*num)=3;
                        menu[y+1][x]=2;
                        
                    }
                /*Charger partie*/
                    else if(menu[y+1][x]==6){
                        verif=verifcharge(joueur);
                        if(verif==1){
                            joueur=chargerlapartie(joueur);
                            jeu(joueur,0);
                        } 
                    }
                /*Nouvelle partie*/
                    else if(menu[y+1][x]==7){
                        effacer();
                        free(menu);
                        jeu(joueur,1);
                    }
                /*Quitter*/
                    else if(menu[y+1][x]==8){
                        effacer();
                        messagequiter();
                        free(menu);
                        exit(1);
                        
                    }
                    else{

                    }
            }
        /*Gauche*/
            else if(direction==4){
                /*Si c'est du Sol*/
                    if(menu[y][x-1]==0){
                        creercategorie(menu);
                        menu[y][x-1]=2;
                        (*num)=0;
                    }
                /*Si c'est charger partie*/
                    else if(menu[y][x-1]==3){
                        creercategorie(menu);
                        (*num)=1;
                        menu[y][x-1]=2;
                    }
                /*Si c'est nouvelle partie*/
                    else if(menu[y][x-1]==4){
                        creercategorie(menu);
                        (*num)=2;
                        menu[y][x-1]=2;
                    }
                /*Si c'est quitter*/
                    else if(menu[y][x-1]==5){
                        creercategorie(menu);
                        (*num)=3;
                        menu[y][x-1]=2;
                    }
                /*Charger partie*/
                    else if(menu[y][x-1]==6){
                        verif=verifcharge(joueur);
                        if(verif==1){
                            joueur=chargerlapartie(joueur);
                            jeu(joueur,0);
                        } 
                    }
                /*Nouvelle partie*/
                    else if(menu[y][x-1]==7){
                        effacer();
                        free(menu);
                        jeu(joueur,1);
                    }
                /*Quitter*/
                    else if(menu[y][x-1]==8){
                        effacer();
                        messagequiter();
                        free(menu);
                        exit(1);
                    }
                    else{

                    }
            }           
    effacer();
    affichermenu(menu);
    /*Si c'est charger partie*/
        if((*num)==1){
            printf(" ┏┓┓┏┏┓┳┓┏┓┏┓┳┓  ┳┳┳┓┏┓  ┏┓┏┓┳┓┏┳┓┳┏┓\n");
            printf(" ┃ ┣┫┣┫┣┫┃┓┣ ┣┫  ┃┃┃┃┣   ┃┃┣┫┣┫ ┃ ┃┣ \n");
            printf(" ┗┛┛┗┛┗┛┗┗┛┗┛┛┗  ┗┛┛┗┗┛  ┣┛┛┗┛┗ ┻ ┻┗┛\n");
        }
    /*Si c'est nouvelle partie*/
        else if((*num)==2){
            printf("  ┓ ┏┓┳┓┏┓┏┓┳┓  ┳┳┳┓┏┓  ┏┓┏┓┳┓┏┳┓┳┏┓\n");
            printf("  ┃ ┣┫┃┃┃ ┣ ┣┫  ┃┃┃┃┣   ┃┃┣┫┣┫ ┃ ┃┣ \n");
            printf("  ┗┛┛┗┛┗┗┛┗┛┛┗  ┗┛┛┗┗┛  ┣┛┛┗┛┗ ┻ ┻┗┛\n");
        }
    /*Si c'est quitter*/
        else if((*num)==3){
            printf("    ┏┓┳┳┳┏┳┓┏┳┓┏┓┳┓  ┓ ┏┓  ┏┳┏┓┳┳\n");
            printf("    ┃┃┃┃┃ ┃  ┃ ┣ ┣┫  ┃ ┣    ┃┣ ┃┃\n");
            printf("    ┗┻┗┛┻ ┻  ┻ ┗┛┛┗  ┗┛┗┛  ┗┛┗┛┗┛\n");
        }
    /*regles*/
        else{
            printf("      ┳┳┏┳┓┳ ┓ ┳┏┓┏┓┏┓  ┓ ┏┓┏┓    \n");
            printf("      ┃┃ ┃ ┃ ┃ ┃┗┓┣ ┏┛  ┃ ┣ ┗┓    \n");
            printf("      ┗┛ ┻ ┻ ┗┛┻┗┛┗┛┗┛  ┗┛┗┛┗┛    \n");
            printf("   ┏┓┓ ┏┓┏┓┓┏┏┓┏┓  ┏┓┏┓┳┳┳┓  ┏┓┏┓ \n");
            printf("   ┣ ┃ ┣ ┃ ┣┫┣ ┗┓  ┃┃┃┃┃┃┣┫  ┗┓┣  \n");
            printf("   ┻ ┗┛┗┛┗┛┛┗┗┛┗┛  ┣┛┗┛┗┛┛┗  ┗┛┗┛ \n");
            printf("     ┳┓┏┓┏┓┓ ┏┓┏┓┏┓┳┓     ⮝       \n");
            printf("     ┃┃┣ ┃┃┃ ┣┫┃ ┣ ┣┫   ⮜   ⮞     \n");
            printf("     ┻┛┗┛┣┛┗┛┛┗┗┛┗┛┛┗     ⮟       \n");
        }
}

#ifdef _WIN32
    void detecterdeplacementmenuwin(int **menu,int *num,Joueur *joueur){
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
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        char touche;
        /*Verification Des touches*/
            if(kbhit()) { // Vérifie si une touche est appuyée
                touche = getch(); // Récupère la touche appuyée

                // Vérifie si la touche est une flèche
                if(touche == 0 || touche == 224) {
                        touche = getch(); // Récupère la seconde partie de la touche (pour les flèches)
                        switch(touche) {
                            case 72: //Haut
                                deplacementmenu(menu,1,num,joueur);
                                break;
                            case 77: //Droite
                                deplacementmenu(menu,2,num,joueur);
                                break;
                            case 80: //Bas
                                deplacementmenu(menu,3,num,joueur);
                                break;
                            case 75: //Gauche
                                deplacementmenu(menu,4,num,joueur);
                                break;
                        }
                        
                    }
                }
    }
#endif
#ifdef __linux__
    void detecterdeplacementmenulinux(int **menu,int *num,Joueur *joueur){
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
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*Initialisation de ncurses*/
        int ch;
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
        ch = getch(); // Récupère la touche appuyée

        switch(ch) {
            case KEY_UP://Haut
                endwin();
                deplacementmenu(menu,1,num,joueur);
                break;
            case KEY_DOWN://Bas
                endwin();
                deplacementmenu(menu,3,num,joueur);
                break;
            case KEY_LEFT://Gauche
                endwin();
                deplacementmenu(menu,4,num,joueur);
                
                break;
            case KEY_RIGHT://Droite
                endwin();
                deplacementmenu(menu,2,num,joueur);
                break;
            
        }
        endwin();
    
    }
    #endif
void menu(){
    /*gerer le menu*/
    int num;
    //////////////////////
        Joueur joueur = {"", /*Skin = */1,/*cle = */ 0,/*objets = */0,/*Pass = */0, 
        /*PV = */5, /*xp = */0,/*argent = */1000,
        /*graine = */ 0,/*Posision x =*/ 0,/*Position y = */ 0,/*map */NULL,
        /*stockage */NULL,/*salle*/0,/*sallemax*/0,/*porte*/0,/*temps*/TEMPSLIMITE};
    //////////////////////
    // Allocation de mémoire juste pour le menu
    joueur.map = malloc(MAP * sizeof(int *));
    for (int i = 0; i < MAP; i++) {
        joueur.map[i] = malloc(MAP* sizeof(int));
    }

    // Allocation de mémoire juste pour le menu
    joueur.StockageDesSalles = malloc(MENULARG * sizeof(int **));
    for (int i = 0; i < MENULARG; i++) {
        joueur.StockageDesSalles[i] = malloc(MENULONG * sizeof(int *));
        for (int j = 0; j < MENULONG; j++) {
            joueur.StockageDesSalles[i][j] = malloc(MENULONG * sizeof(int));
        }
    }
    /*Verifier pointeurs joueur*/
        verifierJoueur(&joueur);
    /*Création de la menu principale*/
        int **menu=malloc(MENULARG*sizeof(int*));   
        for (int i = 0; i < MENULARG; i++) {
            menu[i] = malloc(MENULONG * sizeof(int));
        }
        
    /*Placer la catégorie*/
        creercategorie(menu);
    /*Placer joueur*/
        menu[8][8]=2;
    /*Afficher regles*/
        effacer();
        affichermenu(menu);
        printf("      ┳┳┏┳┓┳ ┓ ┳┏┓┏┓┏┓  ┓ ┏┓┏┓    \n");
        printf("      ┃┃ ┃ ┃ ┃ ┃┗┓┣ ┏┛  ┃ ┣ ┗┓    \n");
        printf("      ┗┛ ┻ ┻ ┗┛┻┗┛┗┛┗┛  ┗┛┗┛┗┛    \n");
        printf("   ┏┓┓ ┏┓┏┓┓┏┏┓┏┓  ┏┓┏┓┳┳┳┓  ┏┓┏┓ \n");
        printf("   ┣ ┃ ┣ ┃ ┣┫┣ ┗┓  ┃┃┃┃┃┃┣┫  ┗┓┣  \n");
        printf("   ┻ ┗┛┗┛┗┛┛┗┗┛┗┛  ┣┛┗┛┗┛┛┗  ┗┛┗┛ \n");
        printf("     ┳┓┏┓┏┓┓ ┏┓┏┓┏┓┳┓     ⮝       \n");
        printf("     ┃┃┣ ┃┃┃ ┣┫┃ ┣ ┣┫   ⮜   ⮞     \n");
        printf("     ┻┛┗┛┣┛┗┛┛┗┗┛┗┛┛┗     ⮟       \n");
        fflush(stdout);
        
    /*Gestion du menu*/
        while(1){
            #ifdef _WIN32
                detecterdeplacementmenuwin(menu,&num,&joueur); //Si c'est sur windows
            #endif
            #ifdef __linux__
                detecterdeplacementmenulinux(menu,&num,&joueur); //Si c'est sur linux
            #endif  
        }
}
