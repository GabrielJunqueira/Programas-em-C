#include <stdio.h>
#include <string.h>



int bissexto(int ano){

    int teste = 0;

    if (ano % 400 == 0){
        teste = 1;

    }
    if (ano % 4 == 0){
        teste = 1;
    }
    if (ano % 100 == 0 && ano % 400 != 0){
        teste = 0;
    }

    return(teste);

}




int main(){
int a;

while (scanf("%d" , &a) != EOF){
    printf("%d\n" , bissexto(a));
}

}



