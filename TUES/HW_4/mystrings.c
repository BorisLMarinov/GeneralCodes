#include "mystrings.h"

void strlength(char str[], int *length) {
    *length = 0;
    while (str[*length] != '\0') {
        (*length)++;
    }
}

void strconcat(char str1[], char str2[]) {
    int i, j = 0;
    for(i = 0; str1[i] != '\0'; i++) {}
    
    while (str2[j] != '\0' && i < 50) {
        str1[i++] = str2[j++];
    }

    str1[i] = '\0';
}

int strcompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && i < 50) {
        if (str1[i] < str2[i]) {
            return -1;
        } else if (str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }

    if (i == 50) {
        return 0;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

