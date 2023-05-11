#include <stdio.h>

#define SIZE 6

void mellekatlo(int matrix[SIZE][SIZE]) {
    printf("A mellékátló elemei:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", matrix[i][SIZE - 1 - i]);
    }
    printf("\n");
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };

    mellekatlo(matrix);

    return 0;
}
