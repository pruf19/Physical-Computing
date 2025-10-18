#include <stdio.h>
#include <ctype.h>
#include <string.h>
 
int main(){
    char txt[450];
    int line = 0, word = 1, cha = 0;
 
    while (1){
        scanf(" %[^\n]",txt);
        if (strcmp(txt,".") == 0){
            break;
        }
        line++;
        word++;
        for (int i = 0; i < strlen(txt);i++){
            if (isspace(txt[i])){
                word++;
            }
            if (!isspace(txt[i])){
                cha++;
            }
        }
    }
     
    printf("Char = %d, word = %d, line = %d",cha,word-1,line);
    return 0;
}
