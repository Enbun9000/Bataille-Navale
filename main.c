#include <stdio.h>
#include <stdlib.h>


void space(int nbr){
    for(int i = 0; i<nbr; i++)
    printf(" ");
}

void menu() {
    printf("\n\n\n                                 === Bataille navale ===\n\n\n");

    space(30);
    printf("1. Jouer\n");
    space(30);
    printf("2. Login\n");
    space(30);
    printf("3. Scores\n");
    space(30);
    printf("4. Aide");
    space(30);
    printf("5. Quitter\n\n");
}

int main() {

    menu();

    system("Pause");
    return 0;

}