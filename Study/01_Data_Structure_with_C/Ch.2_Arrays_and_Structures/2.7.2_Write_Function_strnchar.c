// Returns the number of occurrences of character 'p' in string 's'.

#include <string.h>

int strnchar(char* s, char p) {
    int count = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == p) {
            count++;
        }
    }
    return count;
}