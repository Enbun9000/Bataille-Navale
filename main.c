#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


#pragma execution_character_set( "utf-8" )


int gridValues[10] [10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
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
    printf("      A  B  C  D  E  F  G  H  I  J \n");
    printf("   0  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[0][0], gridValues[0][1], gridValues[0][2], gridValues[0][3], gridValues[0][4], gridValues[0][5], gridValues[0][6], gridValues[0][7], gridValues[0][8], gridValues[0][9]);
    printf("   1  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[1][0], gridValues[1][1], gridValues[1][2], gridValues[1][3], gridValues[1][4], gridValues[1][5], gridValues[1][6], gridValues[1][7], gridValues[1][8], gridValues[1][9]);
    printf("   2  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[2][0], gridValues[2][1], gridValues[2][2], gridValues[2][3], gridValues[2][4], gridValues[2][5], gridValues[2][6], gridValues[2][7], gridValues[2][8], gridValues[2][9]);
    printf("   3  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[3][0], gridValues[3][1], gridValues[3][2], gridValues[3][3], gridValues[3][4], gridValues[3][5], gridValues[3][6], gridValues[3][7], gridValues[3][8], gridValues[3][9]);
    printf("   4  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[4][0], gridValues[4][1], gridValues[4][2], gridValues[4][3], gridValues[4][4], gridValues[4][5], gridValues[4][6], gridValues[4][7], gridValues[4][8], gridValues[4][9]);
    printf("   5  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[5][0], gridValues[5][1], gridValues[5][2], gridValues[5][3], gridValues[5][4], gridValues[5][5], gridValues[5][6], gridValues[5][7], gridValues[5][8], gridValues[5][9]);
    printf("   6  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[6][0], gridValues[6][1], gridValues[6][2], gridValues[6][3], gridValues[6][4], gridValues[6][5], gridValues[6][6], gridValues[6][7], gridValues[6][8], gridValues[6][9]);
    printf("   7  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[7][0], gridValues[7][1], gridValues[7][2], gridValues[7][3], gridValues[7][4], gridValues[7][5], gridValues[7][6], gridValues[7][7], gridValues[7][8], gridValues[7][9]);
    printf("   8  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[8][0], gridValues[8][1], gridValues[8][2], gridValues[8][3], gridValues[8][4], gridValues[8][5], gridValues[8][6], gridValues[8][7], gridValues[8][8], gridValues[8][9]);
    printf("   9  [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", gridValues[9][0], gridValues[9][1], gridValues[9][2], gridValues[9][3], gridValues[9][4], gridValues[9][5], gridValues[9][6], gridValues[9][7], gridValues[9][8], gridValues[9][9]);
}


void jeu() {
    system("cls");
    title();
    printf("\n\n\n");
    grid();
    system("\n\nPause");
}
/*
int getInput() {
    int choix;
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}
*/
int main() {



    SetConsoleOutputCP(65001);

    menu();

    int choix;
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);


    switch(choix) {
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