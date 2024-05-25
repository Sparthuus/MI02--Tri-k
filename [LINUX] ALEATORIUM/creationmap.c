
/*Map*/
#ifdef __linux__
    #include "Aleatorium.h"
#endif
    void VerificationPorte(Joueur *joueur,int principale){
        /*Fonction qui permet de detecter si la porte peut exister ou non
        Pour ce faire il va verifier toutes les cases et voient si ya de la place*/

        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        int Verification=1;
        for(int i=0;i<MAP;i++){
            for(int j=0;j<MAP;j++){
                
                /*Porte du haut*/
                    if(joueur->map[i][j]==31){
                        Verification=1;
                        for(int k=0 ; k<MAX-1 ; k++){
                            for(int l=0; l<MAX ; l++){
                                if(joueur->map[i-1-k][j-1+l]!=303){
                                    Verification=0;
                                }
                            }
                        }
                        if((Verification&&(joueur->porte)>0)||principale){
                            for(int k=0 ; k<MAX-1 ; k++){
                                for(int l=0; l<MAX ; l++){
                                    if(joueur->map[i-1-k][j-1+l]==303){
                                        joueur->map[i-1-k][j-1+l]=444;//Placer des marques pour éviter la superposition
                                    }
                                }
                            }
                            joueur->map[i][j]=3;//Mise en place de la vraie porte
                            (joueur->porte)-=1;
                        }
                        else{
                            joueur->map[i][j]=1;
                        }
                        
                    }
                /*Porte de Droite*/
                    else if(joueur->map[i][j]==32){
                        Verification=1;
                        for(int k=0 ; k<MAX ; k++){
                            for(int l=0; l<MAX-1 ; l++){
                                if(joueur->map[i-1+k][j+1+l]!=303){
                                    Verification=0;
                                }
                            }
                        }
                        if((Verification&&(joueur->porte)>0)||principale){
                            for(int k=0 ; k<MAX ; k++){
                                for(int l=0; l<MAX-1 ; l++){
                                    if(joueur->map[i-1+k][j+1+l]==303){
                                        joueur->map[i-1+k][j+1+l]=444;//Placer des marques pour éviter la superposition
                                    }
                                }
                            }
                            joueur->map[i][j]=3;
                            (joueur->porte)-=1;
                        }
                        else{
                            joueur->map[i][j]=1;
                        }
                    }
                /*Porte du bas*/
                    else if(joueur->map[i][j]==33){
                        Verification=1;
                        for(int k=0 ; k<MAX-1 ; k++){
                            for(int l=0; l<MAX ; l++){
                                if(joueur->map[i+1+k][j-1+l]!=303){
                                   Verification=0;
                                }
                            }
                        }
                        if((Verification&&(joueur->porte)>0)||principale){
                            for(int k=0 ; k<MAX-1 ; k++){
                                for(int l=0; l<MAX ; l++){
                                    if(joueur->map[i+1+k][j-1+l]==303){
                                        joueur->map[i+1+k][j-1+l]=444;//Placer des marques pour éviter la superposition
                                    }
                                }
                            }
                            joueur->map[i][j]=3;
                            (joueur->porte)-=1;
                        }
                        else{
                            joueur->map[i][j]=1;
                        }
                    }
                /*Porte de Gauche*/
                    else if(joueur->map[i][j]==34){
                        Verification=1;
                        for(int k=0 ; k<MAX ; k++){
                            for(int l=0; l<MAX-1 ; l++){
                                if(joueur->map[i+1-k][j-1-l]!=303){
                                    Verification=0;
                                }
                            }
                        }
                        if((Verification&&(joueur->porte)>0)||principale){
                            for(int k=0 ; k<MAX ; k++){
                                for(int l=0; l<MAX-1 ; l++){
                                    if(joueur->map[i+1-k][j-1-l]==303){
                                        joueur->map[i+1-k][j-1-l]=444;
                                    }
                                }
                            }
                            joueur->map[i][j]=3;
                            (joueur->porte)-=1;
                            
                        }
                        else{
                            joueur->map[i][j]=1;
                        }
                    }
            }
        }

    }
    void CreationSallePrincipale(Joueur *joueur){ 
        joueur->salle++;
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*Définir La taille de la Salle*/
            int longueur=rand()%(MAX-2)+4; //+1
            int largeur=rand()%(MAX-2)+4; //+1
        
        /*Création de la salle*/
            int **tab=malloc(longueur*sizeof(int*));
            for (int i = 0; i < longueur; i++) {
                tab[i] = malloc(largeur * sizeof(int));
            }
        /*Génération de la Salle Vide*/
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(i==0||i==longueur-1||j==largeur-1||j==0){
                        tab[i][j]=1; //Création des murs autour de la salle
                    }
                    else{
                        tab[i][j]=0; //Création du sol de la salle
                    }
                }
            }
        /*Génération des Portes*/
            //Création d'une porte en Haut
                int placerPorte=rand()%(largeur-2)+1;
                tab[0][placerPorte]=31; 
            //Création d'une salle à Droite
                placerPorte=rand()%(longueur-2)+1;
                tab[placerPorte][largeur-1]=32; 
            //Création d'une salle en Bas
                placerPorte=rand()%(largeur-2)+1;
                tab[longueur-1][placerPorte]=33;
            //Création d'une salle à Gauche
                placerPorte=rand()%(longueur-2)+1;
                tab[placerPorte][0]=34;

        /*Génération du joueur*/
            tab[longueur/2][largeur/2]=2;
        /*Mise en place d'un jeu ou du boss*/
            CreationJeu(tab,longueur,largeur);
        /*Stocker la première Salle*/
            joueur->StockageDesSalles[0]=tab;

        /*Stocker la Salle sur la Map*/
            int millieu=MAP/2;
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    joueur->map[millieu+i][millieu+j]=joueur->StockageDesSalles[0][i][j];           
                }
            }  
        /*Stocker la position initiale*/ 
        for(int y=0;y<MAP;y++){
            for(int x=0;x<MAP;x++){
                if(joueur->map[y][x]==2){
                    joueur->py=y;
                    joueur->px=x;
                }
            }
        }
    
        /*Ajouter des Marqueurs de colision de porte*/
            VerificationPorte(joueur,1);
        /*Libération de la mémoire*/
            free(tab);  
    }
    void CreationSalleHaut(Joueur *joueur){
        joueur->salle++;
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*Rechercher Position du joueur*/
            int y,x;
            RechercherJoueur(&y,&x,joueur);
        /*Retirer les marqueurs*/
            for(int i=0 ; i<MAX-1 ; i++){
                for(int j=0; j<MAX ; j++){
                    if(joueur->map[y-1-i][x-1+j]==444){
                        joueur->map[y-1-i][x-1+j]=303;//Placer des marques pour éviter la superposition
                    }
                }
            }
        /*Définir La taille de la Salle*/  
            int Verification=0;
            int longueur=3,largeur=3;
                do{
                    //Verifier pour la longueur
                    Verification=0;
                    longueur=rand()%(MAX-2)+3;
                    largeur=rand()%(MAX-2)+3;
                    for(int i=0; i<longueur;i++){
                        for(int j=0; j<largeur; j++){
                            if((joueur->map[y-i][x-1+j]!=303)&&(joueur->map[y-i][x-1+j]!=1)&&(joueur->map[y-i][x-1+j]!=2)){
                                Verification=1;
                            }
                        }
                    }
                }while(Verification);
        /*Création d'une salle*/
            int **tab=malloc(longueur*sizeof(int*));
                for (int i = 0; i < longueur; i++) {
                    tab[i] = malloc(largeur * sizeof(int));
                }
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(i==0||i==longueur-1||j==largeur-1||j==0){
                        tab[i][j]=1; //Création des murs autour de la salle
                    }
                    else{
                        tab[i][j]=0; //Création du sol de la salle
                    }
                }
            }
        /*Mise en place d'un jeu ou du boss*/
            if(joueur->salle==joueur->sallemax){
                CreationBoss(tab,longueur,largeur);
            }
            else{
                CreationJeu(tab,longueur,largeur);
                /*Mise en place d'un Bonus*/
                CreationBonus(tab,longueur,largeur);
            }
        /*Création des portes*/ 
            int piece=rand()%5+1; //4 chance sur 5 de créer une porte
            /*Porte du Haut*/
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(largeur-2)+1;
                    tab[0][placerPorte]=31;
                }
            /*Porte de Droite*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(longueur-2)+1;
                    tab[placerPorte][largeur-1]=32;
                }
            /*Porte du Bas*/
            /*Porte de Gauche*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(longueur-2)+1;
                    tab[placerPorte][0]=34;
                }
        /*Stocker la Salle*/
            joueur->StockageDesSalles[joueur->salle]=tab;
        /*Afficher sur la map*/
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(joueur->map[y-i][x+j-1]!=2){
                        joueur->map[y-i][x+j-1]=tab[longueur-1-i][j];
                    }
                }
            }
        /*Vérification des portes*/
            VerificationPorte(joueur,0);
        /*Libération de la mémoire*/
            free(tab);  

    }
    void CreationSalleDroite(Joueur *joueur){
        joueur->salle++;
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*Rechercher Position du joueur*/
            int y,x;
            RechercherJoueur(&y,&x,joueur);
        /*Retirer les marqueurs*/
            for(int k=0 ; k<MAX ; k++){
                for(int j=0; j<MAX-1 ; j++){
                    if(joueur->map[y-1+k][x+1+j]==444){
                        joueur->map[y-1+k][x+1+j]=303;//Placer des marques pour éviter la superposition
                    }
                } 
            }
        /*Définir La taille de la Salle*/
            
            int Verification=0;
            int longueur=3,largeur=3;
                do{
                    Verification=0;
                    longueur=rand()%(MAX-2)+3;
                    largeur=rand()%(MAX-2)+3;
                    for(int i=0; i<longueur;i++){
                        for(int j=0; j<largeur; j++){
                            if((joueur->map[y-1+i][x+j]!=303)&&(joueur->map[y-1+i][x+j]!=1)&&(joueur->map[y-1+i][x+j]!=2)){
                                Verification=1;
                            }
                        }
                    }
                    
                    
                }while(Verification);
                
        /*Création d'une salle*/
            int **tab=malloc(longueur*sizeof(int*));
                for (int i = 0; i < longueur; i++) {
                    tab[i] = malloc(largeur * sizeof(int));
                }
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(i==0||i==longueur-1||j==largeur-1||j==0){
                        tab[i][j]=1; //Création des murs autour de la salle
                    }
                    else{
                        tab[i][j]=0; //Création du sol de la salle
                    }
                }
            }
        /*Mise en place d'un jeu ou du boss*/
            if(joueur->salle==joueur->sallemax){
                CreationBoss(tab,longueur,largeur);
            }
            else{
                CreationJeu(tab,longueur,largeur);
                /*Mise en place d'un Bonus*/
                CreationBonus(tab,longueur,largeur);
            }
            
        
        /*Création des portes*/ 
            int piece=rand()%5+1; //4 chance sur 5 de créer une porte
            /*Porte du Haut*/
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(largeur-2)+1;
                    tab[0][placerPorte]=31;
                }
            /*Porte de Droite*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(longueur-2)+1;
                    tab[placerPorte][largeur-1]=32;
                }
            /*Porte du Bas*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(largeur-2)+1;
                    tab[longueur-1][placerPorte]=33;
                }
            /*Porte de Gauche*/
        /*Stocker la Salle*/
            joueur->StockageDesSalles[joueur->salle]=tab;
        /*Afficher sur la map*/
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(joueur->map[y+i-1][x+j]!=2){
                        joueur->map[y+i-1][x+j]=tab[i][j];
                    }
                }
            }
        /*Vérification des portes*/
            VerificationPorte(joueur,0);
        /*Libération de la mémoire*/
            free(tab); 
        
    }
    void CreationSalleBas(Joueur *joueur){
        joueur->salle++;
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*Rechercher Position du joueur*/
            int y,x;
            RechercherJoueur(&y,&x,joueur);
        /*Retirer les marqueurs*/
            for(int i=0 ; i<MAX-1 ; i++){
                for(int j=0; j<MAX ; j++){
                    if(joueur->map[y+1+i][x-1+j]==444){
                        joueur->map[y+1+i][x-1+j]=303;//Placer des marques pour éviter la superposition
                    }
                }
            }
        /*Définir La taille de la Salle*/
            int Verification=0;
            int longueur=3,largeur=3;
            do{
                Verification=0;
                longueur=rand()%(MAX-2)+3;
                largeur=rand()%(MAX-2)+3;
                for(int i=0; i<longueur;i++){
                    for(int j=0; j<largeur; j++){
                        if((joueur->map[y+i][x-1+j]!=303)&&(joueur->map[y+i][x-1+j]!=1)&&(joueur->map[y+i][x-1+j]!=2)){
                            Verification=1;
                        }
                    }
                }
                
                
            }while(Verification);
        /*Création d'une salle*/
            int **tab=malloc(longueur*sizeof(int*));
                for (int i = 0; i < longueur; i++) {
                    tab[i] = malloc(largeur * sizeof(int));
                }
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(i==0||i==longueur-1||j==largeur-1||j==0){
                        tab[i][j]=1; //Création des murs autour de la salle
                    }
                    else{
                        tab[i][j]=0; //Création du sol de la salle
                    }
                }
            }
        /*Mise en place d'un jeu ou du boss*/
            if(joueur->salle==joueur->sallemax){
                CreationBoss(tab,longueur,largeur);
            }
            else{
                CreationJeu(tab,longueur,largeur);
                /*Mise en place d'un Bonus*/
                CreationBonus(tab,longueur,largeur);
            }
            
        
        /*Création des portes*/ 
            int piece=rand()%5+1; //4 chance sur 5 de créer une porte
            /*Porte du Haut*/
            /*Porte de Droite*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(longueur-2)+1;
                    tab[placerPorte][largeur-1]=32;
                }
            /*Porte du Bas*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(largeur-2)+1;
                    tab[longueur-1][placerPorte]=33;
                }
            /*Porte de Gauche*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(longueur-2)+1;
                    tab[placerPorte][0]=34;
                }
        /*Stocker la Salle*/
            joueur->StockageDesSalles[joueur->salle]=tab;
        /*Afficher sur la map*/
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(joueur->map[y+i][x+j-1]!=2){
                        joueur->map[y+i][x+j-1]=tab[i][j];
                    }
                }
            }
        /*Vérification des portes*/
            VerificationPorte(joueur,0);
        /*Libération de la mémoire*/
            free(tab);  
        
    }
    void CreationSalleGauche(Joueur *joueur){
        joueur->salle++;
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        /*Rechercher Position du joueur*/
            int y,x;
            RechercherJoueur(&y,&x,joueur);
        /*Retirer les marqueurs*/
            for(int i=0 ; i<MAX ; i++){
                for(int j=0; j<MAX-1 ; j++){
                    if(joueur->map[y+1-i][x-1-j]==444){
                        joueur->map[y+1-i][x-1-j]=303;
                    }
                }
            }
        /*Définir La taille de la Salle*/
            int Verification=0;
            int longueur=3,largeur=3;
            do{
                Verification=0;
                longueur=rand()%(MAX-2)+3;
                largeur=rand()%(MAX-2)+3;
                for(int i=0; i<longueur;i++){
                    for(int j=0; j<largeur; j++){
                        if((joueur->map[y+1-i][x-j]!=303)&&(joueur->map[y+1-i][x-j]!=1)&&(joueur->map[y+1-i][x-j]!=2)){
                            Verification=1;
                        }
                    }
                }
            }while(Verification);
        /*Création d'une salle*/
            int **tab=malloc(longueur*sizeof(int*));
                for (int i = 0; i < longueur; i++) {
                    tab[i] = malloc(largeur * sizeof(int));
                }
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(i==0||i==longueur-1||j==largeur-1||j==0){
                        tab[i][j]=1; //Création des murs autour de la salle
                    }
                    else{
                        tab[i][j]=0; //Création du sol de la salle
                    }
                }
            } 
        /*Mise en place d'un jeu ou du boss*/
            if(joueur->salle==joueur->sallemax){
                CreationBoss(tab,longueur,largeur);
            }
            else{
                CreationJeu(tab,longueur,largeur);
                /*Mise en place d'un Bonus*/
                CreationBonus(tab,longueur,largeur);
            };
            
        
        /*Création des portes*/ 
            int piece=rand()%5+1; //4 chance sur 5 de créer une porte
            /*Porte du Haut*/
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(largeur-2)+1;
                    tab[0][placerPorte]=31;
                }
            /*Porte de Droite*/
            /*Porte du Bas*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(largeur-2)+1;
                    tab[longueur-1][placerPorte]=33;
                }
            /*Porte de Gauche*/
                piece=rand()%5+1;
                if((piece!=5) && (joueur->porte)>0){
                    int placerPorte=rand()%(longueur-2)+1;
                    tab[placerPorte][0]=34;
                }
        /*Stocker la Salle*/
            joueur->StockageDesSalles[joueur->salle]=tab;
        /*Afficher sur la map*/
            for(int i=0;i<longueur;i++){
                for(int j=0;j<largeur;j++){
                    if(joueur->map[y+1-i][x-j]!=2){
                        joueur->map[y+1-i][x-j]=tab[longueur-1-i][largeur-1-j];
                    }
                }
            }
        /*Vérification des portes*/
            VerificationPorte(joueur,0);
        /*Libération de la mémoire*/
            free(tab);  

    }
