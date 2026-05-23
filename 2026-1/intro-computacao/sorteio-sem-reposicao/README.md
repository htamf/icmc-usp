# Simulação de um sorteio sem reposição
**Programa que calcula a probabilidade de se sortear uma bola da cor alvo em um sorteio sem reposição**

## Sobre o problema
O objetivo do programa é calcular a probabilidade teórica de se sortear uma bola de uma cor específica (alvo) de dentro de uma urna que contém bolas de $n$ cores diferentes. 

Além do cálculo matemático exato, o programa realiza uma **simulação de $k$ sorteios sem reposição**, valida a quantidade de acertos e verifica se o resultado prático ficou dentro de uma margem de erro $E$ estipulada em relação ao valor esperado.

## Minha estrutura lógica
Para simular o sorteio sem reposição sem precisar criar um vetor contendo fisicamente cada bolinha, eu adotei uma abordagem matemática de **janelas/intervalos dinâmicos** dentro de um "vetor imaginário".

1. **Definição dos Limites:** Com base no índice da cor alvo, o programa calcula quantas bolas existem antes dela (`limInf`) e o limite onde a cor termina (`limSup`).
2. **Ajuste Pós-Sorteio (Sem Reposição):** A cada rodada do loop, uma bola é retirada (`bolasTotal--`). Para manter a integridade dos sorteios seguintes:
   * Se a bola sorteada for da cor alvo, o `limSup` diminui.
   * Se a bola sorteada for de uma cor que veio antes da alvo, tanto o `limInf` quanto o `limSup` diminuem para empurrar todo o intervalo da cor alvo uma posição para trás.

## Sobre o programa
Simulador desenvolvido em **C** como projeto da disciplina de Introdução à Programação de Computadores — ICMC/USP. O programa recebe a quantidade de cores, o total de bolas de cada tipo, a cor desejada, o número de sorteios e a margem de erro via entrada padrão, <br>
realiza o cálculo da chance teórica, executa uma simulação estatística sem reposição e ao final valida se o resultado prático ficou dentro do esperado.

## Formato de entrada 1
