#include <stdio.h>
#include <math.h>

/* http://www.spoj.com/problems/PRIME1/ */

int is_prime_batch(long int x, int array_primes[], int n_first_sqrt_primes);
int is_prime(long int x);
void generate_primes(int array_primes[]);

void generate_primes_2(int array_primes[]);
int is_prime_2(long int x);


int main() {
	
	long int i,j; //acumuladores
	int t;
	long int m, n;
	long int n1, n2;
	long int k;

	int array_primes[3400];
	int n_first_sqrt_primes = 3399;
	
	generate_primes_2(array_primes);
	

	scanf("%d", &t);
	
	for (i=1; i<=t;i++){

		scanf ("%ld %ld", &m, &n);
		
		/* Processamento */
		
		/* se for um m pequeno, processar separadamente */
		if (m <= 3) {
			for (j=m; j<=3; j++) {
				printf("%ld\n", j);
				m++;
			}
		}
		
		/*encontra primeiro k */
		k = m + (6 - m%6);
		if (k==m+6) { k = m; }
		
		//printf("Parte 1\n");
		//printf("%ld é o k\n", k);
		
		/*verifica se os k anteriores eram
		 * primos e se eles faziam parte do array */
		if ( ((k-1) >= m) ) {
			if (is_prime_batch(k-1, array_primes, n_first_sqrt_primes))
				printf("%ld\n", k-1);
		}
		
		if ( ((k-5) >= m) ) {
			if (is_prime_batch(k-5, array_primes, n_first_sqrt_primes))
				printf("%ld\n", k-5);
		}
		
		//printf("Parte 2\n");
		
		for (k=k; k<=n-6; k+=6) {
			n1 = k + 1;
			n2 = k + 5;
			if (is_prime_batch(n1, array_primes, n_first_sqrt_primes)) {
				printf("%ld\n", n1);
			}
			if (is_prime_batch(n2, array_primes, n_first_sqrt_primes)) {
				printf("%ld\n", n2);
			}
		}
		
		if ( ((k+1) <= n) ) {
			if (is_prime_batch(k+1, array_primes, n_first_sqrt_primes))
				printf("%ld\n", k+1);
		}
		
		if ( ((k+5) <= n) ) {
			if (is_prime_batch(k+1, array_primes, n_first_sqrt_primes))
				printf("%ld\n", k+5);
		}
		
		
		/*verifica se o resto é primo */
		/*for (j=m; j<=n ;j+=2){
			
			if (is_prime_batch(j, array_primes, n_first_sqrt_primes))
				printf("%ld\n", j);
				
		}*/
		
		/* Processamento */
		
		printf("\n");
		
	}

		
	return 0;
}

int is_prime_batch(long int x, int array_primes[], int n_first_sqrt_primes){
	int i;
	if (x < 31623) {
		//sim este código é feio
		for (i=0; i<= n_first_sqrt_primes; i++) {
			if (array_primes[i] >= x) {
				return 1;
			}
			if ( (x%array_primes[i]) == 0) {
				return 0;
			}
		}	
	} else {
		for (i=0; i<= n_first_sqrt_primes; i++) {
			if ( (x%array_primes[i]) == 0) {
				return 0;
			}
		}
	}
	return 1;
}

/* dont send even numbers to this function */
int is_prime(long int x) {
	int i, sqrtx;
	sqrtx = sqrt(x);
	for (i=3; i<= sqrtx; i=i+2) {
		if ( (x%i) == 0)
			return 0;
	}
	return 1;
}

/* primes from 3 to sqrt(1 000 000 000) = */
void generate_primes(int array_primes[]){
	int i,counter,sqrtx = 0;
	sqrtx = 31623; /* sqrt(1 000 000 000) */
	for (i=3; i<= sqrtx; i=i+2) {
		if (is_prime(i)) {
			array_primes[counter] = i;
			counter++;
		}
	}
	/*printf("%d\n", counter);*/
}

void generate_primes_2(int array_primes[]){
	int i = 0;
	int counter = 2;
	int sqrtx = 31623;  /*sqrt(1 000 000 000) */
	
	int n1, n2;

	array_primes[0] = 3;
	array_primes[1] = 5;
	
	for (i=6; i <= sqrtx; i+=6) {
		n1 = i + 1;
		n2 = i + 5;
		if (is_prime_2(n1)) {
			array_primes[counter] = n1;
			//printf("%d\n", n1);
			counter++;
		}
		if (is_prime_2(n2)) {
			array_primes[counter] = n2;
			//printf("%d\n", n2);
			counter++;
		}
	}
	//printf("%d\n", counter);
}


/* não envie primos x <= 5 */
int is_prime_2(long int x) {
	
	int n1, n2;
	
	if (x%2 == 0) {
		return 0;
	} else if (x%3 == 0){
		return 0;	
	} else if (x%5 == 0){
		return 0;
	} else {
		
		int i, sqrtx;
		sqrtx = sqrt(x);
		
		for (i=6; i<= sqrtx; i+=6) {
			n1 = i + 1;
			n2 = i + 5;
			if ( (x%n1) == 0)
				return 0;
			if ( (x%n2) == 0)
				return 0;		
		}
		
		return 1;
	
	}
	
}
