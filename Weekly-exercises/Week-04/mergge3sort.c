#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int vet[], int ini, int meio1, int meio2, int fim) {
    int temp[fim - ini + 1];
    int i = ini, j = meio1 + 1, k = meio2 + 1, p = 0;

    while (i <= meio1 && j <= meio2 && k <= fim) {
        if (vet[i] <= vet[j] && vet[i] <= vet[k])
            temp[p++] = vet[i++];
        else if (vet[j] <= vet[i] && vet[j] <= vet[k])
            temp[p++] = vet[j++];
        else
            temp[p++] = vet[k++];
    }

    while (i <= meio1 && j <= meio2)
        temp[p++] = (vet[i] <= vet[j]) ? vet[i++] : vet[j++];

    while (i <= meio1 && k <= fim)
        temp[p++] = (vet[i] <= vet[k]) ? vet[i++] : vet[k++];

    while (j <= meio2 && k <= fim)
        temp[p++] = (vet[j] <= vet[k]) ? vet[j++] : vet[k++];

    while (i <= meio1)
        temp[p++] = vet[i++];

    while (j <= meio2)
        temp[p++] = vet[j++];

    while (k <= fim)
        temp[p++] = vet[k++];

    for (i = ini, p = 0; i <= fim; i++, p++)
        vet[i] = temp[p];
}

void merge_sort3(int vet[], int ini, int fim) {
    if (ini < fim) {
        int tamanho = (fim - ini + 1);
        int um_terco = ini + tamanho / 3;
        int dois_tercos = ini + (2 * tamanho) / 3;

        merge_sort3(vet, ini, um_terco);
        merge_sort3(vet, um_terco + 1, dois_tercos);
        merge_sort3(vet, dois_tercos + 1, fim);

        merge(vet, ini, um_terco, dois_tercos, fim);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* vetor = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
    merge_sort3(vetor, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
    free(vetor);
    return 0;
}
