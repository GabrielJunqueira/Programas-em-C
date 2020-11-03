#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int soma(int vetor[] , int t){
    int s;
    if (t == 1)
    s = vetor[0];
    else{
        s = vetor[t-1] + soma(vetor , t-1);
    }
   
   return s;
}

int main(){
    
    int t;
    scanf("%d" , &t);
    int v[t];
    
    for (int i = 0; i < t; i++){
        scanf("%d" , &v[i]);
    }
    
    printf ("%d" , soma(v, t));
    
}
