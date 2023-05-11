#include <stdio.h>
#include <stdbool.h>

void alcatraz_szabadon_enged(int cellak_szama){
    bool cellak[cellak_szama];
    int i, j;

    for(i = 0; i < cellak_szama; i++){
        cellak[i] = false;
    }

    for(i = 1; i <= cellak_szama; i++){
        for(j = i; j <= cellak_szama; j += i){
            cellak[j - 1] = !cellak[j - 1];
        }
    }

    printf("Szabad cellák:\n");
    for(i = 0; i < cellak_szama; i++){
        if(cellak[i]){
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main(){
    int cellak_szama = 600;

    alcatraz_szabadon_enged(cellak_szama);

    return 0;
}
