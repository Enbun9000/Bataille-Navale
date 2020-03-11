#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#pragma execution_character_set( "utf-8" )



void title() {
    printf("\n\n\n<----------------------->\n");
    printf("<=== Bataille navale ===>\n");
    printf("<----------------------->\n\n\n");
}

void menu() {
    title();

    printf("1. Jouer\n\n");
    printf("2. Login (Pas encore disponible)\n\n");
    printf("3. Scores (Pas encore disponible)\n\n");
    printf("4. Aide\n\n");
    printf("5. Quitter\n\n\n");
}

void aide() {
    system("cls");
    title();

    printf("Voici les règles du jeu:\n\n");

    printf("La bataille navale est un jeu où deux personnes s'affrontent en plaçant des\nnavires sur leurs"
           "grilles personnelles et tentent de couler les navires de l'autre \nen choisissant la cellule à attaquer.\n\n");

    printf("Il y a différents types de navires:\n\n");

    printf("1 Porte-avion (5 cases)\n"
           "1 Croiseur (4 cases)\n"
           "2 Contre-torpilleur (3 cases)\n"
           "1 torpilleur (2 cases)\n\n\n\n\n");

    printf("Vos navires sont représentés sous forme de cercles accrochés les uns aux autres.\n\n");
    printf("Si vous ratez une attaque, une croix sera placé dans la grille adverse à l'endroit visé.\n\n");
    printf("Si vous touchez un navire, un cercle sera placé à l'endroit de l'impact.\n\n\n\n");

    system("Pause");
}

void grid() {

    int grid = {(0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
                (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)};
}

void jeu() {
    title();
}

int getInput() {
    int choix;
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}

int main() {



    SetConsoleOutputCP(65001);

    menu();

   getInput();


    switch(choix) {
        case 1:
            break;
        case 2:
            system("cls");
            printf("Désolé, mais cette fonctionalité n'est pas encore disponible.\n\n");
            system("Pause");
            break;
        case 3:
            printf("Désolé, mais cette fonctionalité n'est pas encore disponible.\n\n");
            system("Pause");
            break;
        case 4:
            aide();
            break;
        default:
            printf("Veuillez entrer un choix valide.\n");
            menu();
            break;
        }



    //system("Pause");
    return 0;
}