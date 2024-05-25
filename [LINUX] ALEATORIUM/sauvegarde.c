#ifdef __linux__
    #include "Aleatorium.h"
#endif
void sauvegarder(const Joueur* joueur, const char* nomFichier) {
    /*Verifier pointeurs joueur*/
        void verifierJoueur();
        verifierJoueur(joueur);
    FILE* fichier = fopen(nomFichier, "wb");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture = %d\n", errno);
        exit(1);
    }
    // Sauvegarder les informations de base de la structure Joueur
    fwrite(joueur, sizeof(Joueur), 1, fichier);

    // Sauvegarder la map
    for (int i = 0; i < MAP; ++i) {
        fwrite(joueur->map[i], sizeof(int), MAP, fichier);
    }
    // Sauvegarder le stockage
    fclose(fichier);
    printf("Partie sauvegardée !\n");
}

Joueur chargerPartie(const char* nomFichier) {
    Joueur joueur;
    FILE* fichier = fopen(nomFichier, "rb");
    if (fichier == NULL) {
        printf("Aucune sauvegarde trouvée. Code erreur = %d\n", errno);
        exit(1);
    }

    // Charger les informations de base de la structure Joueur
    fread(&joueur, sizeof(Joueur), 1, fichier);

    // Allouer la mémoire pour la map
    joueur.map = malloc(MAP * sizeof(int*));
    if (joueur.map == NULL) {
        printf("Erreur d'allocation mémoire pour joueur.map\n");
        exit(1);
    }
    for (int i = 0; i < MAP; ++i) {
        joueur.map[i] = malloc(MAP * sizeof(int));
        if (joueur.map[i] == NULL) {
            printf("Erreur d'allocation mémoire pour joueur.map[%d]\n", i);
            exit(1);
        }
        fread(joueur.map[i], sizeof(int), MAP, fichier);
    }
    // Allouer la mémoire pour le stockage
    joueur.StockageDesSalles = malloc(NBSALLEMAX * sizeof(int**));
    for (int i = 0; i < NBSALLEMAX; ++i) {
        joueur.StockageDesSalles[i] = malloc(NBSALLEMAX * sizeof(int*));
        for (int j = 0; j < NBSALLEMAX; ++j) {
            joueur.StockageDesSalles[i][j] = malloc(NBSALLEMAX * sizeof(int));
            fread(joueur.StockageDesSalles[i][j], sizeof(int), NBSALLEMAX, fichier);
        }
    }

    fclose(fichier);
    return joueur;
}

void sauvegarderlapartie(Joueur *joueur) {
    /*Verifier pointeurs joueur*/
        void verifierJoueur();
        verifierJoueur(joueur);
    char pseudo[15] = {0};
    // Associe le pseudo et le .txt pour créer un fichier pseudo.txt 
    strcat(pseudo, joueur->nom);
    strcat(pseudo, ".txt");
    // Va Sauvegarder la partie
    sauvegarder(joueur, pseudo);
}

int verifcharge(Joueur *joueur) {
    /*Verifier pointeurs joueur*/
        void verifierJoueur();
        verifierJoueur(joueur);
    // Chargement de la partie
    char pseudo[20] = {0};
    printf("\033[0;33m[Système Aléatorium]\033[0m : Quel est votre pseudo ? :");
    void verifchar();
    verifchar(joueur->nom, 10);
    strcat(pseudo, joueur->nom);
    strcat(pseudo, ".txt");
    FILE* fichier = fopen(pseudo, "rb");
    if (fichier != NULL) {
        fclose(fichier); // Le fichier existe, on peut sortir de la boucle
        return 1;
    } else {
        printf("\033[0;33m[Système Aléatorium]\033[0m : Aucune sauvegarde trouvée. Veuillez réessayer.\n", joueur->nom);
        void continuer();
        continuer();
        //fclose(fichier); // Le fichier existe, on peut sortir de la boucle
        return 0;
    }

}

Joueur* chargerlapartie(Joueur *joueur) {
    /*Verifier pointeurs joueur*/
        void verifierJoueur();
        verifierJoueur(joueur);
    // Chargement de la partie
    char pseudo[15] = {0};
    strcat(pseudo, joueur->nom);
    strcat(pseudo, ".txt");
    
    *joueur = chargerPartie(pseudo);
    return joueur;
}

