#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXCHAR 50

struct Student {
    unsigned id;
    float notaPromovare;
    char *nume;
    struct Student *next;
};

struct Student* insertStud(struct Student* head);
void bubbleSort(struct Student* head);
void swapData(struct Student *a, struct Student *b);
void printStud(struct Student* head);

int main() {
    struct Student *ptrHead = NULL;
    char ans = 'd';
    while(ans == 'd') {
        ptrHead = insertStud(ptrHead);
        printf("Introduceti inca un student?(d/n) : ");
        scanf(" %c", &ans);
    }
    //bubbleSort(ptrHead);
    printStud(ptrHead);
    if(ptrHead!=NULL)
        free(ptrHead);
    return 0;
}

struct Student* insertStud(struct Student* head) {
    if(head==NULL) {
        struct Student *curr;
        curr = (struct Student*)malloc(sizeof(struct Student));
        printf("ID : "); unsigned id; scanf("%u", &id);
        curr->id = id;
        printf("Nume : "); char *nume = (char*)malloc(MAXCHAR*sizeof(char)); scanf("%s", nume);
        curr->nume = (char*)malloc(MAXCHAR*sizeof(char)); strcpy(curr->nume, nume);
        printf("Nota Promovare : "); float notaPromovare; scanf("%f", &notaPromovare);
        curr->notaPromovare = notaPromovare;
        curr->next = NULL;
        head = curr;
    } else {
        struct Student *newInp = (struct Student*)malloc(sizeof(struct Student));
        printf("ID : "); unsigned id; scanf("%u", &id);
        newInp->id = id;
        printf("Nume : "); char *nume = (char*)malloc(MAXCHAR*sizeof(char)); scanf("%s", nume);
        newInp->nume = (char*)malloc(MAXCHAR*sizeof(char)); strcpy(newInp->nume, nume);
        printf("Nota Promovare : "); float notaPromovare; scanf("%f", &notaPromovare);
        newInp->notaPromovare = notaPromovare;
        newInp->next = head;
        head = newInp;
    }
    return head;
}

void bubbleSort(struct Student* head) {
    bool swapped;
    struct Student *curr, *prev=NULL;
    if(head==NULL)
        return;
    do {
        swapped = false;
        curr = head;
        while(curr->next != prev) {
            if(curr->notaPromovare < curr->next->notaPromovare) {
                swapData(curr, curr->next);
                swapped = true;
            }
            curr = curr->next;
        }
        prev = curr;
    } while(swapped);
}

void swapData(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

void printStud(struct Student* head) {
    struct Student *i = head;
    system("cls");
    if(i==NULL)
        return;
    printf("\n\n\tID\tNota Promovare\t\tNume\n");
    while(i!=NULL) {
        printf("\t%u\t%.2f\t\t\t%s\n", i->id, i->notaPromovare, i->nume);
        i = i->next;
    }
}
