/**
 * Project : Bataille navale
 * Author: Benjamin Muminovic
 * Version : 0.5
 * Description :
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>

#pragma execution_character_set( "utf-8" )


// La grille qui est affiché sur la page du jeu
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
// La grille cachée contenant les position des bateaux
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

// réserve à variable
char colonsInChar;
int colonsInNumber;
int choix;
int lines;
boolean program = 1;
char logname = ' ';


//Fonction affichant le titre, presente a chaque debut de page
void title() {
    printf("\033[0;36m"); //pour avoir une couleur cyan
    printf("\n<----------------------->\n");
    printf("<=== Bataille navale ===>\n");
    printf("<----------------------->\n\n\n");
    printf("\033[0m"); //Pour remmetre la couleur par default
}
//Cette fonction recupere les score a la fin d'une partie et les ecrit dans le fichier score
void scores(int valeurScore) {
    FILE * write_file = fopen("scores.txt", "r+");
    fprintf(write_file, "%s : %d pts\n", &logname, valeurScore);
    fclose(write_file);
}

void menu() {
    title();
    // affiche le nom de l'utilisateur (en couleur verte) si il est authentifié
    if(logname != ' ') {
        printf("Vous êtes authentifié en tant que ");
        printf("\033[0;32m");
        printf("%s\n\n", &logname);
        printf("\033[0m");
    }
    else {  // Sinon affiche ce message
        printf("Vous n'êtes pas authentifié\n\n");
    }

    printf("1. Jouer\n\n");
    printf("2. Authentification\n\n");
    printf("3. Scores\n\n");
    printf("4. Aide\n\n");
    printf("5. Quitter\n\n");
}
//La fonction affichant la page d'aide du jeu
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
// Fonction contenant une grande série de printf() pour afficher la grille
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

// Cette fonction convertit les lettres des colonnes et les transforme en chiffres pour qu'ils puissent être manipulés
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

// Page d'authentification
void login() {
    system("cls");

    title();
    printf("Voici la page d'authentification, \n");

    printf("Veuillez entrer votre nom ici :");
    // L'entrée de l'utilisateur est affichée en couleur
    printf("\033[0;32m");
    scanf("%s", &logname);
    printf("\033[0m");
}
// Fonction dans laquelle se déroule toute la phase de jeu
void game() {

    int score = 0;
    int counter = 0;
    boolean GameProgram = 1;

    while (GameProgram == 1) {
        system("cls");
        title();
        printf("\n\n\n");
        printf("O = raté\nX = touché\n\n");
        grid();
        printf("\n\n\n");
        // Pour récupérer les entrées de l'utilisateur
        printf("Colonne : ");
        fflush(stdin);
        scanf("%c", &colonsInChar);

        printf("Ligne : ");
        fflush(stdin);
        scanf("%d", &lines);

        LetterToNumber();

        if(lines <= 9 && lines >= 0) {   // condition pour eviter que le programme plante lorsque l'on rentre une valeur supérieure à 9
            if (isspace(gridValues[lines][colonsInNumber])) {
                frontGrid[lines][colonsInNumber] = 'O';
                gridValues[lines][colonsInNumber] = 'O';
                score = score - 20;
            } else if (gridValues[lines][colonsInNumber] == 'X') {
                if(frontGrid[lines][colonsInNumber] != 'X') {
                    counter++;
                    score = score + 150;
                }
                frontGrid[lines][colonsInNumber] = 'X';
            } else if (gridValues[lines][colonsInNumber] == 'O') {
                frontGrid[lines][colonsInNumber] = 'O';
            }
        }

        if(counter == 17){  // si toutes les cases contenant un bout de bateau on été trouvées
            printf("\nFélicitation, tu as gagné\n");
            system("Pause");
            scores(score);
            GameProgram = 0;
            // Affiche la page d'authentification si le joueur n'est pas déjà authentifié
            if(logname == ' ') {
                login();
            }
        }
    }
}
// Fonction affichant la page des scores
void scorePage() {
    system("cls");
    title();

    FILE * read_file = fopen("scores.txt", "r");  // on ouvre le fichier "score.txt" en mode lecture

    printf("Voici la page où sont affichés les scores.\n\n");
    printf("SCORES : \n\n");
    //Cette partie lit chaque ligne de scores.txt et affiche ces lignes dans la page
    char buf[150];
    while(!feof(read_file)) {
        fgets(buf, 150, read_file);
        puts(buf);
    }

    fclose(read_file);

    system("\n\nPause");

}
// Fonction donnant la valeur de la variable "choix"
int choice() {
    printf("Choix : ");
    fflush(stdin);
    scanf("%d", &choix);
    return choix;
}


int main() {
    SetConsoleOutputCP(65001);
    do {
        system("cls");

        menu();

        choice();

        switch (choix) {
            case 1:
                game();
                break;
            case 2:
                login();
                break;
            case 3:
                scorePage();
                break;
            case 4:
                help();
                break;
            case 5:
                printf("\nÀ bientôt !\n\n");
                system("Pause");
                program = 0;
                break;
            default:
                break;
        }
    // Permet de revenir au menu principal apres l'affichage de chaque page et
    }while(program != 0);

    return 0;

}