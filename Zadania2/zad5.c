#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char number[10];
    char name[100];
    char surname[100];
} Contact;
void searchAll(Contact contacts[], int * size) {
    for (int i = 0; i < *size; i++) {
        printf("Kontakt %d: %s %s - %s\n", i + 1, contacts[i].name, contacts[i].surname, contacts[i].number);
    }
}
    void deleteSurname(Contact contacts[], int *size, const char *surname) {
        int a = 0;
        for (int i = 0; i < *size; i++) {
            if (strcmp(surname, contacts[i].surname) == 0) {
                a = 1;
                for (int j = i; j < *size; j++) {
                    contacts[j] = contacts[j + 1]; //przesuwa kontakty przed podanym, nadpisujac go
                }
                (*size)--;
            }

        }
        if (a == 0){
            printf("nie znaleziono takiego kontaktu");
        }
    }
//funkcja szukajaca kontakt po nazwisku
    void searchSurname(Contact contacts[], int *size, const char *surname) {
        int a = 0;
        for (int i = 0; i < *size; i++) {
            if (strcmp(surname, contacts[i].surname) == 0) {
                printf("Kontakt %d: %s %s - %s\n", i + 1, contacts[i].name, contacts[i].surname, contacts[i].number);
                a = 1;
            }
        }
        if (a == 0){
            printf("nie znaleziono takiego nazwiska\n");
        }
    }
//funkcja dodania kontaktu
    void addContact(Contact contacts[], int *size, const char *number, const char *name, const char *surname) {
        if (*size >= MAX_CONTACTS) {
            printf("Osiągnięto limit książki adresowej.\n");
            return;
        }

        //dodanie kontaktu
        strncpy(contacts[*size].number, number, sizeof(contacts[*size].number) - 1);
        contacts[*size].number[sizeof(contacts[*size].number) - 1] = '\0'; //upewnia sie ze konczy sie nullem
        strncpy(contacts[*size].surname, surname, sizeof(contacts[*size].surname) - 1);
        contacts[*size].surname[sizeof(contacts[*size].surname) - 1] = '\0'; //upewnia sie ze konczy sie nullem
        strncpy(contacts[*size].name, name, sizeof(contacts[*size].name) - 1);
        contacts[*size].name[sizeof(contacts[*size].name) - 1] = '\0'; //upewnia sie ze konczy sie nullem
        (*size)++; //zwieksza ilosc kontaktow
    }

    int main() {
        Contact contacts[MAX_CONTACTS];
        int current = 0;
        char option[5];
        //przykladowe kontakty
        addContact(contacts, &current, "123456789", "Jan", "Kowalski");
        addContact(contacts, &current, "893123111", "Tomasz", "Kwiatek");
        addContact(contacts, &current, "119099712", "Polak", "Rodak");
        addContact(contacts, &current, "377091712", "Adrian", "Palec");
        while (strcmp(option, "0") != 0) {
            printf("Opcje: \nwypisac wszystkie kontakty - 1,\nWyszukac kontakt po nazwisku - 2, "
                   "\nUsunac kontakt po nazwisku - 3, \nDodac kontakt - 4, \nkoniec - 0\n");
            scanf("%s", option);

            if (strcmp(option, "0") == 0) {
                printf("dziekuje za uzywanie programu");
            }
            else if (strcmp(option, "1") == 0) {
                searchAll(contacts, &current);
            }
            else if (strcmp(option, "2") == 0) {
                char sur [20];
                printf("Podaj nazwisko ktore wyszukac: ");
                scanf("%s", sur);
                searchSurname(contacts, &current, sur);
            }
            else if (strcmp(option, "3") == 0) {
                char sur [20];
                printf("Podaj nazwisko ktore chcesz usunac: ");
                scanf("%s", sur);
                deleteSurname(contacts, &current, sur);
            }
            else if (strcmp(option, "4") == 0) {
                char nam [20];
                char sur [20];
                char num [20];
                int a = 1;
                printf("Podaj Imie: ");
                scanf("%s", nam);
                printf("Podaj Nazwisko: ");
                scanf("%s", sur);
                while (a == 1) {
                    printf("Podaj Numer telefonu: ");
                    scanf("%s", num);
                    if (strlen(num) == 9) {
                        a = 0;
                        addContact(contacts,&current,num,nam,sur);
                    }
                    else{ printf("podano zly format numeru\n");}
                }

            }
            else{ printf("nie znaleziono funkcji\n");}
        }
        return 0;
}
