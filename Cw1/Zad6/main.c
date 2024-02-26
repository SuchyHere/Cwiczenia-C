#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
const int MAX_ROUNDS = 150;
const char* moves[] = {"kamien", "papier", "nozyce"};

//przechowanie wynikow
typedef struct {
    int playerMove;
    int computerMove;
    int result; // 0 = remis; 1 = wygrana, 2 = przegrana
} GameRound;

GameRound rounds[MAX_ROUNDS];
int roundCount = 0;

// wypisywanie wczesniejszych wynikow
void printScores() {
    printf("wyniki:\n");
    for (int i = 0; i < roundCount; i++) {
        printf("Runda %d: twoj ruch: %s, ruch komputera: %s, wynik: ", i + 1,
               moves[rounds[i].playerMove], moves[rounds[i].computerMove]);
        if (rounds[i].result == 0) {
            printf("remis\n");
        } else if (rounds[i].result == 1) {
            printf("wygrana\n");
        } else {
            printf("przegrana\n");
        }
    }
}

int main() {
    srand(time(NULL));
    char command[10];

    while (1) {
        printf("wpisz 'play' by grac, 'scores' aby zobaczyc wyniki, 'exit' aby wylaczyc program: ");
        scanf("%s", command);
        //sprawdzanie czy ktora opcje wybral uzytkownik
        if (strcmp(command, "play") == 0) {
            int player, computer, result;

            printf("Wybierz ruch [0: kamien, 1: papier, 2: nozyce]: ");
            scanf("%d", &player);

            computer = rand() % 3;

            //sprawdzanie wyniku
            if (player == computer) {
                result = 0;
            } else if ((player == 0 && computer == 2) ||
                       (player == 1 && computer == 0) ||
                       (player == 2 && computer == 1)) {
                result = 1;
            } else {
                result = 2;
            }
            //zapisywanie wynikow do struktury wyzej
            rounds[roundCount].playerMove = player;
            rounds[roundCount].computerMove = computer;
            rounds[roundCount].result = result;
            roundCount++;

            printf("twoj ruch: %s, ruch komputera: %s, ", moves[player], moves[computer]);
            if (result == 0) {
                printf("remis\n");
            } else if (result == 1) {
                printf("wygrales\n");
            } else {
                printf("przegrales\n");
            }

        } else if (strcmp(command, "scores") == 0) {
            printScores();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("nieznana komenda\n");
        }
    }

    return 0;
}
