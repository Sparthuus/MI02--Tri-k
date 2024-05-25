#ifdef __linux__
    #include "Aleatorium.h"
#endif
/*Deplacement jeu*/
void deplacement(Joueur *joueur,int direction){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    /*Rechercher Position du joueur*/
        int y,x;
        int resulat;
        RechercherJoueur(&y,&x,joueur);
    /*Gérer la colision ou non*/
        /*Haut*/
            if(direction==1){
                /*Si c'est du Sol*/
                    if(joueur->map[y-1][x]==0){
                        joueur->map[y-1][x]=2;
                        joueur->map[y][x]=0;
                    }
                /*Si c'est une porte*/
                    else if(joueur->map[y-1][x]==3&&(joueur->cle)>0){
                        srand((joueur->graine)+(y*x)+303*303);
                        joueur->cle --;
                        joueur->map[y-1][x]=2;
                        joueur->map[y][x]=0;
                        CreationSalleHaut(joueur);
                    }
                /*Si c'est un bonus*/
                    else if(joueur->map[y-1][x]==4){
                        joueur->map[y-1][x]=2;
                        joueur->map[y][x]=0;
                        bonus(joueur);
                    }
                /*Si c'est un mur*/
                    else if(joueur->map[y-1][x]==1||joueur->map[y-1][x]==3){
                        return;
                    }
                /*Cherche ma clé*/
                    else if(joueur->map[y-1][x]==58){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai caché la clé dans l'Aléatorium !\n         A toi de la retrouver !\033[0m\n"); 
                        continuer();
                        joueur->map[y-1][x]=0;
                        cherchemoi(joueur,5);
                    }
                    else if(joueur->map[y-1][x]==5){
                        joueur->map[y-1][x]=2;
                        joueur->map[y][x]=0;
                        joueur->cle ++;
                    }
                /*Cherche ma montre*/
                    else if(joueur->map[y-1][x]==59){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                        continuer();
                        cherchemoi(joueur,6);
                        joueur->map[y-1][x]=7;
                    }
                    else if(joueur->map[y-1][x]==7){
                        if(joueur->montre==0){
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                            continuer();
                        }
                        else{
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mMerci je vais te donner ta clé !\033[0m\n"); 
                            continuer(); 
                            joueur->montre--;
                            joueur->cle++;
                            joueur->map[y-1][x]=0;
                        }
                    }
                    else if(joueur->map[y-1][x]==6){
                        joueur->map[y-1][x]=2;
                        joueur->map[y][x]=0;
                        joueur->montre ++;
                    }
                /*Si c'est un mini jeu*/
                    else{
                        resulat=detecterminijeux(joueur->map[y-1][x],joueur);
                        if (resulat==1){
                            joueur->map[y-1][x]=2;
                            joueur->map[y][x]=0;
                        }
                        else{
                            joueur->map[y][x]=0;
                            joueur->map[joueur->py][joueur->px]=2;
                        }
                    }
            }
        /*Droite*/
            else if(direction==2){
                /*Si c'est du Sol*/
                    if(joueur->map[y][x+1]==0){
                        joueur->map[y][x+1]=2;
                        joueur->map[y][x]=0;
                    }
                /*Si c'est une porte*/
                    else if(joueur->map[y][x+1]==3&&(joueur->cle)>0){
                        srand((joueur->graine)+(y*x)+303*303);
                        joueur->cle --;
                        joueur->map[y][x+1]=2;
                        joueur->map[y][x]=0;
                        CreationSalleDroite(joueur);
                    }
                /*Si c'est un bonus*/
                    else if(joueur->map[y][x+1]==4){
                        joueur->map[y][x+1]=2;
                        joueur->map[y][x]=0;
                        bonus(joueur);
                    }
                /*Cherche ma clé*/
                    else if(joueur->map[y][x+1]==58){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai caché la clé dans l'Aléatorium !\n         A toi de la retrouver !\033[0m\n"); 
                        continuer();
                        joueur->map[y][x+1]=0;
                        cherchemoi(joueur,5);
                    }
                    else if(joueur->map[y][x+1]==5){
                        joueur->map[y][x+1]=2;
                        joueur->map[y][x]=0;
                        joueur->cle ++;
                    }
                /*Cherche ma montre*/
                    else if(joueur->map[y][x+1]==59){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                        continuer();
                        cherchemoi(joueur,6);
                        joueur->map[y][x+1]=7;
                    }
                    else if(joueur->map[y][x+1]==7){
                        if(joueur->montre==0){
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                            continuer();
                        }
                        else{
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mMerci je vais te donner ta clé !\033[0m\n"); 
                            continuer(); 
                            joueur->montre--;
                            joueur->cle++;
                            joueur->map[y][x+1]=0;
                        }
                    }
                    else if(joueur->map[y][x+1]==6){
                        joueur->map[y][x+1]=2;
                        joueur->map[y][x]=0;
                        joueur->montre ++;
                    }
                /*Si c'est un mur*/
                    else if(joueur->map[y][x+1]==1||joueur->map[y][x+1]==3){
                        return;
                    }
                /*Si c'est un mini jeu*/
                    else{
                        resulat=detecterminijeux(joueur->map[y][x+1],joueur);
                        if (resulat==1){
                            joueur->map[y][x+1]=2;
                            joueur->map[y][x]=0;
                        }
                        else{
                            joueur->map[y][x]=0;
                            joueur->map[joueur->py][joueur->px]=2;
                        }
                    }
            }
        /*Bas*/
            else if(direction==3){
                /*Si c'est du Sol*/
                    if(joueur->map[y+1][x]==0){
                        joueur->map[y+1][x]=2;
                        joueur->map[y][x]=0;
                    }
                /*Si c'est une porte*/
                    else if(joueur->map[y+1][x]==3&&(joueur->cle)>0){
                        srand((joueur->graine)+(y*x)+303*303);
                        joueur->cle --;
                        joueur->map[y+1][x]=2;
                        joueur->map[y][x]=0;
                        CreationSalleBas(joueur);
                    }
                /*Si c'est un Bonus*/
                    else if(joueur->map[y+1][x]==4){
                            joueur->map[y+1][x]=2;
                            joueur->map[y][x]=0;
                            bonus(joueur);
                        }
                /*Si c'est un mur*/
                    else if(joueur->map[y+1][x]==1||joueur->map[y+1][x]==3){
                        return;
                    }
                /*Cherche ma clé*/
                    else if(joueur->map[y+1][x]==58){
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai caché la clé dans l'Aléatorium !\n         A toi de la retrouver !\033[0m\n"); 
                        continuer();
                        joueur->map[y+1][x]=0;
                        cherchemoi(joueur,5);
                    }
                    else if(joueur->map[y+1][x]==5){
                        joueur->map[y+1][x]=2;
                        joueur->map[y][x]=0;
                        joueur->cle ++;
                    }
                /*Cherche ma montre*/
                    else if(joueur->map[y+1][x]==59){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                        continuer();
                        cherchemoi(joueur,6);
                        joueur->map[y+1][x]=7;
                    }
                    else if(joueur->map[y+1][x]==7){
                        if(joueur->montre==0){
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                            continuer();
                        }
                        else{
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mMerci je vais te donner ta clé !\033[0m\n"); 
                            continuer(); 
                            joueur->montre--;
                            joueur->cle++;
                            joueur->map[y+1][x]=0;
                        }
                    }
                    else if(joueur->map[y+1][x]==6){
                        joueur->map[y+1][x]=2;
                        joueur->map[y][x]=0;
                        joueur->montre ++;
                    }
                /*Si c'est un mini jeu*/
                    else{
                        resulat=detecterminijeux(joueur->map[y+1][x],joueur);
                        if (resulat==1){
                            joueur->map[y+1][x]=2;
                            joueur->map[y][x]=0;
                        }
                        else{
                            joueur->map[y][x]=0;
                            joueur->map[joueur->py][joueur->px]=2;
                        }
                    } 
            }
        /*Gauche*/
            else if(direction==4){
                /*Si c'est du Sol*/
                    if(joueur->map[y][x-1]==0){
                        joueur->map[y][x-1]=2;
                        joueur->map[y][x]=0;
                    }
                /*Si c'est une porte*/
                    else if(joueur->map[y][x-1]==3&&(joueur->cle)>0){
                        srand((joueur->graine)+(y*x)+303*303);
                        joueur->cle --;
                        joueur->map[y][x-1]=2;
                        joueur->map[y][x]=0;
                        CreationSalleGauche(joueur);
                    }
                /*Si c'est un bonus*/
                    else if(joueur->map[y][x-1]==4){
                        joueur->map[y][x-1]=2;
                        joueur->map[y][x]=0;
                        bonus(joueur);
                    }
                /*Cherche ma clé*/
                    else if(joueur->map[y][x-1]==58){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai caché la clé dans l'Aléatorium !\n         A toi de la retrouver !\033[0m\n"); 
                        continuer();
                        joueur->map[y][x-1]=0;
                        cherchemoi(joueur,5);
                    }
                    else if(joueur->map[y][x-1]==5){
                        joueur->map[y][x-1]=2;
                        joueur->map[y][x]=0;
                        joueur->cle ++;
                    }
                /*Cherche ma montre*/
                    else if(joueur->map[y][x-1]==59){
                        effacer();
                        afficher(joueur);
                        printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                        continuer();
                        cherchemoi(joueur,6);
                        joueur->map[y][x-1]=7;
                    }
                    else if(joueur->map[y][x-1]==7){
                        if(joueur->montre==0){
                            printf("\033[0;33m[René]\033[0m : \033[1;31mJ'ai perdu ma montre dans l'Aléatorium !\n         Peux tu me la chercher contre une clé ?\033[0m\n"); 
                            continuer();
                        }
                        else{
                            effacer();
                            afficher(joueur);
                            printf("\033[0;33m[René]\033[0m : \033[1;31mMerci je vais te donner ta clé !\033[0m\n"); 
                            continuer(); 
                            joueur->montre--;
                            joueur->cle++;
                            joueur->map[y][x-1]=0;
                        }
                    }
                    else if(joueur->map[y][x-1]==6){
                        joueur->map[y][x-1]=2;
                        joueur->map[y][x]=0;
                        joueur->montre ++;
                    }
                /*Si c'est un mur*/
                    else if(joueur->map[y][x-1]==1||joueur->map[y][x-1]==3){
                        return;
                    }
                /*Si c'est un mini jeu*/
                    else{
                        resulat=detecterminijeux(joueur->map[y][x-1],joueur);
                        if (resulat==1){
                            joueur->map[y][x-1]=2;
                            joueur->map[y][x]=0;
                        }
                        else{
                            joueur->map[y][x]=0;
                            joueur->map[joueur->py][joueur->px]=2;
                        }
                    }
            }
    effacer();
    afficher(joueur);
}
