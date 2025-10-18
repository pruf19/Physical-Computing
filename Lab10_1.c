#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    char str[2001];
    int i, j = 0;
 
    scanf("%[^\n]", str);
 
    for (i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
            printf("%c",str[i]);
        }
    }
    return 0;
}
