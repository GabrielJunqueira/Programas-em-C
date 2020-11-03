#include <stdio.h>

vezes(char *p, char r){
    int n = 0;
    for(int i = 0; i < strlen(p); i++){
       if (p[i] == r)
       n++;
    }
    
    printf("%d" , n);
    
}
    
    
int main(){
    char palavra[40];
    char letra;
    
    scanf("%s" , palavra);
    getchar();
    scanf ("%c" , &letra);
    
    vezes(palavra , letra);
    
 
    
    
}
