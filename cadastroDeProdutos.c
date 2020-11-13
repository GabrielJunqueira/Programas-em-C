#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAXCHAR 50

int main() {

	float somaTotal;
	float mediaTotal;
	char temp[50];

	struct itemProd {
		char nome[MAXCHAR];
		char marca[MAXCHAR];
		float preco;
	};

	struct marcaProd {
		char marca[MAXCHAR];
		float preco;
		int qnt;
		float media;
	};

	struct itemProd produtos[8];
	struct marcaProd teste[8];

	for (int i = 0; i < 8; i++) {
		teste[i].preco = 0;
		teste[i].qnt = 0;
	}

	for (int i = 0; i < 8; i++) {

		scanf("%s", &produtos[i].nome);
		scanf("%s", &produtos[i].marca);
		scanf("%f", &produtos[i].preco);

		somaTotal = produtos[i].preco + somaTotal;
	}

	for (int t = 0; t < 8; t++) {

		if (t == 0) {
			strcpy(temp, produtos[0].marca);
			for (int j = 0; j < 8; j++) {
				if (!strcmp(temp, produtos[j].marca)) {
					strcpy(teste[t].marca, temp);
					teste[t].preco = produtos[j].preco + teste[t].preco;
					teste[t].qnt++;
					teste[t].media = teste[t].preco / teste[t].qnt;

				}
			}
		} else {
			for (int y = 0; y < 8; y++) {
				strcpy(temp, produtos[t].marca);
				if (!strcmp(temp, teste[0].marca) || !strcmp(temp, teste[1].marca) || !strcmp(temp, teste[2].marca)
						|| !strcmp(temp, teste[3].marca) || !strcmp(temp, teste[4].marca)
						|| !strcmp(temp, teste[5].marca) || !strcmp(temp, teste[6].marca)
						|| !strcmp(temp, teste[7].marca)) {
					t++;
				}

				else {
					strcpy(temp, produtos[t].marca);
					for (int j = 0; j < 8; j++) {
						if (!strcmp(temp, produtos[j].marca)) {
							strcpy(teste[t].marca, temp);
							teste[t].preco = produtos[j].preco + teste[t].preco;
							teste[t].qnt++;
							teste[t].media = teste[t].preco / teste[t].qnt;

						}
					}
				}
			}
		}
	}

	mediaTotal = somaTotal / 8;

	for (int p = 0; p < 8; p++) {
		if (teste[p].qnt != 0)
			printf("%s %d\n", teste[p].marca, teste[p].qnt);
	}

	printf("media total %.2f\n", mediaTotal);

	for (int p = 0; p < 8; p++) {
		if (teste[p].qnt != 0)
			printf("media %s %.2f\n", teste[p].marca, teste[p].media);
	}

	return 0;
}
