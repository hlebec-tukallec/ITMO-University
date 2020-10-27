#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct person {
    char *surname;
    char *name;
    char *fathername;
    int64_t number;
} person;

void swap (person *a, person *b) {
    person tmp = *a;
    *a = *b;
    *b = tmp;
}

int less(person *a, person *b) {
    return strcmp((*a).surname, (*b).surname) < 0 ||
           strcmp((*a).surname, (*b).surname) == 0 && strcmp((*a).name, (*b).name) < 0 ||
           strcmp((*a).surname, (*b).surname) == 0 && strcmp((*a).name, (*b).name) == 0 &&
           strcmp((*a).fathername, (*b).fathername) < 0 ||
           strcmp((*a).surname, (*b).surname) == 0 && strcmp((*a).name, (*b).name) == 0 &&
           strcmp((*a).fathername, (*b).fathername) == 0 && (*a).number < (*b).number;
}


int part (person *list, int l, int r) {
    int tmp = l - 1;
    for (int i = l; i < r; i++) {
        if (less(&list[i], &list[r])) {
            tmp++;
            swap(&list[tmp], &list[i]);
        }
    }
    swap(&list[tmp + 1], &list[r]);
    return tmp + 1;
}

void quicksort (person *list, int l, int r) {
    if (r - l < 0) {
        exit(0);
    }
    int stack[r - l + 1];
    int top = 0;
    stack[top] = l;
    stack[++top] = r;
    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];
        int h;
        h = part(list, l, r);

        if (h + 1 < r) {
            stack[++top] = h + 1;
            stack[++top] = r;
        }
        if (h - 1 > l) {
            stack[++top] = l;
            stack[++top] = h - 1;
        }
    }
}

int main(int argc, char **argv) {
    //input.txt  output.txt

    if (argc < 3) {
        printf("Wrong arguments! Try again.");
        return 1;
    }

    FILE *r;
    if ((r = fopen(argv[1], "r")) == NULL) {

        printf("Can't open the input file");
        return 2;
    }

    FILE *w;
    if((w = fopen(argv[2], "w")) == NULL) {

        printf("Can't open the output file");
        return 3;
    }

    person *list;
    char surname[20];
    char name[20];
    char fathername[20];
    int64_t number;
    int k = 0;

    if (!(list = (person*)malloc(sizeof(person)))) {
        printf("Allocation error");
        return 4;
    }

    while(fscanf(r, "%s %s %s %lu", surname, name, fathername, &number) != EOF){
        k = k + 1;
        if (k > 1) {
            if(!(list = (person *) realloc(list,k * sizeof(person)))){
                printf("Allocation error");
                return 4;
            }
        }

        if(!(list[k - 1].surname = (char*) malloc((strlen(surname) + 1) * sizeof(char)))) {
            printf("Allocation error");
            return 4;
        }
        strcpy(list[k - 1].surname, surname);

        if(!(list[k - 1].name = (char*)malloc((strlen(name) + 1) * sizeof(char)))) {
            printf("Allocation error");
            return 4;
        }
        strcpy(list[k - 1].name, name);

        if(!(list[k - 1].fathername = (char*)malloc((strlen(fathername) + 1) * sizeof(char)))) {
            printf("Allocation error");
            return 4;
        }
        strcpy(list[k - 1].fathername, fathername);

        list[k - 1].number = number;
    }

    if (fclose(r) == EOF) {
        printf("Can't close the input file");
        return 6;
    }

    quicksort(list, 0, k - 1);


    for (long int i = 0; i < k; i++) {
        fprintf(w, "%s %s %s %lu\n", list[i].surname, list[i].name, list[i].fathername, list[i].number);
    }
    if (fclose(w) == EOF) {
        printf("Can't close the output file");
        return 6;
    }

    for (long int i = 0; i < k; i++) {
        free(list[i].surname);
        free(list[i].name);
        free(list[i].fathername);
    }
    free(list);

    return 0;
}
