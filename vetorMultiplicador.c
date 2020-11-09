#include <stdio.h>

void imprime (int vetor[], int n){
    int i;

    for (i=0;i<n;i++){
        printf("%d " , vetor[i]);
    }

}


void multiplica (int vetor[], int n, double v){
    int i;

    for (i=0;i<n;i++){
         vetor[i] = vetor[i] * v; 
    }

   

}

int main(){
int a;
int i;
double m;

 

scanf("%d", &a);

int vet[10000];

for (i=0;i<a;i++){
    scanf("%d", &vet[i]);
}

imprime(vet, a);


scanf("%lf", &m);

double n = 1/m;


multiplica(vet, a, m);

imprime(vet, a);

multiplica(vet, a, n);

imprime(vet, a);




}

