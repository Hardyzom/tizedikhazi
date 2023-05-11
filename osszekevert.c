#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void my_strfry(char* str) {
    size_t length = strlen(str);
    srand((unsigned int)time(NULL));
    
    for (size_t i = 0; i < length - 1; i++) {
        size_t j = i + rand() % (length - i);
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[] = "SziaaaAAaaAAAA UdvoZZoLEeeK!.";
    
    printf("Eredeti sztring: %s\n", str);
    
    my_strfry(str);
    
    printf("Összekevert sztring: %s\n", str);

    return 0;
}
