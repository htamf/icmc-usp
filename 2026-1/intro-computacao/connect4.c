//SIMULADOR DE PARTIDA DE *CONNECT FOUR* ENTRE DUAS PESSOAS

#include <stdio.h>
int main () {

    //1. definir variavel Struct
    struct Jogador {
        char nome[50];
        char peca;
    };

    //2. definir variaveis
    struct Jogador p1;
    struct Jogador p2;
    int jogada, i, j, ganhou, colocou_peca, rodada, espacos_sobrando, cont;
    char tabuleiro[6][7], peca_atual;

    //3. ler dados dos jogadores
    scanf("%s", p1.nome);           //nome do player1
    scanf(" %c", &p1.peca);         //caractere que representa player1
    scanf("%s", p2.nome);           //nome do player2
    scanf(" %c", &p2.peca);         //caractere que representa player2

    //4. verificar se os dados sao validos
    if (p1.peca == '0' || p2.peca == '0') {
        printf("Entrada invalida.");
        return 0;
    }

    //5. inicializa o tabuleiro
     for (i = 0; i <= 5; i++) {
         for (j = 0; j <= 6; j++) {
            tabuleiro[i][j] = '0';
         }
     }


    //6. inciar jogo
    rodada = 0;
    espacos_sobrando = 42;
    ganhou = 0;
    while (espacos_sobrando > 0 && ganhou == 0) {
        //6.1. jogador faz sua jogada
        scanf("%d", &jogada);
        //6.2. verifica se jogada eh valida
        if (jogada < 1 || jogada > 7) {
            printf("Entrada invalida.");
            return 0;
        }
        //6.3. coloca a peca do jogador no tabuleiro
        else { 
            colocou_peca = 0;
            for (i=5; i>=0; i--) {              //comeca de baixo para cima para preencher a posicao mais baixa na coluna
                if (tabuleiro[i][jogada - 1] == '0' && colocou_peca == 0) {
                    rodada++;                  
                    if (rodada % 2 != 0) {      //confere qual jogador esta jogando para saber a peca que vai colocar na coluna
                        tabuleiro[i][jogada-1] = p1.peca;
                        colocou_peca = 1;
                        peca_atual = p1.peca;
                    }
                    else {
                        tabuleiro[i][jogada-1] = p2.peca;
                        colocou_peca = 1;
                        peca_atual = p2.peca;

                    }
                }
            }
            //6.4. verifica se conseguiu colocar a peca
            if (colocou_peca == 0) {            //se passou por todas as linhas da coluna da jogada e nao conseguiu
                printf("Entrada invalida.");    //colocar a peca: significa que tentou colocar em uma coluna cheia
                return 0;
            }
            else {
                espacos_sobrando = espacos_sobrando - 1;    //se conseguiu colocar a peca, diminui os espacos sobrando
            }
            //6.5. verifica se o jogador ganhou
            i=0;
            //6.5.1. percorre todo o tabuleiro ate encontrar uma peca do jogador que acabou de jogar
            while (i<=5 && ganhou == 0) {       
                j=0;
                while (j<=6 && ganhou == 0) {
                    if (tabuleiro[i][j] == peca_atual) {
                        cont = 1;
                        //6.5.2. procura ao redor da peca encontrada para ver se tem outra peca do mesmo jogador
                        //caso i. procura na diagonal1: para baixo e para a direita
                        while (ganhou == 0 && i+cont <= 5 && j+cont <= 6 && tabuleiro[i+cont][j+cont] == peca_atual) {       
                            cont++;
                            if (cont == 4) {
                                ganhou = 1;
                            }
                        }
                        //caso ii. procura na diagonal2: para baixo e para a esquerda
                        cont = 1;
                        while (ganhou == 0 && i+cont <= 5 && j-cont >=0 && tabuleiro[i+cont][j-cont] == peca_atual) {
                            cont++;
                            if (cont == 4) {
                                ganhou = 1;
                            }
                        }
                        //caso iii. procura na linha
                        cont = 1;
                        while (ganhou == 0 && i <= 5 && j+cont <= 6 && tabuleiro[i][j+cont] == peca_atual) {
                            cont++;
                            if (cont == 4) {
                                ganhou = 1;
                            }
                        }
                        //caso iv. procura na coluna
                        cont = 1;
                        while (ganhou == 0 && i+cont <= 5 && j <= 6 && tabuleiro[i+cont][j] == peca_atual) {
                            cont++;
                            if (cont == 4) {
                                ganhou = 1;
                            }
                        }
                    }
                    j++;
                }
                i++;
            }
        }

    }

    //7. mostra o tabuleiro
     for (i = 0; i <= 5; i++) {
         for (j = 0; j <= 6; j++) {
             printf ("%c ", tabuleiro[i][j]);
         }
         printf("\n");
     }
     //8. anuncia o vencedor (caso exista) ou o empate
     if (ganhou == 1) {
        if (peca_atual == p1.peca) {
        printf("%s ganhou!", p1.nome);
        }
        else {
            printf("%s ganhou!", p2.nome);
        }
     }
     else {
        printf("Empate!");
     }
    

    return 0;
}