#include <stdio.h>
#include <string.h>


int main(){

    FILE *file;

    char nome[20];
    gets(nome);
    
    //scanf("%s" , nome);

    file = fopen(nome, "r");
    //file = fopen("C:\\Users\\gabri\\OneDrive\\Área de Trabalho\\UFMG\\fazer\\fisica\\laboratorio1.txt", "r");

    if (file == NULL)
    {
        printf("ERRO AO ABRIR\n");
    }

    long long int mat2[5][5];
    long long int mat3[5][5];
    long long int mat1[5][5];
    int i;
    int j;
    float x;
    


for (i = 0; i< 5; i++){
for (j = 0; j< 5; j++){

 fscanf(file, "%lld", &mat1[i][j]);

}
}

for (i = 0; i< 5; i++){
for (j = 0; j< 5; j++){

 fscanf(file, "%lld", &mat2[i][j]);

}
}


    for(i=0;i<5;i++){
    for (j=0;j<5;j++){
        mat3[i][j]= mat1[i][j] + mat2[i][j];
                printf("%lld ",mat3[i][j]);
            }
        }

fclose(file);


}
