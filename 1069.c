#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 int diamante(char *str){
     int i=0, j=0, total=0;
     int verifica=0;
     for(i; i<strlen(str); i++){
        if(str[i] == '<'){
            verifica+=1;
        }
        if(str[i] == '>' && verifica>0){
            verifica-=1;
            total++;
             }
        }
    
        printf("%d\n", total);
        
        return 0;
 }
 
int main() {
    char *string = (char *) malloc(1000 * sizeof(char));
    int i=0, n=0;
    scanf("%d", &n);
    getchar();
    for(i=0; i<n; i++){
        fgets(string, 1000, stdin);
        diamante(string);
    }
   
    return 0;
}
