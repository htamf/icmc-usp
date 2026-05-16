# Connect Four
**Programa que simula uma partida do jogo *Connect Four* entre duas pessoas**

## Sobre o jogo
*Connect Four* é um jogo de tabuleiro para dois jogadores, disputado em uma grade vertical de 6 linhas por 7 colunas. 
O objetivo é ser o primeiro a alinhar quatro peças de um mesmo jogador na horizontal, vertical ou diagonal. Os jogadores 
se alternam, colocando uma peça por vez em qualquer coluna não cheia, e a peça ocupa sempre a posição mais baixa disponível 
nessa coluna. O jogo termina quando um dos jogadores forma uma sequência de quatro peças (com a vitória deste jogador) ou 
quando o tabuleiro fica completamente preenchido, resultando em empate.

## Sobre o programa
Simulador desenvolvido em **C** como projeto da disciplina de Introdução à Computação — ICMC/USP. O programa recebe os dados dos 
dois jogadores e as jogadas via entrada padrão, valida cada jogada e ao final exibe o tabuleiro e anuncia o vencedor (ou empate).

## Formato de entrada
```
Joao
*
Maria
+
1 2
2 3
6 3
3 4
5 4
6 4
4 1
```
## Formato de saída
```
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 * 0 0 0
0 0 * + 0 0 0
0 * + + 0 * 0
* + + + * * 0
Joao ganhou !
```
