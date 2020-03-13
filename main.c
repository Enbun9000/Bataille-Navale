#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#pragma execution_character_set( "utf-8" )


int gridValues[10] [10] =
        {
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 1, 1, 1, 1, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
                          {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };


void title() {
    printf("\n\n\n<----------------------->\n");
    printf("<=== Bataille navale ===>\n");
    printf("<----------------------->\n\n\n");
}

void menu() {
    title();

    printf("1. Jouer\n\n");
    printf("2. Aide\n\n");
    printf("3. Quitter\n\n\n");
}

void help() {
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
    printf("       A   B   C   D   E   F   G   H   I   J                 \n");
    printf("   0  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]      \n" );
    printf("   1  [ ] [%d] [%d] [%d] [ ] [%d] [%d] [%d] [ ] [ ]\n", gridValues[1][1], gridValues[1][2], gridValues[1][3], gridValues[1][5], gridValues[1][6], gridValues[1][7]);
    printf("   2  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]      \n" );
    printf("   3  [ ] [ ] [ ] [ ] [%d] [%d] [%d] [%d] [ ] [ ]  \n", gridValues[3][4], gridValues[3][5], gridValues[3][6], gridValues[3][7]);
    printf("   4  [ ] [%d] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[4][1]);
    printf("   5  [ ] [%d] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[5][1]);
    printf("   6  [ ] [%d] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[6][1]);
    printf("   7  [ ] [%d] [ ] [ ] [%d] [%d] [ ] [ ] [ ] [ ]   \n", gridValues[7][1], gridValues[7][4], gridValues[7][5]);
    printf("   8  [ ] [%d] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[8][1]);
    printf("   9  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]      \n");
}

void jeu() {
    system("cls");
    title();
    printf("\n\n\n");
    grid();
    system("\n\nPause");
}


int choice(choix) {
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}

int main() {

    SetConsoleOutputCP(65001);

    menu();

    choice();
/*
    int choix;
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
*/

    switch() {
        case 1:
            jeu();
            break;
        case 2:
            help();
            break;
        default:
            printf("Veuillez entrer un choix valide.\n");
        }


    return 0;
}