#include <stdio.h>

void hatoslottó_számok(int osszeg, int szorzat){
    int szamok[45];
    int i, j, k, l, m, n;

    for(i = 1; i <= 45; i++){
        szamok[i - 1] = i;
    }

    for(i = 0; i < 40; i++){
        for(j = i + 1; j < 41; j++){
            for(k = j + 1; k < 42; k++){
                for(l = k + 1; l < 43; l++){
                    for(m = l + 1; m < 44; m++){
                        for(n = m + 1; n < 45; n++){
                            if(szamok[i] + szamok[j] + szamok[k] + szamok[l] + szamok[m] + szamok[n] == osszeg && szamok[i] * szamok[j] * szamok[k] * szamok[l] * szamok[m] * szamok[n] == szorzat){
                                printf("A számok: %d, %d, %d, %d, %d, %d\n", szamok[i], szamok[j], szamok[k], szamok[l], szamok[m], szamok[n]);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int osszeg = 90;
    int szorzat = 996300;

    hatoslottó_számok(osszeg, szorzat);

    return 0;
}
