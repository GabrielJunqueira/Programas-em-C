#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int fib(int t){
    int s;
    
    
    if (t == 1 || t == 2)
    s = 1;
    else{
        s = fib(t - 1) + fib (t - 2);
    }
   
   return s;
}

int main(){
    
    int t;
    scanf("%d" , &t);
  
    printf ("%d" , fib(t));
    
}
