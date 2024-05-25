/*variables*/
    /*Définir Logiciel*/
        #ifdef _WIN32
            #include <conio.h>
        #elif __linux__
            #include <ncurses.h>
            #include <termios.h>
        #endif
    /*Bibliothèque*/
        /*Universel*/
            #include <stdio.h>
            #include <stdlib.h>
            #include <time.h>
            #include <unistd.h> 
            #include <string.h>
            #include <errno.h>  
    /*Variable qu'on peut varier*/
        #define HACK 0
        #define NBSALLEMAX 12
        #define MAX 15 //Taille de la Salle au maximum
        #define MAP (NBSALLEMAX * MAX + VISION * 2) //Définir la taille de Map
        #define VISION 9 //Définir la vision du joueur
        #define MAXXP 5 //Définir le maximum d'expérience requis
        #define TEMPSLIMITE 20*60
    /*Variable qu'il ne faut pas changer*/
        #define NBDEJEU 11 //Nb de jeu dispo
        #define MENU 10
        #define MENULONG 17
        #define MENULARG 12
        #define PARAMLONG 17
        #define PARAMLARG 7
        #define COURSE 10
        /*Alexandre*/
        #define TAILLE 3
        #define TAILLE2 5
        #define TAILLE3 40
        #define MOUTONS 5
            /*Boss*/
            #define COMPTEURFLASH 6
            #define COMPTEURULT 5
            #define TEMPSSOUSFLASH 1
            #define TEMPSSOUSULT 0
            #define MONSTRES 1
            /*Batum*/
            #define taille 6
            #define MANCHE 1
        /*Mathieu*/
        #define A 20
        #define QUESTION 8
        #define NBQUESTION 8 
//Outils
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
    void continuer();
    void effacer();
    void afficher(Joueur *joueur);
    void RechercherJoueur(int *py,int *px, Joueur *joueur);
    void RechercherJoueurMenu(int *py,int *px, int **menu);
    int detecterminijeux(int num, Joueur *joueur);
    int verifscan(int min,int max);
    void verifierJoueur(const Joueur *joueur);
    void CreationJeu(int **tab, int longueur, int largeur);
    void CreationBonus(int **tab, int longueur, int largeur);
    void CreationBoss(int **tab, int longueur, int largeur);
    void afficherstat(Joueur *joueur);
    void verifchar(char *nom, int max);
    void perdu(Joueur *joueur);
    void gagne(Joueur *joueur);
    

//Jeux
    void jeu(Joueur *joueur,int introduction);
//deplacement
    void deplacement(Joueur *joueur,int direction);
//detecter deplacment
    #ifdef _WIN32
        void detecterdeplacementwin(Joueur *joueur);
    #endif
    #ifdef __linux__
        void detecterdeplacementlinux(Joueur *joueur);
    #endif
//creation map
    void VerificationPorte(Joueur *joueur,int principale) ;
    void CreationSallePrincipale(Joueur *joueur);
    void CreationSalleHaut(Joueur *joueur);
    void CreationSalleDroite(Joueur *joueur);
    void CreationSalleBas(Joueur *joueur);
    void CreationSalleGauche(Joueur *joueur);
//Intro
    void intro(Joueur *joueur);
//Menu
    void affichermenu(int **menu);
    void creercategorie(int **menu);
    void messagequiter() ;
    void deplacementmenu(int **menu,int direction,int *num,Joueur *joueur);
    #ifdef _WIN32
        void detecterdeplacementmenuwin(int **menu,int *num,Joueur *joueur);
    #endif
    #ifdef __linux__
        void detecterdeplacementmenulinux(int **menu,int *num,Joueur *joueur);
    #endif
    void menu();
//param
    void afficherparam(int **param);
    void RechercherJoueurParam(int *py,int *px, int **param);
    void creercategorieparam(int **param);
    int deplacementparam(int **param,int direction,int *num);
    #ifdef _WIN32
        int detecterdeplacementparamwin(int **param,int *num);
    #endif
    #ifdef __linux__
        int detecterdeplacementparamlinux(int **param,int *num);
    #endif
    int mainparam(); 
//sauvegarde
    void sauvegarder(const Joueur* joueur, const char* nomFichier);
    Joueur chargerPartie(const char* nomFichier) ;
    void sauvegarderlapartie(Joueur *joueur) ;
    int verifcharge(Joueur *joueur) ;
    Joueur* chargerlapartie(Joueur *joueur) ;



//minijeux
    int pileouface();
    int calcul();
    int prv();
    int tictac();
    void bonus(Joueur *joueur);
    void cherchemoi(Joueur *joueur,int objets);
    int detecterminijeux(int num, Joueur *joueur);

//Jeu Pomme 
    void afficheTab2D(char tab[TAILLE][TAILLE]);
    void reglesp();
    int victoire(char tab[TAILLE][TAILLE]);
    int joueurp(char tab[TAILLE][TAILLE], int a, int b);
    int Ordi(char tab[TAILLE][TAILLE]);
    int ppartie(char tab[TAILLE][TAILLE], int choix2, int manche);
    int pommeraison();

//Jeu Question pour Un Golem
    typedef struct{
        char question[200];
        char reponse[A];
        
    }Questions;
    void affregle();
    void poserQuestion(Questions *list, int numQuestion);
    int verifierReponse(Questions *list, int numeroQuestion, char* reponse);
    int questiongolem();

//Jeu rapidos
    void regleRapidos();
    void affichercourse(int *avion, int*cheval, int*velo,int manche,int propal);
    void avancerrapidos(int *tab);
    int verificationrapidos(int *tab);
    int jeurapidos(int manche);
    int rapidos();

//Jeu Trouve le Mouton
    void reglesmouton();
    void debut();
    void remplirtab(char tab[TAILLE2][TAILLE2]);
    void affichetab(char tab[TAILLE2][TAILLE2]);
    int conversion(char a);
    int conversion2(char a);
    int veriftab(char tab[TAILLE2][TAILLE2], char casee[]);
    int verifmouton(char tab[TAILLE2][TAILLE2], char tab2[TAILLE2][TAILLE2], char casee[]);
    void moutons(char tab[TAILLE2][TAILLE2]);
    int trouvelemouton();
//jeu batum
    void afficheTab2Dbatum(char tab[taille][taille]);
    void constructTab(char tab[taille][taille]);
    void debutbato(int a);
    int conversion3(int a);
    int soustraction(char*** bateau,int k,int i);
    int soustraction2(char*** bateau, int k, int i);
    int verifbateau(char tab[taille][taille],char ***bateau, int taillebateau, int i,int k,int poschar,int posint);
    int casePrise(char tab[taille][taille], int poschar, int posint,int k);
    void creebateau(char tab[taille][taille],int taillebateau, int sens, int direction, int abscisse, int ordonnee,int k);
    int verifbateauu(char tab[taille][taille], int taillebateau, int sens, int direction,int abscisse,int ordonnee);
    int ordi3(char tab[taille][taille],char tabpremierbateau[taille][taille], char tabsecondbateau[taille][taille], char tabtroisiemebateau[taille][taille]);
    int veriftabgagne(char tab[taille][taille]);
    int veriftperdu(char tab[taille][taille]);
    int verifOrdi(char tab[taille][taille],int abscisse,int ordonnee);
    int comparerchaquebateau(char tab[taille][taille],char tab1[taille][taille],int taillebateau);
    int ordi2(char tab[taille][taille]);
    int verifreponse(char tab[taille][taille],char casee[2]);
    int comparetab(char tab[taille][taille], char tab2[taille][taille], int poschar,int posint);
    int distance(char tab[taille][taille], int poschar, int posint, int taillebateau);
    int verifdisp(char*** bateau,int taillebateau,int poschar,int posint);
    int destructBateau(char tab[taille][taille],char ***bateau,int poschar,int posint,int taillebateau,int k,int i);
    int batum();
//Boss
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
    JoueurJeu constructJoueurJeu(int combat) ;
    monstre1 constructmonstre(int combat) ;
    void phrasesalea();
    void introboss() ;
    void reglesB(monstre1 c,JoueurJeu b,int a) ;
    void fin() ;
    int combat(monstre1 a, JoueurJeu b,int boss1) ;
    int bossf(Joueur *joueur) ;







