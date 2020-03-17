#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#pragma execution_character_set( "utf-8" )

char frontGrid[10][10] =
        {
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        };

char gridValues[10][10] =
        {
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'X', 'X', 'X', ' ', 'X', 'X', 'X', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', ' ', ' '},
                          {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', 'X', ' ', ' ', 'X', 'X', ' ', ' ', ' ', ' '},
                          {' ', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
        };

int choix;
char colonsInChar;
int colonsInNumber;
int lines;
boolean program = 1;
int counter = 0;


// TODO - Fix Choice  -----------X
// TODO - Better game interface ---------X
// TODO - Search about invisible characters for the boats ---------X
// TODO - fix the help page -------------X
// TODO - Win  ---------------
// TODO - error -------------X
// TODO - Commentaires

void title() {
    printf("\033[0;36m"); //pour avoir une couleur cyan
    printf("\n<----------------------->\n");
    printf("<=== Bataille navale ===>\n");
    printf("<----------------------->\n\n\n");
    printf("\033[0m"); //Pour remmetre la couleur par default
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
    printf("\033[0;36m"); //pour avoir une couleur cyan
    printf("1 Porte-avion (5 cases)\n"
           "1 Croiseur (4 cases)\n"
           "2 Contre-torpilleur (3 cases)\n"
           "1 torpilleur (2 cases)\n\n\n");
    printf("\033[0m"); //Pour remmetre la couleur par default
    printf("Lorsque vous touchez un navire, une croix apparaît à l'emplacement, cependant, si vous ratez\n"
                    "un cercle apparaîtra.\n");
    printf("Vous gagnez lorsque tous les navires sont coulés.\n\n");

    system("Pause");
}

void grid() {
    printf("       A   B   C   D   E   F   G   H   I   J      \n");
    printf("   0  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[0][0], frontGrid[0][1], frontGrid[0][2], frontGrid[0][3], frontGrid[0][4], frontGrid[0][5], frontGrid[0][6], frontGrid[0][7], frontGrid[0][8], frontGrid[0][9]);
    printf("   1  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[1][0], frontGrid[1][1], frontGrid[1][2], frontGrid[1][3], frontGrid[1][4], frontGrid[1][5], frontGrid[1][6], frontGrid[1][7], frontGrid[1][8], frontGrid[1][9]);
    printf("   2  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[2][0], frontGrid[2][1], frontGrid[2][2], frontGrid[2][3], frontGrid[2][4], frontGrid[2][5], frontGrid[2][6], frontGrid[2][7], frontGrid[2][8], frontGrid[2][9]);
    printf("   3  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[3][0], frontGrid[3][1], frontGrid[3][2], frontGrid[3][3], frontGrid[3][4], frontGrid[3][5], frontGrid[3][6], frontGrid[3][7], frontGrid[3][8], frontGrid[3][9]);
    printf("   4  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[4][0], frontGrid[4][1], frontGrid[4][2], frontGrid[4][3], frontGrid[4][4], frontGrid[4][5], frontGrid[4][6], frontGrid[4][7], frontGrid[4][8], frontGrid[4][9]);
    printf("   5  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[5][0], frontGrid[5][1], frontGrid[5][2], frontGrid[5][3], frontGrid[5][4], frontGrid[5][5], frontGrid[5][6], frontGrid[5][7], frontGrid[5][8], frontGrid[5][9]);
    printf("   6  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[6][0], frontGrid[6][1], frontGrid[6][2], frontGrid[6][3], frontGrid[6][4], frontGrid[6][5], frontGrid[6][6], frontGrid[6][7], frontGrid[6][8], frontGrid[6][9]);
    printf("   7  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[7][0], frontGrid[7][1], frontGrid[7][2], frontGrid[7][3], frontGrid[7][4], frontGrid[7][5], frontGrid[7][6], frontGrid[7][7], frontGrid[7][8], frontGrid[7][9]);
    printf("   8  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[8][0], frontGrid[8][1], frontGrid[8][2], frontGrid[8][3], frontGrid[8][4], frontGrid[8][5], frontGrid[8][6], frontGrid[8][7], frontGrid[8][8], frontGrid[8][9]);
    printf("   9  [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c] [%c]     \n", frontGrid[9][0], frontGrid[9][1], frontGrid[9][2], frontGrid[9][3], frontGrid[9][4], frontGrid[9][5], frontGrid[9][6], frontGrid[9][7], frontGrid[9][8], frontGrid[9][9]);
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

void game() {
    while (program == 1) {
        system("cls");
        title();
        printf("\n\n\n");
        printf("O = raté\nX = touché\n\n");
        grid();
        printf("\n\n\n");

        printf("Colonne : ");
        fflush(stdin);
        scanf("%c", &colonsInChar);

        printf("Ligne : ");
        fflush(stdin);
        scanf("%d", &lines);

        LetterToNumber();


        if (isspace(gridValues[lines][colonsInNumber])) {
            frontGrid[lines][colonsInNumber] = 'O';
            gridValues[lines][colonsInNumber] = 'O';
        }
        else if(gridValues[lines][colonsInNumber] == 'X') {
            frontGrid[lines][colonsInNumber] = 'X';
        }
        else if(gridValues[lines][colonsInNumber] == 'O') {
            frontGrid[lines][colonsInNumber] = 'O';
        }


        for (int y = 0; y <= 9; y++) {
            for (int x = 0; x <= 9; x++) {
               if(gridValues[y][x] == frontGrid[y][x]) {
                    counter++;
               }
            }
        }
        if(counter == 100){
            printf("Félicitation, tu as gagné\n");
            program = 0;
            system("Pause");
        }
        else {
            program = 1;
        }
    }
}

int choice() {
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}

int main() {
    while (program == 1) {
        system("cls");
        SetConsoleOutputCP(65001);


        menu();

        choice();

        switch (choix) {
            case 1:
                game();
                break;
            case 2:
                help();
                break;
            case 3:
                printf("\nÀ bientôt !\n");
                system("Pause");
                program = 0;
                break;
            default:
                break;
            }
    }


    return 0;

}