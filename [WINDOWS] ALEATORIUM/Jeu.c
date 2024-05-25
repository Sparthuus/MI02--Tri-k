#ifdef __linux__
    #include "Aleatorium.h"
#endif

void jeu(Joueur *joueur,int introduction){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    effacer();
    void perdu();
    /*Initialisation*/
    ///////////////////////////////////////////////////////////////////////////////////////
    if(introduction==1){
            intro(joueur);
        /*Création de la Map principale*/
            srand(joueur->graine);
            joueur->map=malloc(MAP*sizeof(int*));   
            for (int i = 0; i < MAP; i++) {
                joueur->map[i] = malloc(MAP * sizeof(int));
            }
            for(int i=0;i<MAP;i++){ //Mettre à 0 la Map
                for(int j=0;j<MAP;j++){
                    joueur->map[i][j]=303;
                }
            }
        /*Définir les variables pour les salles*/
            joueur->porte=(rand()%(NBSALLEMAX - 5 + 1)+5)-1;
            joueur->StockageDesSalles=(int ***)calloc((joueur->porte)+1,sizeof(int**));
            joueur->salle=0;
            joueur->sallemax=((joueur->porte)+1);
            CreationSallePrincipale(joueur);
    }
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    /*Graine du Monde*/
        srand(joueur->graine);
        //joueur->graine=303;
    /*Lancement de la Partie*/
        effacer();
        afficher(joueur);
        /*Variable temps*/
            time_t debut=0, actuel=2;
            //const int TEMPS_LIMITE = 5 * 60;
            const int TEMPS_LIMITE = 10;
            double temps_ecoule;
        while(1){
            /*chrono*/
                time(&debut);
            /*verif pv*/
                if(joueur->pv==0){
                perdu(joueur);
                }
            /*verif temps*/
                if ((joueur->temps) <= 0) {
                    printf("\033[0;33m[Système Aléatorium]\033[0m : \033[1;31mLe temps imparti est écoulé !\033[0m\n");
                    continuer();
                    perdu(joueur);
                }
            /*jeus*/   
                #ifdef _WIN32
                    detecterdeplacementwin(joueur);//Windows
                #endif
                #ifdef __linux__
                    detecterdeplacementlinux(joueur);//Linux
                #endif
            /*chrono*/
                time(&actuel);
                temps_ecoule = difftime(actuel, debut);
                (joueur->temps) -= (int)temps_ecoule;
                if (joueur->temps%60==0) {
                    effacer();
                    afficher(joueur);
                    joueur->temps--;
                }
        }
}