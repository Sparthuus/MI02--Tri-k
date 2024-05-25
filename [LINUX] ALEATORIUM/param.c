
#ifdef __linux__
    #include "Aleatorium.h"
#endif
void afficherparam(int **param){
    /*verification des pointeurs du param*/
        if (param == NULL) {
            printf("Le pointeur param est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < PARAMLARG; i++) {
            if (param[i] == NULL) {
                printf("Le pointeur param est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
    printf("         ┏┓┏┓┳┓┏┓┳┳┓┏┓┏┳┓┳┓┏┓\n");
    printf("         ┃┃┣┫┣┫┣┫┃┃┃┣  ┃ ┣┫┣ \n");
    printf("         ┣┛┛┗┛┗┛┗┛ ┗┗┛ ┻ ┛┗┗┛\n");
    printf("=====================================\n");
    for(int i =0; i <PARAMLARG; i++) {
        for(int j =0; j <PARAMLONG; j++) {
                switch(param[i][j]) {
                    case 1:
                        printf("   ");
                    break;
                    case 2:
                        printf("🙂"); //Joueur 
                    break;
                    case 3:
                        printf("⚫"); //Reprendre la partie
                    break;
                    case 4:
                        printf("🔴"); //retour au menu
                    break;   
                    case 5:
                        printf("⚔️ "); //reprendre
                    break;  
                    case 6:
                        printf("🚪"); //quitter
                    break;  
                    case 0: 
                        printf("⚪"); //Sol  
                    break;
                        
                }
            
            
        }
        printf("\n");
    }
    printf("=====================================\n");
    return;
}
void RechercherJoueurParam(int *py,int *px, int **param){
    /*verification des pointeurs du param*/
        if (param == NULL) {
            printf("Le pointeur param est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < PARAMLARG; i++) {
            if (param[i] == NULL) {
                printf("Le pointeur param est NULL !\n");
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
    /*Chercher le joueur sur la map*/
        for(int y=0;y<PARAMLARG;y++){
            for(int x=0;x<PARAMLONG;x++){
                if(param[y][x]==2){
                    *px=x;
                    *py=y;
                    return;
                }
            }
        }
}
void creercategorieparam(int **param){
    /*verification des pointeurs du param*/
        if (param == NULL) {
            printf("Le pointeur param est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < PARAMLARG; i++) {
            if (param[i] == NULL) {
                printf("Le pointeur param est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
    /*Création de la sal*/
        for(int i=0;i<PARAMLARG;i++){ //Mettre à 0 la param
                for(int j=0;j<PARAMLONG;j++){
                    if(i==0||i==PARAMLARG-1||j==PARAMLONG-1||j==0){
                            param[i][j]=1; //Création des murs autour de la salle
                    }
                    else{
                        param[i][j]=0;
                    }
                }
            }
    /*Reprendre la partie*/
        for(int i=1;i<6;i++){
            for(int j=1;j<6;j++){
                param[i][j]=3;
            }
        }
    /*Retour au menu*/
        for(int i=1;i<6;i++){
            for(int j=11;j<16;j++){
                param[i][j]=4;
            }
        }
    /*Icone reprendr ou quitter*/
        param[3][3]=5;
        param[3][13]=6;
}
int deplacementparam(int **param,int direction,int *num){
    /*verification des pointeurs de num*/
    if (num == NULL) {
            printf("Le pointeur num est NULL !\n");
            exit(EXIT_FAILURE);
        }
    /*verification des pointeurs du param*/
        if (param == NULL) {
            printf("Le pointeur param est NULL !\n");
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < PARAMLARG; i++) {
            if (param[i] == NULL) {
                printf("Le pointeur param est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
    /*Rechercher Position du joueur*/
        int y,x;
        int resulat;
        RechercherJoueurParam(&y,&x,param);
    /*Gérer la colision ou non*/
        /*Haut*/
            if(direction==1){
                
                /*Si c'est du Sol*/
                    if(param[y-1][x]==0){
                        creercategorieparam(param); 
                        param[y-1][x]=2;
                        (*num)=0;
                    }
                /*Si c'est sol reprendre*/
                    else if(param[y-1][x]==3){
                        creercategorieparam(param); 
                        (*num)=1;
                        param[y-1][x]=2;
                    }
                /*Si c'est sol quitter*/
                    else if(param[y-1][x]==4){
                        creercategorieparam(param); 
                        (*num)=2;
                        param[y-1][x]=2;
                    }
                /*Si c'est case reprendre*/
                    else if(param[y-1][x]==5){
                        effacer();
                        return (*num);
                    }
                /*Si c'est case quitter*/
                    else if(param[y-1][x]==6){
                        effacer();
                        return (*num);
                    }
                    
                    else{

                    }
            }
        /*Droite*/
            else if(direction==2){
                /*Si c'est du Sol*/
                    if(param[y][x+1]==0){
                        creercategorieparam(param); 
                        param[y][x+1]=2;
                        (*num)=0;
                        
                    }
                /*Si c'est sol reprendre*/
                    else if(param[y][x+1]==3){
                        creercategorieparam(param); 
                        (*num)=1;
                        param[y][x+1]=2;
                    }
                /*Si c'est sol quitter*/
                    else if(param[y][x+1]==4){
                        creercategorieparam(param); 
                        (*num)=2;
                        param[y][x+1]=2;
                    }
                /*Si c'est case reprendre*/
                    else if(param[y][x+1]==5){
                        effacer();
                        return (*num);
                    }
                /*Si c'est case quitter*/
                    else if(param[y][x+1]==6){
                        effacer();
                        return (*num);
                    }
                    else{

                    }
            }
        /*Bas*/
            else if(direction==3){
                /*Si c'est du Sol*/
                    if(param[y+1][x]==0){
                        creercategorieparam(param); 
                        param[y+1][x]=2;
                        (*num)=0;
                    }
                /*Si c'est sol reprendre*/
                    else if(param[y+1][x]==3){
                        creercategorieparam(param); 
                        (*num)=1;
                        param[y+1][x]=2;
                        
                    }
                /*Si c'est sol quitter*/
                    else if(param[y+1][x]==4){
                        creercategorieparam(param); 
                        (*num)=2;
                        param[y+1][x]=2;
                        
                    }
                /*Si c'est case reprendre*/
                    else if(param[y+1][x]==5){
                        effacer();
                        return (*num);
                        
                    }
                /*Si c'est case quitter*/
                    else if(param[y+1][x]==6){
                        effacer();
                        return (*num);
                        
                    }
                    else{

                    }
            }
        /*Gauche*/
            else if(direction==4){
                /*Si c'est du Sol*/
                    if(param[y][x-1]==0){
                        creercategorieparam(param); 
                        param[y][x-1]=2;
                        (*num)=0;
                    }
                /*Si c'est sol reprendre*/
                    else if(param[y][x-1]==3){
                        creercategorieparam(param); 
                        (*num)=1;
                        param[y][x-1]=2;
                    }
                /*Si c'est sol quitter*/
                    else if(param[y][x-1]==4){
                        creercategorieparam(param); 
                        (*num)=2;
                        param[y][x-1]=2;
                    }
                /*Si c'est case reprendre*/
                    else if(param[y][x-1]==5){
                        effacer();
                        return (*num);
                    }
                /*Si c'est case quitter*/
                    else if(param[y][x-1]==6){
                        effacer();
                        return (*num);
                    }
                    else{

                    }
            }           
    effacer();
    afficherparam(param);
    /*Affichage*/
        if((*num)==1){
            printf("      ┳┓┏┓┏┳┓┏┓┳┳┳┓  ┏┓┳┳  ┏┳┏┓┳┳\n");
            printf("      ┣┫┣  ┃ ┃┃┃┃┣┫  ┣┫┃┃   ┃┣ ┃┃\n");
            printf("      ┛┗┗┛ ┻ ┗┛┗┛┛┗  ┛┗┗┛  ┗┛┗┛┗┛\n");
        }
        else if((*num)==2){
            printf("    ┳┓┏┓┏┳┓┏┓┳┳┳┓  ┏┓┳┳  ┳┳┓┏┓┳┓┳┳\n");
            printf("    ┣┫┣  ┃ ┃┃┃┃┣┫  ┣┫┃┃  ┃┃┃┣ ┃┃┃┃\n");
            printf("    ┛┗┗┛ ┻ ┗┛┗┛┛┗  ┛┗┗┛  ┛ ┗┗┛┛┗┗┛\n");
        }
        else{
            printf("  ┏┓┏┓┳┓┏┳┓┳┏┓  ┏┓┏┓┳┳┓┏┏┓┏┓┏┓┳┓┳┓┏┓\n");
            printf("  ┃┃┣┫┣┫ ┃ ┃┣   ┗┓┣┫┃┃┃┃┣ ┃┓┣┫┣┫┃┃┣ \n");
            printf("  ┣┛┛┗┛┗ ┻ ┻┗┛  ┗┛┛┗┗┛┗┛┗┛┗┛┛┗┛┗┻┛┗┛\n");
        }
    return 0;
}

#ifdef _WIN32
    int detecterdeplacementparamwin(int **param,int *num){
        /*verification des pointeurs de num*/
            if (num == NULL) {
                printf("Le pointeur num est NULL !\n");
                exit(EXIT_FAILURE);
            }
        /*verification des pointeurs du param*/
            if (param == NULL) {
                printf("Le pointeur param est NULL !\n");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < PARAMLARG; i++) {
                if (param[i] == NULL) {
                    printf("Le pointeur param est NULL !\n");
                    exit(EXIT_FAILURE);
                }
            }
        char touche;
        int zone;
        /*Verification Des touches S/o chatgpt*/
            if(kbhit()) { // Vérifie si une touche est appuyée
                touche = getch(); // Récupère la touche appuyée

                // Vérifie si la touche est une flèche
                if(touche == 0 || touche == 224) {
                        touche = getch(); // Récupère la seconde partie de la touche (pour les flèches)
                        switch(touche) {
                            case 72: //Haut
                                zone=deplacementparam(param,1,num);
                                break;
                            case 77: //Droite
                                zone=deplacementparam(param,2,num);
                                break;
                            case 80: //Bas
                                zone=deplacementparam(param,3,num);
                                break;
                            case 75: //Gauche
                                zone=deplacementparam(param,4,num);
                                break;
                        }
                        
                    }
                }
    }
#endif
#ifdef __linux__
    int detecterdeplacementparamlinux(int **param,int *num){
        /*verification des pointeurs de num*/
            if (num == NULL) {
                printf("Le pointeur num est NULL !\n");
                exit(EXIT_FAILURE);
            }
        /*verification des pointeurs du param*/
            if (param == NULL) {
                printf("Le pointeur param est NULL !\n");
                exit(EXIT_FAILURE);
            }
            for (int i = 0; i < PARAMLARG; i++) {
                if (param[i] == NULL) {
                    printf("Le pointeur param est NULL !\n");
                    exit(EXIT_FAILURE);
                }
            }
        int ch;
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
        ch = getch();
        int zone;
        void menu();

        switch(ch) {
            case KEY_UP:
                endwin();
                zone=deplacementparam(param,1,num);
                break;
            case KEY_DOWN:
                endwin();
                zone=deplacementparam(param,3,num);
                break;
            case KEY_LEFT:
                endwin();
                zone=deplacementparam(param,4,num);
                
                break;
            case KEY_RIGHT:
                endwin();
                zone=deplacementparam(param,2,num);
                break;
            
        }
        endwin();
        return zone;
    }
#endif

int mainparam(){ 
    /*permet de gérer les paramètres*/
    int num,zone;
    /*Création de la param principale*/
        int **param=malloc(PARAMLARG*sizeof(int*)); 
        if (param == NULL) {
            printf("Le pointeur param est NULL !\n");
            exit(EXIT_FAILURE);
        }  
        for (int i = 0; i < PARAMLARG; i++) {
            param[i] = malloc(PARAMLONG * sizeof(int));
            if (param[i] == NULL) {
                printf("Le pointeur param est NULL !\n");
                exit(EXIT_FAILURE);
            }
        }
        
        creercategorieparam(param);
        param[3][8]=2;
    effacer();
    afficherparam(param);
    printf("  ┏┓┏┓┳┓┏┳┓┳┏┓  ┏┓┏┓┳┳┓┏┏┓┏┓┏┓┳┓┳┓┏┓\n");
    printf("  ┃┃┣┫┣┫ ┃ ┃┣   ┗┓┣┫┃┃┃┃┣ ┃┓┣┫┣┫┃┃┣ \n");
    printf("  ┣┛┛┗┛┗ ┻ ┻┗┛  ┗┛┛┗┗┛┗┛┗┛┗┛┛┗┛┗┻┛┗┛\n");
    while(1){
            #ifdef _WIN32
                zone=detecterdeplacementparamwin(param,&num);
            #endif
            #ifdef __linux__
                zone=detecterdeplacementparamlinux(param,&num);
            #endif  
            if(zone==1){
                return 1;
            }
            else if(zone==2){
                return 0;
            }
        }
}