#ifdef __linux__
    #include "Aleatorium.h"
#endif
/*Détecter le déplacement*/
    #ifdef _WIN32
    void detecterdeplacementwin(Joueur *joueur){
        /*Verifier pointeurs joueur*/
            verifierJoueur(joueur);
        char touche;
        int param;
        void menu();
        /*Verification Des touches*/
            if(kbhit()) { // Vérifie si une touche est appuyée
                touche = getch(); // Récupère la touche appuyée

                // Vérifie si la touche est une flèche
                if(touche == 0 || touche == 224 || touche==27) {
                    if (touche == 27) { // Si c'est la touche "Escape" //parametre
                            sauvegarderlapartie(joueur);
                            param=mainparam();
                            if(param==0){ //Retour menu
                                menu(); 
                            }
                            else{
                                effacer();
                                afficher(joueur);
                            }
                    } 
                    else {
                        touche = getch(); // Récupère la seconde partie de la touche (pour les flèches)
                        switch(touche) {
                            case 72: //Haut
                                deplacement(joueur,1);
                                break;
                            case 77: //Droite
                                deplacement(joueur,2);
                                break;
                            case 80: //Bas
                                deplacement(joueur,3);
                                break;
                            case 75: //Gauche
                                deplacement(joueur,4);
                                break;
                        }
                        
                    }
                    
                }
            }
    }
    #endif
    #ifdef __linux__
    void detecterdeplacementlinux(Joueur *joueur){
        /*Initialisation de ncurses*/
        int ch;
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
        ch = getch();// Récupère la touche appuyée
        int param;
        void menu();
        switch(ch) {
            case KEY_UP://Haut
                endwin();
                deplacement(joueur,1);
                break;
            case KEY_DOWN://Bas
                endwin();
                deplacement(joueur,3);
                break;
            case KEY_LEFT://Gauche
                endwin();
                deplacement(joueur,4);
                break;
            case KEY_RIGHT://Droite
                endwin();
                deplacement(joueur,2);
                break;
            case 27://parametre
                endwin();
                sauvegarderlapartie(joueur);
                param=mainparam(); 
                    if(param==0){
                        menu();//Retour au menu
                    }
                    else{
                        effacer();
                        afficher(joueur);
                    }
                break;
            
        }
        endwin();
        effacer();
        afficher(joueur);
    
    }
    #endif
