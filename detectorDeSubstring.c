#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


int main(){

int i;
int j;
char str [20];
char str2 [10];
int a = 0;

gets(str);
gets(str2);


for (i=0;i<=20;i++){
    for(j=0;j<=10;j++){

        if (str[i]==str2[j] && str[i+1]==str2[j+1] && str[i+2]==str2[j+2]){
            printf("É substring");
            i = 14;
            a = 1;
            break;
        }
        else {
            break;
        }

        }

    }

    if (a != 1){
        printf("Não é substring");
    }

   }


