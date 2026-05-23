// Programa que calcula a probabilidade de se sortear uma bola
// da cor alvo em um surteio sem reposicao 

#include <stdio.h>
#include <stdlib.h>

// Calcula a probabilidade teorica de se sortear uma bola da cor alvo
float calcularProbabilidade (int bolasAlvo, int bolasTotal) {
    return ((float)bolasAlvo / bolasTotal) * 100;
}

// Simula o sorteio de bolas sem reposicao
int simularSorteio (int sorteiosTotal, int coresTotal, int bolasPorCor[], int indiceAlvo, int bolasTotal) {
    int bolaSorteada, limInf = 0, limSup = 0, indx, sorteouAlvo = 0;
    
    srand(42);

    // Define o intervalo da cor alvo no "vetor imaginario" que contem todas as bolas
    // O limite inferior vai ser determinado pela quantidade de bolas que vem antes da cor alvo
    // O limite superior vai ser pela quantidade de bolas que vem antes + quantidade da cor alvo
    for (indx = 0; indx < indiceAlvo; indx++) {
        limInf = limInf + bolasPorCor[indx];
    }
    limSup = limInf + bolasPorCor[indiceAlvo];

    indx = 1;               // Conta quantos sorteios aconteceram
    while (indx <= sorteiosTotal) {
        int aleatorio = rand();
        bolaSorteada = aleatorio % bolasTotal;

        if (bolaSorteada >= limInf && bolaSorteada < limSup) {
            sorteouAlvo++;
            // Como uma bola alvo foi retirada, o limite superior do 
            // intervalo dela diminui em 1 para o próximo sorteio.
            limSup--;
        }
        else if (bolaSorteada < limInf) {
            // Como a bola retirada veio ANTES da cor alvo, todo o intervalo
            // da cor alvo é deslocado uma posição para a esquerda.
            limInf--;
            limSup--;
        }
        // Reduz o total de bolas na urna (sorteio sem reposição)
        bolasTotal--;
        indx++;
    }

    return sorteouAlvo;
}

int main () {
    int coresTotal, indiceAlvo, i, bolasTotal, bolasAlvo, sorteiosTotal, valorEsperado, valorSimulado;
    float probabilidade, margemErro;

    scanf("%d", &coresTotal);

    int bolasPorCor[coresTotal];

    bolasTotal = 0;
    for (i = 0; i < coresTotal; i++) {
        scanf("%d", &bolasPorCor[i]);
        bolasTotal = bolasTotal + bolasPorCor[i];
    }

    scanf("%d", &indiceAlvo);

    bolasAlvo = bolasPorCor[indiceAlvo];

    probabilidade = calcularProbabilidade(bolasAlvo, bolasTotal);

    scanf("%d", &sorteiosTotal);

    valorEsperado = sorteiosTotal*(probabilidade/100);

    valorSimulado = simularSorteio(sorteiosTotal, coresTotal, bolasPorCor, indiceAlvo, bolasTotal);

    scanf("%f", &margemErro);

    printf("%.2f%%\nValor esperado: %d\nValor simulado: %d\n", probabilidade, valorEsperado, valorSimulado);

    if (abs(valorEsperado-valorSimulado) <= (int)(margemErro*bolasTotal)) {
        printf("Simulacao dentro da margem de erro\n");
    }
    else {
        printf("Simulacao fora da margem de erro\n");
    }

    return 0;
}