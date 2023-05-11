#include <stdio.h>
#include <ctype.h>

int strcmpi(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        int diff = tolower(*str1) - tolower(*str2);
        if (diff != 0) {
            return diff;
        }
        str1++;
        str2++;
    }
    return tolower(*str1) - tolower(*str2);
}

int main() {
    const char* str1 = "ez";
    const char* str2 = "EZ";
    int kulonbseg = strcmpi(str1, str2);
    printf("Eredmény: %d\n", kulonbseg);

    return 0;
}
