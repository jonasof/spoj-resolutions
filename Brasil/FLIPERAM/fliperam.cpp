#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int sorteio (const void * a, const void * b)
{
     return ( *(int*)b - *(int*)a );
}

int main(){

    int n_partidas;
    int n_exibir;

    cin >> n_partidas >> n_exibir;

    long int partidas[n_partidas];

    for (int i=0; i < n_partidas; i++)
    {
        cin >> partidas[i];
    }

    qsort(partidas, n_partidas, sizeof(int), sorteio);

    for (int i=0; i < n_exibir; i++)
    {
        cout << partidas[i] << endl;
    }

	return 0;
}
