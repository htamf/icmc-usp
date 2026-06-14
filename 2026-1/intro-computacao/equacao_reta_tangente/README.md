# Cálculo de Equações de Retas Tangentes
## Descrição

Dado um polinômio `f` de coeficientes reais e um ponto `t`, o programa:
- Armazena `f` e `f'` em vetores alocados dinamicamente
- Imprime `f` e `f'`
- Calcula e imprime a equação da reta tangente ao gráfico de `f` no ponto `(t, f(t))`

A reta tangente é dada por:
```
y - f(t) = f'(t)(x - t)
```

## Entrada

```
t n
a_n a_(n-1) ... a_0
```

- `t`: ponto real onde a reta tangente é calculada
- `n`: grau do polinômio (inteiro ≥ 0)
- `a_n ... a_0`: coeficientes do polinômio, do maior ao menor grau

## Saída

Imprime `f(x)`, `f'(x)` e a equação da reta tangente.  
Se `n < 0` ou o coeficiente de maior grau for zero, imprime `Entrada invalida.`

## Exemplos

**Entrada:**
```
0 3
9 0 1 1
```
**Saída:**
```
f(x) = (9)x^3 + (1)x^1 + (1)x^0
f'(x) = (27)x^2 + (1)x^0
y - (1) = 1(x - (0))
```
## Implementação

- `leFuncao`: lê e imprime o polinômio
- `calculaDerivada`: calcula e imprime a derivada
- `resultadoFuncao`: avalia `f(t)`
- `resultadoDerivada`: avalia `f'(t)`
- `retaTangente`: imprime a equação da reta tangente
