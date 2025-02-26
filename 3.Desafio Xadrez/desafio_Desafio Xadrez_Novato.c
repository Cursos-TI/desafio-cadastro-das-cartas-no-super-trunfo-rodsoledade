#include <stdio.h>

int main() {
    // Declaração de variáveis para o número de casas
    const int TORRE_MOV = 5;    // Movimentos da Torre
    const int BISPO_MOV = 5;    // Movimentos do Bispo
    const int RAINHA_MOV = 8;   // Movimentos da Rainha
    
    // Variáveis contadoras
    int i;  // Para o for da Torre
    int j;  // Para o while do Bispo
    int k;  // Para o do-while da Rainha

    // Simulação do movimento da Torre (usando for)
    printf("Movimento da Torre:\n");
    for (i = 1; i <= TORRE_MOV; i++) {
        printf("Direita\n");    // Torre se move para a direita
    }
    printf("\n");  // Linha em branco para separação

    // Simulação do movimento do Bispo (usando while)
    printf("Movimento do Bispo:\n");
    j = 0;
    while (j < BISPO_MOV) {
        printf("Cima, Direita\n");  // Bispo se move na diagonal
        j++;
    }
    printf("\n");  // Linha em branco para separação

    // Simulação do movimento da Rainha (usando do-while)
    printf("Movimento da Rainha:\n");
    k = 0;
    do {
        printf("Esquerda\n");   // Rainha se move para a esquerda
        k++;
    } while (k < RAINHA_MOV);

    return 0;
}