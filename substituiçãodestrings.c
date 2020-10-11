#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

int i;
char str [30];
char um;
char enter;
char dois;



gets(str);
um = getchar();
enter = getchar();
dois = getchar();


for (i=0;i<=30;i++){
    if (str[i] == um){
        str[i] = dois;
        break;
    }
}

printf("%s" , str);

}

