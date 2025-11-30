#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int N;
    printf("Entrez une valeur N : ");
    scanf("%d", &N);

    bool estPremier[N + 1];

    // Initialisation : on suppose que tous sont premiers
    for (int i = 0; i <= N; i++) {
        estPremier[i] = true;
    }

    estPremier[0] = false;
    estPremier[1] = false;

    // Crible d’Ératosthène
    for (int i = 2; i <= sqrt(N); i++) {
        if (estPremier[i] == true) {
            for (int j = i * i; j <= N; j += i) {
                estPremier[j] = false;
            }
        }
    }

    // Affichage des nombres premiers
    printf("Nombres premiers jusqu'à %d :\n", N);
    for (int i = 2; i <= N; i++) {
        if (estPremier[i]) {
            printf("%d ", i);
        }
    }

    return 0;
}
