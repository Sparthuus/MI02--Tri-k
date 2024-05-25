#ifdef __linux__
    #include "Aleatorium.h"
#endif
void regleRapidos(){
    printf("\n+==============================================================+\n");
    printf("                   \033[4m\033[1;31m[Bienvenue dans RAPIDOS]\033[0m\n\n"); 
    printf("Dans \033[0;31mrapidos\033[0m votre but est de \033[4mparier\033[0m sur \033[1;32mle plus\033[0m rapide!\n");
    printf("Vous avez le choix entre : \033[1;37mLe Cheval🐎\033[0m,\033[1;37mL'avion✈️  \033[0met \033[1;37mLe Velo🚴\033[0m\n");
    printf("Vous devez \033[1;32mgagner\033[0m une course pour obtenir la \033[1;33mclé\033[0m.\n");
    printf("\033[0;31m[!]\033[0mAttention,vous n'avez que 3 courses pour en remporter une !\n");
    printf("    \033[4m\033[1;37mPour avancer dans la course il faut appuyer sur Entrée !\033[0m");
    printf("\n+==============================================================+\n\n");
}
void affichercourse(int *avion, int*cheval, int*velo,int manche,int propal){
    /*Verification des pointeurs avions cheval velo*/
        if (cheval == NULL) {
                printf("Le pointeur cheval est NULL !\n");
                exit(EXIT_FAILURE);
            }
        if (velo == NULL) {
                printf("Le pointeur velo est NULL !\n");
                exit(EXIT_FAILURE);
            }
        if (avion == NULL) {
                printf("Le pointeur avion est NULL !\n");
                exit(EXIT_FAILURE);
            }
    if(propal==1){
        printf("                      \033[0;34m[Manche %d]\033[1;32m[Cheval]\033[0m\n\n",manche);
    }
    else if(propal==2){
        printf("                       \033[0;34m[Manche %d]\033[1;32m[Avion]\033[0m\n\n",manche);
    }
    else{
        printf("                        \033[0;34m[Manche %d]\033[1;32m[Velo]\033[0m\n\n",manche);
    }
    printf("                      ");
    for(int i=0;i<COURSE;i++){
        switch(cheval[i]) {
            case 0:
                printf("⬜"); //Murs
            break;
            case 1:
                printf("🐎");
            break;
            case 2:
                printf("🏁");
            break;
        }
    }
    printf("\n");
    printf("                      ");
    for(int i=0;i<COURSE;i++){
        switch(avion[i]) {
            case 0:
                printf("⬜"); //Murs
            break;
            case 1:
                printf("✈️ ");
            break;
            case 2:
                printf("🏁");
            break;
        }
    }
    printf("\n");
    printf("                      ");
    for(int i=0;i<COURSE;i++){
        switch(velo[i]) {
            case 0:
                printf("⬜"); //Murs
            break;
            case 1:
                printf("🚴");
            break;
            case 2:
                printf("🏁");
            break;
        }
    }
    printf("\n\n");
}
void avancerrapidos(int *tab){
    /*Verification des pointeurs tab*/
        if (tab == NULL) {
                printf("Le pointeur tab rapidos est NULL !\n");
                exit(EXIT_FAILURE);
            }
    int alea;
    alea=rand()%4;
    if(alea==3){
        for(int i=0;i<COURSE;i++){
            if(tab[i]==1){
                tab[i]=0;
                tab[i+1]=1;
                return;
            }
        }
    }
}
int verificationrapidos(int *tab){
    /*Verification des pointeurs tab*/
        if (tab == NULL) {
                printf("Le pointeur tab rapidos est NULL !\n");
                exit(EXIT_FAILURE);
            }
    for(int i=0;i<COURSE;i++){
        if(tab[i]==1){
            if(i==9){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
}
int jeurapidos(int manche){
    int course=1,tour=1;
    int victoire=0;
    int propal=0,gavion=1,gcheval=1,gvelo=1;
    int *avion=calloc(COURSE,sizeof(int*));
    int *cheval=calloc(COURSE,sizeof(int*));
    int *velo=calloc(COURSE,sizeof(int*));
    avion[0]=1;avion[9]=2;
    cheval[0]=1;cheval[9]=2;
    velo[0]=1;velo[9]=2;
    effacer();
    regleRapidos();
    printf("        Place aux paris ! Qui allez-vous choisir entre :\n\n");
    printf("                       \033[1;37m1 : Le Cheval🐎\033[0m\n\n");
    printf("                       \033[1;37m2 : L'avion✈️  \033[0m\n\n");
    printf("                       \033[1;37m3 : Le Velo🚴\033[0m\n");
    propal = verifscan(1,3);
    effacer();
    regleRapidos();
    affichercourse(avion,cheval,velo,manche,propal);
    do{
        printf("[Tour : %d]  ",tour);
        continuer();
        avancerrapidos(avion);
        avancerrapidos(cheval);
        avancerrapidos(velo);
        effacer();
        regleRapidos();
        affichercourse(avion,cheval,velo,manche,propal);
        gavion=verificationrapidos(avion);
        gvelo=verificationrapidos(velo);
        gcheval=verificationrapidos(cheval);
        tour++;
    }while(gavion&&gvelo&&gcheval);
            if(gcheval==0){
            if(propal==1){
                printf("\033[1;32mBravo à vous\033[0m \033[1;37mLe Cheval🐎 \033[0m\033[1;32ma gagné !\033[0m\n");
                victoire++;
            }
        }
    else if(gavion==0){
            if(propal==2){
                printf("\033[1;32mBravo à vous\033[0m \033[1;37mL'avion✈️  \033[0m\033[1;32ma gagné !\033[0m\n");
                victoire++;
            }
        }
    else if(gvelo==0){
            if(propal==3){
                printf("\033[1;32mBravo à vous\033[0m \033[1;37mLe Velo🚴 \033[0m\033[1;32ma gagné !\033[0m\n");
                victoire++;
            }
    }
    if(victoire==0){
        printf("\033[1;31mOh non vous avez perdu la course !\033[0m\n");
    }
    free(avion);    
    free(cheval);    
    free(velo);
    printf("\033[1;30mTapez sur \033[4mun nombre\033[0m\033[1;30m entre 0 et 9 pour continuer\033[0m\n");
    manche=verifscan(0,9);
    return victoire;
    
}
int rapidos(){
    
    int partie=0;
    int manche=1;
    do{
        partie=jeurapidos(manche);
        manche++;
    }while(manche!=4 && partie==0);
    if (partie==1){
        return 1;
    }
    else{
        return 0;
    }
    
}