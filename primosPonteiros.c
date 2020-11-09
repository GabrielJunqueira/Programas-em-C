#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void funcao(int n, int *p1, int *p2){

    int i,j;
    int prox;
    int ant;

    // acha o prox primo
    for(i=n+1;;i++){

        for(j=2;j<i;j++){
            if(i%j==0)
                break;
        }

        if(j==i)
        {
            prox = i;
            *p2 = prox;
            break;
        }
    }

    //acha o primo anterior
    for(i=n-1;;i--){

        for(j=2;j<i;j++){
            if(i%j==0)
                break;
        }

        if(j==i){
            ant = i;
            *p1 = ant;
            break;
        }
    }

}

int main(){

int n;
int p1;
int p2;

scanf("%d", &n);

funcao(n,&p1,&p2);

printf("%d\n", p1);
printf("%d", p2);




}
