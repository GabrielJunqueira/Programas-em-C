#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

char str1 [40];
char str2 [40];

gets(str1);
gets(str2);


strcat(str1,str2);
printf("%s",str1);
}

