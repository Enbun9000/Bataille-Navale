#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#pragma execution_character_set( "utf-8" )

char gridValues[10][10] =
        {
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'x', 'x', 'x', ' ', 'x', 'x', 'x', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', 'x', 'x', 'x', 'x', ' ', ' '},
                          {' ', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'x', ' ', ' ', 'x', 'x', ' ', ' ', ' ', ' '},
                          {' ', 'x', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        };

int choix;
char colone[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int number[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
char colonsInChar;
int colonsInNumber;
int lines;


// TODO - Fix Choice  -----------X
// TODO - Do a better game interface ---------
// TODO - Search about invisible characters for the boats ---------
// TODO - fix the help page

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
    printf("       A   B   C   D   E   F   G   H   I   J       \n");
    printf("   0  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]      \n" );
    printf("   1  [ ] [%c] [%c] [%c] [ ] [%c] [%c] [%c] [ ] [ ]\n", gridValues[1][1], gridValues[1][2], gridValues[1][3], gridValues[1][5], gridValues[1][6], gridValues[1][7]);
    printf("   2  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]      \n" );
    printf("   3  [ ] [ ] [ ] [ ] [%c] [%c] [%c] [%c] [ ] [ ]  \n", gridValues[3][4], gridValues[3][5], gridValues[3][6], gridValues[3][7]);
    printf("   4  [ ] [%c] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[4][1]);
    printf("   5  [ ] [%c] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[5][1]);
    printf("   6  [ ] [%c] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[6][1]);
    printf("   7  [ ] [%c] [ ] [ ] [%c] [%c] [ ] [ ] [ ] [ ]   \n", gridValues[7][1], gridValues[7][4], gridValues[7][5]);
    printf("   8  [ ] [%c] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]     \n", gridValues[8][1]);
    printf("   9  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]      \n");
}

char abdc() {

}

int LetterToNumber() {
    if(colonsInChar == 'A' || colonsInChar == 'a') {
        colonsInNumber = 0;
    }
    else if(colonsInChar == 'B' || colonsInChar == 'b') {
        colonsInNumber = 1;
    }
    else if(colonsInChar == 'C' || colonsInChar == 'c') {
        colonsInNumber = 2;
    }
    else if(colonsInChar == 'D' || colonsInChar == 'd') {
        colonsInNumber = 3;
    }
    else if(colonsInChar == 'E' || colonsInChar == 'e') {
        colonsInNumber = 4;
    }
    else if(colonsInChar == 'F' || colonsInChar == 'f') {
        colonsInNumber = 5;
    }
    else if(colonsInChar == 'G' || colonsInChar == 'g') {
        colonsInNumber = 6;
    }
    else if(colonsInChar == 'H' || colonsInChar == 'h') {
        colonsInNumber = 7;
    }
    else if(colonsInChar == 'I' || colonsInChar == 'i') {
        colonsInNumber = 8;
    }
    else if(colonsInChar == 'J' || colonsInChar == 'j') {
        colonsInNumber = 9;
    }

    return colonsInNumber;
}

void jeu() {


    system("cls");
    title();
    printf("\n\n\n");
    printf("O = raté\nX = touché\n\n");
    grid();
    printf("\n\n\n");

    printf("Lettre de la colonne : ");
    fflush(stdin);
    scanf("%c", &colonsInChar);

    printf("Chiffre de la ligne : ");
    fflush(stdin);
    scanf("%d", &lines);

    LetterToNumber();

    system("\n\nPause");
/*
    for(int y = 0; y <9; y++) {
        for(int x = 0; x < 9; x++) {
            if(isspace(gridValues[y][x])) {
                printf("Raté !");
            } else {
                printf("Touché");
            }
        }
    }
*/
}



int choice() {
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}

int main() {


    SetConsoleOutputCP(65001);

    menu();

    choice();

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