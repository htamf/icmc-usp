// programa que simula uma corrida

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void mostraPista(int totalCorredores, int tamanhoPista, int posicaoCorredor[]) {
    int i, j;
    clock_t agora, limite;

    // limpar a tela
    agora = clock();
    limite = agora + 0.2*CLOCKS_PER_SEC;
    while (limite > agora) {
        agora = clock();
    }

    system("clear");

    // mostra a pista (cada linha) com os corredores
    for (i = 0; i < totalCorredores; i++) {
        for (j = 0; j < posicaoCorredor[i]; j++) {
            printf("_");
        }

        printf("%c", 'A'+i);

        for (j = posicaoCorredor[i]+1; j < tamanhoPista; j++) {
            printf("_");
        }

        printf("|\n");
    }
    printf("\n*******************\n");
    return ;
}

// verificar se alguem ganhou, devolve 0 se ninguem chegou no final e 1 caso contrario
int alguemGanhou (int totalCorredores, int tamanhoPista, int posicaoCorredor[]) {
    int i;
    for (i = 0; i < totalCorredores; i++) {
        if (posicaoCorredor[i] == tamanhoPista - 1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int totalCorredores, tamanhoPista, posicaoCorredor[100], i, j, indexVencedor;

    srand(time(NULL));

    printf("Digite o numero de corredores e o tamanho da pista:");
    scanf("%d %d", &totalCorredores, &tamanhoPista);

    // validacao da entrada
    while (totalCorredores < 2 || totalCorredores > 100 || tamanhoPista < 2 || tamanhoPista > 100) {
        printf("Entrada invalida. Tente novamente:\nDigite o numero de corredores e o tamanho da pista: ");
        scanf("%d %d", &totalCorredores, &tamanhoPista);
    }

    // inicializando corredores no inicio da pista
    // a pista vai de 0 ate tamanhoPista - 1
    for (i = 0; i < totalCorredores; i++) {
        posicaoCorredor[i] = 0;
    }

    mostraPista(totalCorredores, tamanhoPista, posicaoCorredor);

    // rodadas: para cada jogador vai ser somado 0 ou 1 a posicao atual dele, indicando se este jogador avanca ou nao
    while (alguemGanhou(totalCorredores, tamanhoPista, posicaoCorredor) == 0) {

        for (i = 0; i < totalCorredores; i++) {
            posicaoCorredor[i] = posicaoCorredor[i] + (rand() % 2);
        }

        mostraPista(totalCorredores, tamanhoPista, posicaoCorredor);
    }

    // encontrar vencedor
    indexVencedor = -1;
    for (i = 0; i < totalCorredores; i++) {
        if (posicaoCorredor[i] == tamanhoPista-1) {
            indexVencedor = i;
        }
    }

    if (indexVencedor != -1) {
        printf("Vencedor: %c\n\n", 'A'+indexVencedor);
    }
    return 0;
}