#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char age[3];
    char major[4];
} Student;

int compare(const void* a, const void* b) {
    return strcmp(((Student*)a)->name, ((Student*)b)->name);
}

void printPTIStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        if (strcasecmp(students[i].major, "PTI") == 0) {
            char capitalized[MAX_NAME_LENGTH];
            strcpy(capitalized, students[i].name);
            capitalized[0] = toupper(capitalized[0]);
            printf("%s, ", capitalized);
        }
    }
    printf("\n");
}

int main() {
    FILE* file = fopen("nevek.csv", "r");
    if (file == NULL) {
        fprintf(stderr, "Hiba a fájl megnyitásakor.\n");
        return 1;
    }
    
    Student students[100];
    int numStudents = 0;
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char* name = strtok(line, ",");
        char* age = strtok(NULL, ",");
        char* major = strtok(NULL, ",");
        
        if (name != NULL && age != NULL && major != NULL) {
            strcpy(students[numStudents].name, name);
            strcpy(students[numStudents].age, age);
            strcpy(students[numStudents].major, major);
            numStudents++;
        }
    }
    
    fclose(file);
    
    qsort(students, numStudents, sizeof(Student), compare);
    
    printPTIStudents(students, numStudents);
    
    return 0;
}
