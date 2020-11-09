#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

int i;
char str1 [10];
char str2 [10];

gets(str1);


for (i = 10; i >= 0; i--){
    printf("%c" , str1[i]);
}


}

