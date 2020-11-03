#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void funcReceber(int l , int c, int **p){
    
    	for (int i = 0; i < l; i++){
	    for (int j = 0; j < c; j++){
	scanf("%d", &p[i][j]);
	}
	}
    	
}


int main(){


	int **p;
	int l;
	int c;
	
	// recebe o numero de linhas e de colunas 
	scanf("%d" , &l);
    scanf("%d" , &c);
	
	//aloca a matriz 
	p = (int **) malloc(sizeof(int*)*l);
	
	for (int i = 0; i < l; i++){
		p[i] = (int *)malloc(sizeof(int)*c);
	}
	
		funcReceber(l , c, p);
	
	for (int i = 0; i < l; i++){
    	   	for (int j = 0; j < c; j++){
	    printf("%d\n", p[i][j]);
	}
    	}
	

	
	free(p);

}
