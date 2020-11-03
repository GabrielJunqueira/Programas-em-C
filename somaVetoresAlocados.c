#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void funcSoma(int n , int *p, int *q, int *s){
    for (int i = 0; i < n; i++){
		s[i] = p[i] + q[i]; 
	}
}


int main(){


	int *p;
	int *q;
	int *s;
	
	int n;
	
	scanf("%d" , &n);
	
	p = (int *) malloc(n * sizeof(int));
	q = (int *) malloc(n * sizeof(int));
	s = (int *) malloc(n * sizeof(int));
	
	
	for (int i = 0; i < n; i++){
	    scanf("%d", &p[i]);
	}
	
	for (int i = 0; i < n; i++){
	    scanf("%d", &q[i]);
	}
	
	funcSoma(n, p, q, s);
	
	for (int i = 0; i < n; i++){
	    printf("%d\n", s[i]);
	}
	
	
	free(p);
	free(q);
	free(s);

}
    
