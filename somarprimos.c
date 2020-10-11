#include <stdio.h>
#include <string.h>
#include <math.h>



int Primo(int numero){

    int i;
    int r;

    int naoprimo = 0;

    for (i=2; i <= sqrt(numero); i++){
        if (numero % i == 0){
            naoprimo = 1;
        }
    }

    return (naoprimo);
}

int SPrimo(int numero){

int k = 2;
unsigned long long int contador = 0;
unsigned long long int soma = 0;

for (k = 2; contador <= numero - 1; k++){
    if (Primo(k)== 0){
        contador++;
        soma = soma + k;
        //printf("%d\n" , k);
    }

}

return (soma);
}




int main(){
int a;

while (scanf("%d" , &a) != EOF){
    printf("%llu\n" , SPrimo(a));
}

}


