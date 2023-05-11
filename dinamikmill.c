#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

typedef struct {
    int* data;
    int capacity;
    int count;
} DynArray;

int compare_numbers(const void* a, const void* b) {
    const int* number_a = (const int*)a;
    const int* number_b = (const int*)b;
    return *number_a - *number_b;
}

void da_init(DynArray* self) {
    self->data = NULL;
    self->capacity = 0;
    self->count = 0;
}

void da_insert(DynArray* self, int number) {
    if (self->count == self->capacity) {
        self->capacity = (self->capacity == 0) ? 1 : self->capacity * 2;
        int* new_data = (int*)realloc(self->data, self->capacity * sizeof(int));
        if (new_data == NULL) {
            printf("Hiba: Memoriafoglalas sikertelen.\n");
            free(self->data);
            exit(1);
        }
        self->data = new_data;
    }

    self->data[self->count] = number;
    self->count++;
}

void da_clear(DynArray* self) {
    free(self->data);
    self->data = NULL;
    self->capacity = 0;
    self->count = 0;
}

int main() {
    FILE* file = fopen("millions.txt", "r");
    if (file == NULL) {
        printf("Hiba: millions.txt fajl megnyitasa sikertelen.\n");
        return 1;
    }

    DynArray szamok;
    da_init(&szamok);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        int szam = atoi(line);
        da_insert(&szamok, szam);
    }

    fclose(file);

    qsort(szamok.data, szamok.count, sizeof(int), compare_numbers);

    printf("A rendezett szamok:\n");
    for (int i = 0; i < szamok.count; i++) {
        printf("%d\n", szamok.data[i]);
    }

    da_clear(&szamok);

    return 0;
}
