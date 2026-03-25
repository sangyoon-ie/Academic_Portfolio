#include <stdio.h>
#include <string.h>

/*
 * Refactoring pmatch() from a 'while' loop to a 'for' loop.
 * Original logic:
 * while (i < lens && j < lenp) {
 * if (string[i] == pat[j]) { i++; j++; }
 * else if (j == 0) i++;
 * else j = failure[j-1] + 1; }
 */

int pmatch(char* string, char* pat, int* failure) {
    int i, j = 0;
    int lens = strlen(string);
    int lenp = strlen(pat);

  // Increment is handled inside the loop to maintain KMP logic
    for (i = 0; i < lens && j < lenp; ) {
        if (string[i] == pat[j]) {
            i++;
            j++;
        }
        else if (j == 0) {
            i++;
        }
        else {
            j = failure[j - 1] + 1;
        }
    }
    return (j == lenp ? i - lenp : -1);
}