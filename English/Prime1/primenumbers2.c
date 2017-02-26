#include <stdio.h>
#include <math.h>

/* http://www.spoj.com/problems/PRIME1/ */

int is_prime(long int x);

int main() {
	
	long int i,j; //acumuladores
	
	int t;
	
	long int m, n;

	scanf("%d", &t);
	
	for (i=1; i<=t;i++){

		scanf ("%ld %ld", &m, &n);
		
		/* Processamento */
		
		if ( (m%2) == 0 ) {
			m++;
		}

		for (j=m; j<=n ;j+=2){
			
			if (is_prime(j))
				printf("%ld\n", j);
				
		}
		
		/* Processamento */
		
		printf("\n");
		
	}

		
	return 0;
}

/* dont send even numbers to this function */
int is_prime(long int x) {
	int i, sqrtx;
	/*if ( (x%2) == 0 ) {
		return 0;
	}*/
	sqrtx = sqrt(x);
	for (i=3; i<= sqrtx; i=i+2) {
		if ( (x%i) == 0)
			return 0;
	}
	return 1;
}

