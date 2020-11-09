#include <stdio.h>
#include <string.h>
#include <math.h>


int primo(int numero){
int i;
int k = 1;

for (i = 2; i<= numero/2; i++){
    if (numero%i == 0){
        k = 0;
        break;
    }
    else {
        k =1;
    }
}

if (numero < 2){
    k = -1;
}

if (numero >= 1000000009){
    k =1;
}
return (k);
}


int main(){

    int a;

    while((scanf("%d", &a) != EOF))
        printf("%d\n" , primo(a));

}


