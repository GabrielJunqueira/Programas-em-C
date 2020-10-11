#include <stdio.h>
#include <string.h>

struct dados{
    unsigned int idade;
    float salario;
    char nome[10];
};

int a = 0;
int b = 0;
int vvvv = 0;

char operacao[15] = "\0";
char quem[10] = "\0";
char inserir[8] = "inserir";
char mostrar[8] = "mostrar";
char sair[2] = "\0";
char lot[50] = "\0";
int x = 0;
struct dados p[10];

int main(){

    do{
        fgets(operacao, 15, stdin);
        if (!(strcmp (operacao, "inserir ")))
        operacao[strlen(operacao) - 2] = '\0';

        else{
        operacao[strlen(operacao) - 1] = '\0';
        }



        if (strcmp(operacao, inserir) == 0){
            if (a > 3){

                fgets(lot, 50, stdin);
                lot[strlen(lot) - 1] = '\0';
                printf("Espaco insuficiente\n");

            }

            if (a <= 3){

                scanf("%s", p[a].nome);
                scanf("%u", &p[a].idade);
                scanf("%f", &p[a].salario);
                getchar();
                printf("Registro %s %u %.2f inserido\n", p[a].nome, p[a].idade, (float)p[a].salario);
                a++;
            }
        }

        else{

            if (!(strcmp(operacao, mostrar))){

                setbuf(stdin, NULL);
                fgets(quem, 10, stdin);
                quem[strlen(quem)-1] = '\0';

                for (b = 0; b <= 3; b++){
                    if ((strcmp(quem, p[b].nome)) == 0){

                        printf("Registro %s %d %.2f\n", p[b].nome, p[b].idade, p[b].salario);
                        vvvv = 1;
                        break;
                    }
                }
                if (vvvv == 0){
                    printf("Registro ausente\n");
                }


                vvvv = 0;
            }
        }


//x++;

    }
while ((strcmp(operacao, mostrar) == 0) || (strcmp(operacao, inserir) == 0));

}
