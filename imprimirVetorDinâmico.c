#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void funcRecebe(int n , int *p){
    for (int i = 0; i < n; i++){
		scanf("%d", &p[i]);
	}
}


int main(){


	int *p;
	int n;
	
	scanf("%d" , &n);
	
	p = (int *) malloc(n * sizeof(int));
	
	funcRecebe(n , p);
	
	for (int i = 0; i < n; i++){
	    printf("%d\n", p[i]);
	}
	
	free(p);

}
