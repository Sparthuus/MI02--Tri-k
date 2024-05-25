
    
#ifdef _WIN32
    /*Définir Logiciel*/
        #include <conio.h>
    /*Bibliothèque*/
        /*Universel*/
            #include <stdio.h>
            #include <stdlib.h>
            #include <time.h>
            #include <unistd.h> 
            #include <string.h>
            #include <errno.h>
            #include <termios.h> //tcflush(STDIN_FILENO, TCIFLUSH);
        /*Nos Bibliothèques*/
            #include "variables.c"
            #include "outils.c"
            #include "param.c"
            #include "creationmap.c"
            #include "boss.c"
            #include "minijeux.c"
            #include "deplacement.c"
            #include "detecterdeplacement.c"
            #include "intro.c"
            #include "Jeu.c"
            #include "menu.c"
#endif
#ifdef __linux__
    #include "Aleatorium.h"
#endif
//https://patorjk.com/software/taag/#p=display&f=Chiseled&t=PARAMETRE
//Font Name: tmplr // Calvin S
// Delta Corps Priest 1



void main(){    
    effacer();
    menu();
}