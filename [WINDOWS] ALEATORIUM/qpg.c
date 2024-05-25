#ifdef __linux__
    #include "Aleatorium.h"
#endif
void affregle(){
    printf("\n+--------------- \033[4m\033[1;31mBienvenue dans Question Pour un Golem !\033[0m --------------+\n");
    printf("\nVoici les règles : \n - Il faut répondre correctement à \033[1;33m4 questions\033[0m sur %d pour gagner\n", QUESTION);
    printf(" - Chaque questions comportera plusieurs réponses possibles,\nseulement une est correct\n");
    printf(" - Certaines questions nécessitent \033[4m\033[1;31md'entrer le numéro de la réponse\033[0m afin \nd'éviter au joueur d'entrer la réponse complète\n");
    printf("+---------------------------------------------------------------------+\n\n"); 
}
#ifdef _WIN32
    typedef struct {
        char question[200];
        char reponse[A];
        
    }Questions;
#endif

/*Liste questions*/
    Questions questions1[QUESTION]={ //tableau de structure avec les questions et la réponse
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"En quelle année l'Equipe de France a gagné la coupe du monde ?\n2020 / 2022 / 1990 / 2018","2018"},
        {"Qui a écrit les Misérables ?\n1) Victor Hugo 2) Alexandre Dumas 3) Romuald Grignon 4) Masashi Kishimoto","1"},
        {"Combien de lettres il y a dans le mot : Lettre ?","6"},
        {"Qui fut le quarantième président des USA ?\n1) Obama 2) Reagan 3) Kennedy 4) Washington","2"},
        {"Au golf, quel club utilise-t-on sur le green ?\n1) un driver 2) un bois 3) un putter 4) un fer","3"},
        {"Combien il y a de chiffres dans le nombre 54 ?\n54 / 3 / 5 / 2","2"},
        {"Dans Star Wars, qui est le grand méchant ?\n1) Pikachu 2) Dark Vador 3) Astérix 4) Thanos","2"},
    };
    Questions questions2[QUESTION]={ //tableau de structure avec les questions et la réponse
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Dans quel pays se sont déroulés les Jeux Olympiques 2022 ?\n1) Japon 2) France 3) Chine 4) Corée du Sud","3"},
        {"Quelle est la planète la plus proche du soleil ?\n1) Mercure 2) Uranus 3) Venus 4) Jupiter","1"},
        {"Quelle est la plus grande planète du système solaire ?\n1) Mercure 2) Uranus 3) Venus 4) Jupiter","4"},
        {"Quel est le plus grand mammifère marin ?\n1) Esturgeon 2) La baleine bleue 3) Le poisson d'avril 4) Le Requin-baleine","1"},
        {"Quel est le symbole chimique de l'eau ?\n1) HO2 2) EAU 3) 2H0 4) H20","4"},
        {"En quelle année a eu lieu la Révolution française ?\n1789 / 1678 / 1879 / 1666","1789"},
        {"Combien de joueurs y a-t-il dans une équipe de football ?\n10 / 11 / 12 / 9.5","11"},
    };
    Questions questions3[QUESTION]={
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Quelle est la capitale de la France ?\n1) Rome 2) Madrid 3) Berlin 4) Paris", "4"},
        {"Quelle est la formule chimique du dioxyde de carbone ?\n1) CO 2) CO2 3) O2 4) H2O", "2"},
        {"Quel est le plus grand désert du monde ?\n1) Sahara 2) Gobi 3) Kalahari 4) Antarctique", "1"},
        {"Combien de continents y a-t-il sur Terre ?\n 5 / 6 / 7 / 8", "7"},
        {"Qui a écrit 'Roméo et Juliette' ?\n1) Molière 2) Victor Hugo 3) William Shakespeare 4) Homère", "3"},
        {"Quelle est la langue la plus parlée dans le monde ?\n1) Anglais 2) Espagnol 3) Chinois 4) Hindi", "3"},
        {"Quelle est la vitesse de la lumière ?\n1) 300 000 km/s 2) 150 000 km/s 3) 100 000 km/s 4) 50 000 km/s", "1"},
    };
    Questions questions4[QUESTION]={
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Quelle est la capitale de l'Espagne ?\n1) Lisbonne 2) Rome 3) Madrid 4) Paris", "3"},
        {"Qui a peint la Joconde ?\n1) Michel-Ange 2) Léonard de Vinci 3) Pablo Picasso 4) Vincent van Gogh", "2"},
        {"Quelle est la racine carrée de 144 ?\n1) 10 / 12 / 14 / 16", "12"},
        {"Quelle est la couleur du cheval blanc de Napoléon ?\n1) Blanc 2) Noir 3) Gris 4) Marron", "1"},
        {"Quel est le plus haut sommet du monde ?\n1) Mont Blanc 2) Mont Everest 3) Kilimandjaro 4) K2", "2"},
        {"Quelle est la capitale du Canada ?\n1) Toronto 2) Montréal 3) Ottawa 4) Vancouver", "3"},
        {"Quelle est la capitale de l'Australie ?\n1) Sydney 2) Canberra 3) Melbourne 4) Brisbane", "2"},
        };
    Questions questions5[QUESTION]={
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Quelle est la plus grande île du monde ?\n1) Madagascar 2) Groenland 3) Nouvelle-Guinée 4) Bornéo", "2"},
        {"Qui a écrit 'Le Petit Prince' ?\n1) J.K. Rowling 2) Antoine de Saint-Exupéry 3) J.R.R. Tolkien 4) Roald Dahl", "2"},
        {"Combien de côtés a un hexagone ?\n 4 / 5 / 6 / 7", "6"},
        {"Quelle est la capitale du Japon ?\n1) Osaka 2) Kyoto 3) Tokyo 4) Hiroshima", "3"},
        {"Quel est le symbole chimique du fer ?\n1) Fe 2) Fi 3) Fr 4) Fl", "1"},
        {"Qui a découvert l'Amérique ?\n1) Christophe Colomb 2) Vasco de Gama 3) Marco Polo 4) Amerigo Vespucci", "1"},
        {"Quelle est la plus grande cascade du monde ?\n1) Chutes Victoria 2) Chutes du Niagara 3) Chutes d'Iguaçu 4) Chutes du Rhin", "1"},
    };
    Questions questions6[QUESTION]={
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Quel est le plus long fleuve du monde ?\n1) Nil 2) Amazone 3) Yangtsé 4) Mississippi", "2"},
        {"Quel est le symbole chimique de l'oxygène ?\n1) O 2) Ox 3) Og 4) Oz", "1"},
        {"Qui a peint la Cène ?\n1) Léonard de Vinci 2) Michel-Ange 3) Raphaël 4) Botticelli", "1"},
        {"Quel est le plus grand animal terrestre ?\n1) Éléphant 2) Girafe 3) Hippopotame 4) Rhinocéros", "1"},
        {"Quel est le principal constituant de l'air ?\n1) Azote 2) Oxygène 3) Dioxyde de carbone 4) Argon", "1"},
        {"Quel est le plus grand océan du monde ?\n1) Atlantique 2) Indien 3) Arctique 4) Pacifique", "4"},
        {"Quelle est la capitale de l'Italie ?\n1) Milan 2) Rome 3) Florence 4) Naples", "2"},
    };
    Questions questions7[QUESTION]={
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Quelle est la plus haute montagne d'Afrique ?\n1) Kilimandjaro 2) Mont Kenya 3) Mont Cameroun 4) Mont Nimba", "1"},
        {"Quelle est la planète la plus éloignée du Soleil dans le système solaire ?\n1) Neptune 2) Pluton 3) Uranus 4) Saturne", "1"},
        {"Combien de jours y a-t-il dans une année bissextile ?\n 365 / 366 / 364 / 367", "366"},
        {"Quelle est la monnaie du Royaume-Uni ?\n1) Euro 2) Livre sterling 3) Dollar 4) Franc", "2"},
        {"Quel est le plus grand désert du monde ?\n1) Sahara 2) Gobi 3) Arctique 4) Antarctique", "1"},
        {"Quelle est la plus longue rivière du monde ?\n1) Nil 2) Amazone 3) Mississippi 4) Yangtsé", "1"},
        {"Qui est le premier homme à avoir marché sur la lune ?\n1) Neil Armstrong 2) Buzz Aldrin 3) Alan Shepard 4) Yuri Gagarin", "1"},
    };
    Questions questions8[QUESTION]={
        {"Quel sera notre note pour le projet d'info ?\n 20 / 20 / 20 / 20", "20"},
        {"Quel est le président actuel des États-Unis ?\n1) Donald Trump 2) Joe Biden 3) Barack Obama 4) George W. Bush", "2"},
        {"Quel est le symbole chimique de l'or ?\n1) Au 2) Ag 3) Fe 4) Cu", "1"},
        {"Qui a écrit 'Les Trois Mousquetaires' ?\n1) Victor Hugo 2) Alexandre Dumas 3) Gustave Flaubert 4) Emile Zola", "2"},
        {"Quelle est la première lettre de l'alphabet grec ?\n1) Alpha 2) Bêta 3) Gamma 4) Delta", "1"},
        {"Combien de planètes y a-t-il dans notre système solaire ?\n 7 / 8 / 9 / 10", "8"},
        {"Quel est le plus grand pays du monde en superficie ?\n1) Russie 2) Canada 3) Chine 4) États-Unis", "1"},
        {"Qui a peint 'Les Tournesols' ?\n1) Vincent van Gogh 2) Claude Monet 3) Pablo Picasso 4) Henri Matisse", "1"},
    };

void poserQuestion(Questions *list, int numQuestion){ // Fonction pour poser une question
    printf("\033[1;33mQuestion %d :\033[0m \033[1;37m%s\033[0m\n\n", numQuestion + 1, list[numQuestion].question);
}

int verifierReponse(Questions *list, int numeroQuestion, char* reponse){
    if (strcmp(list[numeroQuestion].reponse, reponse) == 0) {
        printf("Bonne réponse !\n\n");
        return 1;
    } else {
        printf("Mauvaise réponse.\n\n");
        return 0;
    }
}

int questiongolem(){
    srand(time(NULL));
    effacer();
    char reponse[A];                //tableau pour stocker les réponses
    int score=0, j=0;
    // Créer un tableau de pointeurs vers les listes de questions
    Questions *lists[NBQUESTION] = {questions1, questions2,questions3,questions4,questions5,questions6, questions7,questions8};
    // Sélectionner aléatoirement une liste de questions
    Questions *selectedQuestions = lists[rand() % NBQUESTION];
    for (int i = 0; i < QUESTION; ++i) {  //Boucle pour poser les 8 questions
        effacer();
        affregle();
        poserQuestion(selectedQuestions, i);
        printf("Votre réponse : ");
        scanf("%20s", reponse);
        score += verifierReponse(selectedQuestions, i, reponse);
        continuer();
    }
 
    if (score > 3){
        printf("Vous êtes trop intelligent pour être un simple Golem, c'est gagné ! score : %d/8\n", score);
        continuer();
        return 1;   //victoire
    } else {
        printf("Vous êtes le golem que vous pensez être, c'est perdu. score : %d/8\n", score);
        continuer();
        return 0;    //defaite
    }
}