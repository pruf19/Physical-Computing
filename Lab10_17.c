#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Weather {
    char outlook[9];
    int temperature;
    int humidity;
    char wind; //wind{T,F}
} Weather;
 
void playing_decision(Weather *w){
    if (strcmp(w->outlook, "overcast") == 0) {
        printf("yes\n");
    }
    else if (strcmp(w->outlook, "rain") == 0) {
        if (w->wind == 'F') {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    else if(strcmp(w->outlook,"sunny") == 0){
        if(w->humidity > 77.5){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
    }
    else{
        printf("no\n");   
    }
}
 
int main(){
    int num;
    scanf("%d",&num);
 
    for(int i = 0; i < num; i++){
        Weather *w = (Weather*) malloc(sizeof(Weather));
        scanf("%s %d %d %c", w->outlook, &w->temperature, &w->humidity, &w->wind);
        playing_decision(w);
        free(w);
    }
 
    return 0;
}
