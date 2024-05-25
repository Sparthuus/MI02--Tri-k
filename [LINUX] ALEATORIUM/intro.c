#ifdef __linux__
    #include "Aleatorium.h"
#endif
void intro(Joueur *joueur){
    /*Verifier pointeurs joueur*/
        verifierJoueur(joueur);
    effacer(); 
    int choix1=0;
    int choix2=0;
    int graine=0;
    /*Rentrer pseudo joueur*/
        printf("\033[1;37m╔═╗ ╦   ╔═╗ ╔═╗ ╔╦╗ ╔═╗ ╦═╗ ╦ ╦ ╦ ╔╦╗\n");
        printf("╠═╣ ║   ║╣  ╠═╣  ║  ║ ║ ╠╦╝ ║ ║ ║ ║║║\n");
        printf("╩ ╩ ╩═╝ ╚═╝ ╩ ╩  ╩  ╚═╝ ╩╚═ ╩ ╚═╝ ╩ ╩\033[0m\n");
        printf("\n=====================================\n");  
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez rentrer \033[4mvotre nom\033[0m avant de pouvoir entrer : \033[1;30m (10 char)\033[0m\n-->");
        verifchar(joueur->nom, 10);
    /*Choisir un skin*/
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez choisir \033[4mvotre skin\033[0m avant de pouvoir commencer :\n");
        printf("\033[1;37m1-[🤠] 2-[😭] 3-[😎] 4-[😷] 5-[😁] 6-[😨] 7-[🤡]\033[0m  --> ");
        (joueur->skin)=verifscan(1,7);        
    //faire le choix
        effacer();
        printf("\033[1;37m╔═╗ ╦   ╔═╗ ╔═╗ ╔╦╗ ╔═╗ ╦═╗ ╦ ╦ ╦ ╔╦╗\n");
        printf("╠═╣ ║   ║╣  ╠═╣  ║  ║ ║ ╠╦╝ ║ ║ ║ ║║║\n");
        printf("╩ ╩ ╩═╝ ╚═╝ ╩ ╩  ╩  ╚═╝ ╩╚═ ╩ ╚═╝ ╩ ╩\033[0m\n");
        printf("\n=====================================\n");
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez rentrer \033[4mvotre nom\033[0m avant de pouvoir entrer : \033[1;30m (10 char)\033[0m\n-->");
        printf("%s\n", &joueur->nom);
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez choisir \033[4mvotre skin\033[0m avant de pouvoir commencer :\n");
        printf("\033[1;37m1-[🤠] 2-[😭] 3-[😎] 4-[😷] 5-[😁] 6-[😨] 7-[🤡]\033[0m  --> ");
        printf("%d\n", joueur->skin);
        printf("\033[1;31m[🧐 BOB]\033[0m : Oh! c'est toi \033[0;34m%s\033[0m,\nça fait déjà 15 fois que tu es venu cette semaine !\n",joueur->nom);
        sleep(2);
        printf("----------[Faites un choix]-------------\n",joueur->nom);
        printf("\033[0;32m1 -\033[0m Oui, tu sais très bien que j'ai pour objectif de devenir le plus riche !\n",joueur->nom);
        printf("\033[0;32m2 -\033[0m Oui, je ne peux pas m'arrêter de venir à \033[1;37ml'Aléatorium\033[0m.",joueur->nom);
        tcflush(STDIN_FILENO, TCIFLUSH);
        choix1=verifscan(1,2);
    //Afficher le choix 1
        effacer();
        printf("\033[1;37m╔═╗ ╦   ╔═╗ ╔═╗ ╔╦╗ ╔═╗ ╦═╗ ╦ ╦ ╦ ╔╦╗\n");
        printf("╠═╣ ║   ║╣  ╠═╣  ║  ║ ║ ╠╦╝ ║ ║ ║ ║║║\n");
        printf("╩ ╩ ╩═╝ ╚═╝ ╩ ╩  ╩  ╚═╝ ╩╚═ ╩ ╚═╝ ╩ ╩\033[0m\n");
        printf("\n=====================================\n");
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez rentrer \033[4mvotre nom\033[0m avant de pouvoir entrer : \033[1;30m (10 char)\033[0m\n-->");
        printf("%s\n", &joueur->nom);
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez choisir \033[4mvotre skin\033[0m avant de pouvoir commencer :\n");
        printf("\033[1;37m1-[🤠] 2-[😭] 3-[😎] 4-[😷] 5-[😁] 6-[😨] 7-[🤡]\033[0m  --> ");
        printf("%d\n", joueur->skin);
        printf("\033[1;31m[🧐 BOB]\033[0m : Oh! c'est toi \033[0;34m%s\033[0m,\nça fait déjà 15 fois que tu es venu cette semaine !\n",joueur->nom);
        if(choix1==1){
            printf("\033[0;34m[%s]\033[0m : Oui, tu sais très bien que j'ai pour objectif de devenir le plus riche !\n",joueur->nom);
        }
        else{
            printf("\033[0;34m[%s]\033[0m : Oui, je ne peux pas m'arrêter de venir à \033[1;37ml'Aléatorium\033[0m.\n",joueur->nom);
        }
    /*Regles du jeu*/
        sleep(2);
        printf("\033[1;31m[🧐 BOB]\033[0m : Veux-tu que je te réexplique comment fonctionne \033[1;37ml'Aléatorium\033[0m ?\n");
        sleep(2); 
    //faire le choix
        printf("----------[Faites un choix]-------------\n",joueur->nom);
        printf("\033[0;32m1 -\033[0m Oui, juste pour être sûr d'avoir bien compris !\n",joueur->nom);
        printf("\033[0;32m2 -\033[0m Non, je sais comment ça fonctionne !",joueur->nom);
        tcflush(STDIN_FILENO, TCIFLUSH);
        choix2=verifscan(1,2);
    //Afficher le choix 2
        effacer();
        printf("\033[1;37m╔═╗ ╦   ╔═╗ ╔═╗ ╔╦╗ ╔═╗ ╦═╗ ╦ ╦ ╦ ╔╦╗\n");
        printf("╠═╣ ║   ║╣  ╠═╣  ║  ║ ║ ╠╦╝ ║ ║ ║ ║║║\n");
        printf("╩ ╩ ╩═╝ ╚═╝ ╩ ╩  ╩  ╚═╝ ╩╚═ ╩ ╚═╝ ╩ ╩\033[0m\n");
        printf("\n=====================================\n");
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez rentrer \033[4mvotre nom\033[0m avant de pouvoir entrer : \033[1;30m (10 char)\033[0m\n-->");
        printf("%s\n", joueur->nom);
        printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez choisir \033[4mvotre skin\033[0m avant de pouvoir commencer :\n");
        printf("\033[1;37m1-[🤠] 2-[😭] 3-[😎] 4-[😷] 5-[😁] 6-[😨] 7-[🤡]\033[0m  --> ");
        printf("%d\n", joueur->skin);
        printf("\033[1;31m[🧐 BOB]\033[0m : Oh! c'est toi \033[0;34m%s\033[0m,\nça fait déjà 15 fois que tu es venu cette semaine !\n",joueur->nom);
        if(choix1==1){
            printf("\033[0;34m[%s]\033[0m : Oui, tu sais très bien que j'ai pour objectif de devenir le plus riche !\n",joueur->nom);
        }
        else{
            printf("\033[0;34m[%s]\033[0m : Oui, je ne peux pas m'arrêter de venir à \033[1;37ml'Aléatorium\033[0m.\n",joueur->nom);
        }
        printf("\033[1;31m[🧐 BOB]\033[0m : Veux-tu que je te réexplique comment fonctionne \033[1;37ml'Aléatorium\033[0m?\n");
        if(choix2==2){
            printf("\033[0;34m[%s]\033[0m : Non, je sais comment ça fonctionne !\n",joueur->nom);
            sleep(2);
        }
        else{
            printf("\033[0;34m[%s]\033[0m : Oui, juste pour être sûr d'avoir bien compris !\n",joueur->nom);
            sleep(2);
            printf("\033[1;31m[🧐 BOB]\033[0m : Très bien, si vous voulez devenir \033[1;33mriche\033[0m,\nvous devez \033[1;32mréussir\033[0m tous les mini-jeux de \033[1;37ml'Aléatorium\033[0m.\n");
            sleep(3);
            printf("\033[1;31m[🧐 BOB]\033[0m : Pour passer d'une salle à l'autre,\nvous devez \033[1;32mremporter\033[0m le mini-jeu de la salle actuelle. \n");
            sleep(3);
            printf("\033[1;31m[🧐 BOB]\033[0m : À chaque jeu, vous misez tout votre \033[1;33margent\033[0m;\nsi vous\033[1;32m gagnez\033[0m, vous verrez votre somme doublée.\n");
            sleep(3);
            printf("\033[1;31m[🧐 BOB]\033[0m : Mais \033[4mattention\033[0m, en cas de \033[1;31mdéfaite\033[0m, vous \033[1;31mperdez\033[0m tous vos gains !\nÀ partir d'un certain nombre de \033[1;31mdéfaites\033[0m, vous êtes \033[4mbanni à vie\033[0m de \033[1;37ml'Aléatorium\033[0m.\n");
            sleep(5);
            printf("\033[1;31m[🧐 BOB]\033[0m : Je vous rappelle que vous avez accès à\n\033[1;37ml'Aléatorium\033[0m pendant \033[4mseulement 2 heures\033[0m !\033[1;30m (20 minutes)\033[0m\n");
            sleep(3);
        }
        printf("\033[1;31m[🧐 BOB]\033[0m : Sur ce, je vous laisse, peut-être que vous allez réussir cette fois-ci !\n");   
        sleep(2);
        /*Demander la graine au joueur*/
            printf("\033[0;33m[Système Aléatorium]\033[0m : Veuillez rentrez un \033[4mcode d'accès\033[0m pour accéder à une salle de \033[1;37ml'Aléatorium\033[0m :");
            
            tcflush(STDIN_FILENO, TCIFLUSH);
            graine=verifscan(0,10000000);
            graine=(((graine+303)*303)+303*303)-303;
            joueur->graine=graine;
            

}