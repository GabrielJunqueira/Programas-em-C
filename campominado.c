#include <stdio.h>


int main (){

    int jogos;
    int tamanho;
	char tab[120][120];
	int matriz[120][120];
	int jogadas;
	int i;
	int n;
	int x;
	int y;
	int j;

	int linha;
	int coluna;


//todos os elementos da matriz são -100
    for (i=0; i < tamanho; i++){
	 for (j=0; j < tamanho; j++){
                matriz[i][j]== -100;

     }
	}

	//printf("Jogos:\n");
	scanf ("%d" , &jogos);

volta:
	//printf("\nTamanho:\n");
	scanf ("%d" , &tamanho);



// lendo o tabuleiro
	for (i=1; i < tamanho + 1; i++){
	 for (j=1; j < tamanho + 1; j++){

            scanf(" %c" , &tab[i][j]);
            getchar();

        }
	}

//elementos x passam a ser 1 e b passam a ser 15
    for (i=1; i < tamanho + 1; i++){
	 for (j=1; j < tamanho + 1; j++){

	 if (tab[i][j]=='x'){
        matriz[i][j] = 1;
	 }

     if (tab[i][j]=='b'){
        matriz[i][j] = 150;
     }

        }
	}

	/*for (i=1; i < tamanho + 1; i++){
	 for (j=1; j < tamanho + 1; j++){
            printf("%d\n" , matriz[i][j]);
     }
	}
*/




// lendo o numero de jogadas
	//printf("\nJogadas:\n");
	scanf ("%d" , &jogadas);


// lendo cada jogada x = linha, y = coluna
	for (n=1;n<=jogadas;n++){
        scanf("%d %d" , &x , &y);
        //a posicao escolhida eh multiplicada por 10
        matriz[x+1][y+1] = matriz[x+1][y+1]*10;
        //as posiçoes adjacentes crescem em 1
if (matriz[x+2][y+1] <150 && matriz[x+1][y+2] <150 && matriz[x][y+1] <150 &&  matriz[x+1][y] <150 && matriz[x+2][y+2] < 150 && matriz[x][y] < 150 && matriz[x+1][y+1] < 150){

            matriz[x+2][y+1]++;
            matriz[x+1][y+2]++;
            matriz[x][y+1]++;
            matriz[x+1][y]++;
            matriz[x+2][y+2]++;
            matriz[x][y]++;

}

       }
    /* for (i=1; i < tamanho + 1; i++){
	 for (j=1; j < tamanho + 1; j++){
            printf("%d\n" , matriz[i][j]);
     }
	}
*/

	/*printf("zz%d\n", matriz[0][0]);
	printf("zu%d\n", matriz[0][1]);
	printf("uz%d\n", matriz[1][0]);
	printf("uu%d\n", matriz[1][1]);
*/

    for (i=1; i < tamanho+1; i++){
	 for (j=1; j < tamanho+1; j++){

            if (matriz[i][j] >= 1500){
                printf("PERDEU\n");
                goto label;
            }
	 }
    }

    for (i=1; i < tamanho+1; i++){
	 for (j=1; j < tamanho+1; j++){

            if (matriz[i][j] == 1){
                printf("FALTOU TERMINAR\n");
                goto label;
            }
	 }
    }

	   for (i=1; i < tamanho+1; i++){
	 for (j=1; j < tamanho+1; j++){

            if (matriz[i][j] != 1  && matriz[x][y] <= 1500){
                printf("GANHOU\n");
                goto label;
            }
	 }


	 }








    label:
        jogos--;
        if (jogos > 0){
            goto volta;
        }
        else


    return 0;


	}