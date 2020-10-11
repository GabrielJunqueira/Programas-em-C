#include <stdio.h>
#include <string.h>


int main(){

    char nome[20];
    gets(nome);
    FILE *arq= fopen(nome, "rb");
   
    //arq = fopen("C:\\Users\\gabri\\OneDrive\\Área de Trabalho\\UFMG\\pdslabb\\laboratorio1.txt" , "r");

    char str;
    char *result;




    unsigned long int  i;
    unsigned long int t = 0;

    if (arq == NULL){
        printf("Nao pode ser aberto");
        return 0;
    }

    for (i=0 ; i<= 20000000; i++){
        str = fgetc(arq);
        if (str == 'a'){
            t++;
        }

    }
    printf("%lu" , t);


    /*for(i = 0;i <= strlen(str); i++){
       if (str[i] == 'a'){
        t++;
       }
    }

    printf("%d", t);

*/

    return 0;


}
