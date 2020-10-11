#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void funcao (double vet[], int n, int *ponteiro){

  int a;

  double soma = 0;
  double media = 0;


  double atual;
  int f;



//descobre a media dos numeros do vetor
  for (a = 0; a < n; a++){
      soma = soma + vet[a];
      media = soma / n;
  }

//atual começa sendo a posicao 0 - media
  atual = abs(vet[0] - media);


    for (a = 0; a < n; a++){

      if ((abs(vet[a] - media)) < atual){

          atual = abs(vet[a] - media);
          f = a;
          *ponteiro = a;
      }
  }

}


int main(){

    int tamanho;
    int i = 0;
    double vet[1000];
    int l;



    scanf("%d" , &tamanho);


   for (i = 0; i < tamanho; i++){
        scanf("%lf", &vet[i]);
    }



    funcao(vet,tamanho,&l);
    printf("%d", l);

}
