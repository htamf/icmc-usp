//codigo que calcula a maior soma dos elementos
//entre as submatrizes possiveis;
//
//somente sera considerada as submatrizes cuja
//diagonal principal contenha somente elementos
//da diagonal principal da matriz original;

#include <stdio.h> 
int main() {

    //1. declarar variaveis
    int matriz[10][10], n, linha, coluna, soma, n_aux, maior_soma, diagonal_inicio, diagonal_maior_subm, n_aux_maior_subm; 

    //2. pedir n (dimensao da matriz n x n)
    scanf("%d", &n);

    //3. validar entrada
    if (n <= 0) {
        printf("Entrada invalida.");
        return 0;
    }
    
    //4. pedir valores para cada linha da MATRIZ ORIGINAL
    for (linha = 0; linha < n; linha++) {
        for (coluna = 0; coluna < n; coluna++) {
            scanf("%d", &matriz[linha][coluna]);
        }
    }


    //5. somando elementos das submatrizes e comparando
    maior_soma = 0;                                                                                 //inicializa varivel
    for (n_aux = 1; n_aux <= n; n_aux++) {                                                          //ordem da submatriz
        for (diagonal_inicio = 0; diagonal_inicio <= n-n_aux; diagonal_inicio++) {                  //determinando em qual diagonal comeca a submatriz
            soma = 0;
            for (linha = diagonal_inicio; linha < n_aux+diagonal_inicio; linha++) {                 //loop para somar os elementos da submatriz
                for (coluna = diagonal_inicio; coluna < n_aux+diagonal_inicio; coluna++) {
                    soma = soma + matriz[linha][coluna];
                }
            }
            if (soma > maior_soma) {                                                                //assim que soma os elementos, compara com oq esta guardado em maior_soma
                maior_soma = soma;
                diagonal_maior_subm = diagonal_inicio;                                              //e tambem guarda em que diagonal a maior 
                n_aux_maior_subm = n_aux;                                                           //submatriz comeca, e tb a sua ordem
            }

        }
    }

    //6. printa a maior soma
    printf("Soma: %d\n", maior_soma);

    //7. printa a maior submatriz
    for (linha = diagonal_maior_subm; linha < n_aux_maior_subm+diagonal_maior_subm; linha++) {
        for (coluna = diagonal_maior_subm; coluna < n_aux_maior_subm+diagonal_maior_subm; coluna++) {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }
    
    return 0;
}




