#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main() {
    char str[2001], lower[2001];
    char* result = str;
    int first = 1;
 
    scanf("%[^\n]",str);
 
    for (int i = 0; str[i]; i++) {
        lower[i] = tolower(str[i]);
    }
    lower[strlen(str)] = '\0';
     
    result = lower;
    while ((result = strstr(result, "cat")) != NULL)
    {
        if (!first) printf(", ");
        printf("%d",result - lower);
        first = 0;
        result++;
    }
 
    return 0;
}
