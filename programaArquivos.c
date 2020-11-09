#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXCHAR 50
#define MAXCHARNOME 50
#define MAXCHARDEP 30
#define DATADELIM "/"
#define MAXDAY 50
#define MAXMONTH 50
#define MAXYEAR 5000

struct tipoData {
	int dia;
	int mes;
	int ano;
};

struct itemFunc {
	char nome[MAXCHARNOME];
	double salario;
	struct tipoData dataEntrada;
	char departamento[MAXCHARDEP];
};
//funções antes do main para evitar warnings
void imprimeFuncsArq(struct itemFunc *funcLst, int nFunc, char *fileName);
void imprimeFunc(struct itemFunc funcionario);
int maisNovo(struct tipoData data1, struct tipoData data2);
void imprimeDep(struct itemFunc * funcLst, int nFunc, char *nomeDepartamento);
void imprimeFuncMaisVelhoDep(struct itemFunc * funcLst, int nFunc, char *nomeDepartamento);
void imprimeMediaSalDep(struct itemFunc * funcLst, int nFunc, char *nomeDepartamento);
void imprimeData(struct tipoData data, FILE *outFile);

char *strolPtr;

int main(int argc, char *argv[]) {

	//para o caso de algum parametro não ser passado
	FILE *inFile;
	if (argc < 2)
		return EXIT_SUCCESS;

	inFile = fopen(argv[1], "r");
	if (inFile) {
		char buff[MAXCHAR];
		//numero de funcionarios começa como 0
		long nFunc = 0;
		//media salarial começa como 0
		double mediaSal = 0;

		//le numero de funcionarios
		if (fgets(buff, MAXCHAR, inFile) != NULL) {
			//converte a string lida em numero
			nFunc = strtol(buff, &strolPtr, 10);

			struct itemFunc funcLst[nFunc];
			struct itemFunc funcMaisVelho;
			funcMaisVelho.dataEntrada.dia = MAXDAY;
			funcMaisVelho.dataEntrada.mes = MAXMONTH;
			funcMaisVelho.dataEntrada.ano = MAXYEAR;

			//le dados de cada funcionario
			for (int i = 0; i < nFunc; i++) {

				//le o nome fonte: https://www.programiz.com/c-programming/examples/read-file
				fscanf(inFile, "%[^\n]\n", funcLst[i].nome);

				//le o salario - buff usado devido à quebra de linha e conversão para double
				fgets(buff, MAXCHAR, inFile);
				funcLst[i].salario = atof(buff);

				//le a data
				fgets(buff, MAXCHAR, inFile);

				// função strtok para separar as barras da data
				char *day = strtok(buff, DATADELIM);
				char *mes = strtok(NULL, DATADELIM);
				char *ano = strtok(NULL, DATADELIM);

				//convertendo as datas para int para comparacao
				funcLst[i].dataEntrada.dia = strtol(day, &strolPtr, 10);
				funcLst[i].dataEntrada.mes = strtol(mes, &strolPtr, 10);
				funcLst[i].dataEntrada.ano = strtol(ano, &strolPtr, 10);

				//le o departamento
				fscanf(inFile, "%[^\n]\n", funcLst[i].departamento);

				//calcula a media salarial geral
				mediaSal += funcLst[i].salario / nFunc;
				
				//descobre se o funcionario lido é mais velho que o atual mais velho
				if (maisNovo(funcMaisVelho.dataEntrada, funcLst[i].dataEntrada))
					funcMaisVelho = funcLst[i];

			    //insert sort: adiciona os funcionarios em ordem alfabetica
				for (int j = i; j > 0; j--) {
					struct itemFunc tempFunc;
					if (strcmp(funcLst[j].nome, funcLst[j - 1].nome) < 0) {
						tempFunc = funcLst[j - 1];
						funcLst[j - 1] = funcLst[j];
						funcLst[j] = tempFunc;
					} else
						break;
				}
			}

			//para o caso de menos parametros
			if (argc < 3)
				return EXIT_SUCCESS;

			
			switch (strtol(argv[2], &strolPtr, 10)) {
			case 1:
				imprimeFuncsArq(funcLst, nFunc, argv[3]);
				break;
			case 2:
				imprimeDep(funcLst, nFunc, argv[3]);
				break;
			case 3:
				imprimeFunc(funcMaisVelho);
				break;
			case 4:
				imprimeFuncMaisVelhoDep(funcLst, nFunc, argv[3]);
				break;
			case 5:
				printf("%.2lf\n", mediaSal);
				break;
			case 6:
				imprimeMediaSalDep(funcLst, nFunc, argv[3]);
				break;
			}

		}
		fclose(inFile);
	}

	return EXIT_SUCCESS;
}

//imprime os funcionarios, ja em ordem, no arquivo output
void imprimeFuncsArq(struct itemFunc *funcLst, int nFunc, char *fileName) {
	FILE *outFile;
	outFile = fopen(fileName, "w");
	if (outFile) {
		for (int i = 0; i < nFunc; i++) {
			fprintf(outFile, "%s\n", funcLst[i].nome);
			fprintf(outFile, "%.2lf\n", funcLst[i].salario);
			imprimeData(funcLst[i].dataEntrada, outFile);
			fprintf(outFile, "%s\n", funcLst[i].departamento);
		}
		fclose(outFile);
	}
}

//função para imprimir dados na tela
void imprimeFunc(struct itemFunc funcionario) {
	printf("%s\n", funcionario.nome);
	printf("%.2lf\n", funcionario.salario);
	imprimeData(funcionario.dataEntrada, NULL);
	printf("%s\n", funcionario.departamento);
}

//função para descobrir qual o mais velho
int maisNovo(struct tipoData data1, struct tipoData data2) {
	//data1 -> mais velho ate agora
	//data2 -> func a ser comparado
	// retorna 1 -> comparado passa a ser o mais velho

	if (data1.ano < data2.ano)
		return 0;

	if (data1.ano > data2.ano)
		return 1;

	if (data1.ano == data2.ano){
		if (data1.mes < data2.mes)
			return 0;
		if (data1.mes > data2.mes)
			return 1;
		if (data1.mes == data2.mes){
			if (data1.dia < data2.dia)
				return 0;
			if (data1.dia > data2.dia)
				return 1;
			}
}
		return 1;

}

//imprime os dados dos funcionarios do departamento passado
void imprimeDep(struct itemFunc * funcLst, int nFunc, char *nomeDepartamento) {
	for (int i = 0; i < nFunc; i++) {
		if (!strcmp(funcLst[i].departamento, nomeDepartamento)) {
			imprimeFunc(funcLst[i]);
		}
	}
	return;
}

//acha o mais velho do departamento passado e imprime
void imprimeFuncMaisVelhoDep(struct itemFunc *funcLst, int nFunc, char *nomeDepartamento) {

	struct itemFunc funcMaisVelhoDep;
	funcMaisVelhoDep.dataEntrada.dia = MAXDAY;
	funcMaisVelhoDep.dataEntrada.mes = MAXMONTH;
	funcMaisVelhoDep.dataEntrada.ano = MAXYEAR;
	for (int i = 0; i < nFunc; i++) {
		if (!strcmp(funcLst[i].departamento, nomeDepartamento)) {
			if (maisNovo(funcMaisVelhoDep.dataEntrada, funcLst[i].dataEntrada))
				funcMaisVelhoDep = funcLst[i];
		}
	}
	imprimeFunc(funcMaisVelhoDep);
}

//acha media salarial de todos que são do departamento
void imprimeMediaSalDep(struct itemFunc *funcLst, int nFunc, char *nomeDepartamento) {
	double somaSalDep = 0;
	int nFuncDep = 0;

	for (int i = 0; i < nFunc; i++) {
		if (!strcmp(funcLst[i].departamento, nomeDepartamento)) {
			somaSalDep += funcLst[i].salario;
			nFuncDep++;
		}
	}
	if (nFuncDep != 0)
		printf("%.2lf\n", somaSalDep / nFuncDep);
	else
		printf("0.00\n");
}

//função para imprimir data quando é preciso - por causa da barra
void imprimeData(struct tipoData data, FILE *outFile) {
	if (outFile) {
		fprintf(outFile, "%02d%s%02d%s%04d\n", data.dia, DATADELIM, data.mes,
		DATADELIM, data.ano);
	} else {
		printf("%02d%s%02d%s%04d\n", data.dia, DATADELIM, data.mes, DATADELIM, data.ano);
	}
}
