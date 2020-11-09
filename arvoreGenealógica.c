#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXCHARNOME 50

struct pessoa {
	char nome[MAXCHARNOME];
	int idade;
	int numFilhos;
	struct pessoa *filhos;
};

struct pessoa* buscaPessoa(struct pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel);
void freeTree(struct pessoa *pessoaAsc);

int main() {

	struct pessoa *patriarca, *pai;
	struct pessoa *atual;
	int nPessoas;
	int nConsultas;
	char buff[20];
	patriarca = (struct pessoa*) malloc(sizeof(struct pessoa));

	//numero de pessoas a serem cadastradas
	scanf("%d", &nPessoas);

	//lendo o ascendente mais velho
	scanf("%s", (char*) &patriarca->nome);
	scanf("%d", (int*) &patriarca->idade);
	scanf("%s", (char*) &buff);

	//ponteiro filhos começa apontando pra NULL
	patriarca->filhos = NULL;
	patriarca->numFilhos = 0;

	char nomePai[MAXCHARNOME];
	for (int i = 0; i < nPessoas - 1; i++) {
		//deve fazer malloc no começo sempre? free no final?
		atual = (struct pessoa*) malloc(sizeof(struct pessoa));
		atual->numFilhos = 0;
		atual->filhos = NULL;

		scanf("%s", (char*) &atual->nome);
		scanf("%d", (int*) &atual->idade);
		scanf("%s", (char*) &nomePai);

		//buscaPessoa retorna endereço para o qual *pai apontará
		pai = buscaPessoa(patriarca, nomePai, 0, 0);

		//Adiciona o "atual" na lista de filhos de "pai"
		//se o pai não tiver filhos, alocar espaço
		if (pai->filhos == NULL) {
			pai->filhos = (struct pessoa*) malloc(sizeof(struct pessoa));
			//se tiver, realocar esse espaço
		} else {
			pai->filhos = (struct pessoa*) realloc(pai->filhos, (pai->numFilhos + 1) * sizeof(struct pessoa));
		}
		//adiciona o filho no espaço
		(*pai).filhos[(*pai).numFilhos] = *atual;
		//*(pai->filhos + pai -> numFilhos) = *atual;
		//incrementa contador numero de filhos
		pai->numFilhos++;

	}

	struct pessoa *maisVelho;
	scanf("%d", &nConsultas);
	char velho[MAXCHARNOME];
	char novo[MAXCHARNOME];
	for (int i = 0; i < nConsultas; i++) {
		scanf("%s", novo);
		getchar();
		scanf("%s", velho);
		maisVelho = buscaPessoa(patriarca, velho, 0, 0);
		buscaPessoa(maisVelho, novo, 0, 1);

	}

	freeTree(patriarca);
	free(patriarca);
	return EXIT_SUCCESS;
}

void freeTree(struct pessoa *pessoaAsc) {
	//apenas prevenção para eventual futura manutencao
	if (pessoaAsc == NULL)
		return;
	else {
		for (int i = 0; i < pessoaAsc->numFilhos; i++) {
			freeTree((pessoaAsc->filhos + i));
		}
		if (pessoaAsc->numFilhos > 0)
			free(pessoaAsc->filhos);
	}
}

int contadorBuscaPessoa = 0;
struct pessoa* buscaPessoa(struct pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel) {

	contadorBuscaPessoa = nivel;

	//se nome igual
	if (!strcmp(pessoaAsc->nome, nomeProcurado)) {
		if (imprimeNivel == 1) {
			printf("%d\n", nivel);
		}
		return pessoaAsc;
	} else {
		for (int i = 0; i < pessoaAsc->numFilhos; i++) {
			struct pessoa *filho = buscaPessoa((pessoaAsc->filhos + i), nomeProcurado, contadorBuscaPessoa + 1,
					imprimeNivel);
			if (filho != NULL) {
				return filho;
			}
		}
		contadorBuscaPessoa--;
		return NULL;
	}
}
